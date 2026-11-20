
#include <stdio.h>

void increase(int *number) {
    *number += 1;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void redirect(int **ptr, int *target) {
    *ptr = target;
}

int main(void) {
    int value = 10;

    printf("Before increase: %d\n", value);

    increase(&value);

    printf("After increase: %d\n", value);

    int x = 10;
    int y = 20;

    printf("\nBefore swap: x=%d, y=%d\n", x, y);

    swap(&x, &y);

    printf("After swap: x=%d, y=%d\n", x, y);

    int first = 10;
    int second = 100;

    int *p = &first;

    redirect(&p, &second);

    printf("%d\n", *p);


    return 0;
}
