#include <stdlib.h>

int main(void) {
    int *numbers = malloc(3 * sizeof *numbers);

    if (numbers == NULL) {
        return 1;
    }

    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;
    numbers[3] = 40;

    free(numbers);

    return 0;
}