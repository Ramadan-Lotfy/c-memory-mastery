#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* ---------- Function under test ---------- */

bool append_integer(int **numbers, size_t *length, int value) {
    if (numbers == NULL || length == NULL) {
        return false;
    }

    if (*length > 0 && *numbers == NULL) {
        return false;
    }

    if (*length == SIZE_MAX) {
        return false;
    }
    size_t new_length = *length + 1;

    if (new_length > SIZE_MAX / sizeof(int)) {
        return false;
    }

    int *temp = realloc(*numbers, new_length * sizeof(int));
    if (temp == NULL) {
        return false;
    }

    *numbers = temp;
    (*numbers)[*length] = value;
    *length = new_length;

    return true;
}

/* ---------- Tiny test helper ---------- */

static int failures = 0;

#define CHECK(cond, name)                      \
    do {                                       \
        if (cond) {                            \
            printf("PASS: %s\n", (name));      \
        } else {                               \
            printf("FAIL: %s\n", (name));      \
            failures++;                        \
        }                                      \
    } while (0)

/* ---------- Tests ---------- */

static void test_append_to_empty(void) {
    int *numbers = NULL;
    size_t length = 0;

    bool ok = append_integer(&numbers, &length, 10);

    CHECK(ok, "append to empty array succeeds");
    CHECK(length == 1, "length is 1 after first append");
    CHECK(numbers != NULL && numbers[0] == 10, "first element is 10");

    free(numbers);
}

static void test_append_three(void) {
    int *numbers = NULL;
    size_t length = 0;

    bool ok1 = append_integer(&numbers, &length, 10);
    bool ok2 = ok1 && append_integer(&numbers, &length, 20);
    bool ok3 = ok2 && append_integer(&numbers, &length, 30);

    CHECK(ok1 && ok2 && ok3, "append three integers succeeds");
    CHECK(length == 3, "length is 3 after three appends");
    CHECK(numbers != NULL && numbers[0] == 10 && numbers[1] == 20 && numbers[2] == 30,
          "elements are 10, 20, 30");

    /* Expected output: 10 / 20 / 30, one per line */
    for (size_t i = 0; i < length; i++) {
        printf("%d\n", numbers[i]);
    }

    free(numbers);
}

static void test_append_negative(void) {
    int *numbers = NULL;
    size_t length = 0;

    bool ok = append_integer(&numbers, &length, -42);

    CHECK(ok, "append negative integer succeeds");
    CHECK(length == 1, "length is 1 after negative append");
    CHECK(numbers != NULL && numbers[0] == -42, "stored value is -42");

    free(numbers);
}

static void test_null_numbers(void) {
    size_t length = 0;

    bool ok = append_integer(NULL, &length, 1);

    CHECK(!ok, "numbers == NULL fails");
    CHECK(length == 0, "length unchanged when numbers == NULL");
}

static void test_null_length(void) {
    int *numbers = NULL;

    bool ok = append_integer(&numbers, NULL, 1);

    CHECK(!ok, "length == NULL fails");
    CHECK(numbers == NULL, "buffer unchanged when length == NULL");
}

static void test_nonzero_length_null_buffer(void) {
    int *numbers = NULL;
    size_t length = 3; /* claims 3 elements, but there is no buffer */

    bool ok = append_integer(&numbers, &length, 1);

    CHECK(!ok, "nonzero length with NULL buffer fails");
    CHECK(length == 3, "length unchanged on failure");
    CHECK(numbers == NULL, "buffer still NULL on failure");
}

/* ---------- Main ---------- */

int main(void) {
    test_append_to_empty();
    test_append_three();
    test_append_negative();
    test_null_numbers();
    test_null_length();
    test_nonzero_length_null_buffer();

    if (failures == 0) {
        printf("\nAll tests passed.\n");
        return 0;
    }

    printf("\n%d check(s) failed.\n", failures);
    return 1;
}