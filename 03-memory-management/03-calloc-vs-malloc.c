#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *numbers = calloc(5, sizeof *numbers);

    if (numbers == NULL) {
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        printf("%d\n", numbers[i]);
    }

    free(numbers);
    return 0;
}