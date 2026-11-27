#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>



int main(void) {
    int number = 0;

    printf("enter the number of prices: ");
    if (scanf("%d", &number) != 1 || number <= 0) {
        printf("invalid number\n");
        return 1;
    }

    float *prices = malloc(number * sizeof(float));
    if (prices == NULL) {
        printf("memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < number; i++) {
        printf("enter price #%d: ", i + 1);
        if (scanf("%f", &prices[i]) != 1) {
            printf("invalid price\n");
            free(prices);
            return 1;
        }
    }

    int newNumber = 0;
    printf("enter the number of prices: ");
    scanf("%d", &newNumber);

    float *temp = realloc(prices, newNumber * sizeof(float));

    if (temp == NULL) {
        printf("could not reallocat memory\n");
    }
     else{
        prices = temp;
        temp = NULL;
        
        for (int i = number; i < newNumber; i++) {
        printf("enter price #%d: ", i + 1);
        scanf("%f", &prices[i]);
        }

        for (int i = 0; i < newNumber; i++) {
        printf("$%.2f ", prices[i]);
    }

    }

    printf("\n");

    free(prices);
    prices = NULL;

    return 0;
}

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

    if (new_length > SIZE_MAX / sizeof **numbers) {
        return false;
    }

    int *temp = realloc(*numbers, new_length * sizeof **numbers);

    if (temp == NULL) {
        return false;
    }

    *numbers = temp;
    (*numbers)[*length] = value;
    *length = new_length;

    return true;
}