#include <stdio.h>
#include <stdlib.h>



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
