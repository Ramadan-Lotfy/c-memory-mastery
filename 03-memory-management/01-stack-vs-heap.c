#include <stdio.h>
#include <stdlib.h>


void example(void) {
    int x = 10;
    int *ptr = malloc(sizeof *ptr);
    *ptr = 20;

    free(ptr);
}

int *create_number(void) {
    int *number = malloc(sizeof *number);

    if (number == NULL) {
        return NULL;
    }

    *number = 100;

    return number;
}

int main(void) {
    int *a = malloc(sizeof *a);
    int b = 50;

    if (a == NULL) {
        return 1;
    }

    *a = 100;

    printf("%d\n", *a);
    printf("%d\n", b);

    free(a);
    return 0;
}