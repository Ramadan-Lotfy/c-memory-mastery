#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



bool create_integer(int **ptr, int value) {
    if (ptr == NULL) {
        return false;
    }

    int *p = malloc(sizeof *p);

    if (p == NULL) {
        return false;
    }

    *p = value;
    *ptr = p;

    return true;
}

void update(int ***ptr) {
    if (ptr == NULL || *ptr == NULL || **ptr == NULL) {
        return;
    }

    ***ptr = 999;
}

int main(void) {
    int number = 10;

    int *ptr = &number;

    int **pptr = &ptr;

    printf("number = %d\n", number);
    printf("*ptr = %d\n", *ptr);
    printf("**pptr = %d\n", **pptr);

    printf("\nAddresses:\n");
    printf("&number = %p\n", (void *)&number);
    printf("ptr     = %p\n", (void *)ptr);
    printf("&ptr    = %p\n", (void *)&ptr);
    printf("pptr    = %p\n", (void *)pptr);

    **pptr = 50;

    printf("\nAfter modifying through **pptr:\n");
    printf("number = %d\n", number);


    return 0;
}
