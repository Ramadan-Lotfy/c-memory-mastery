
#include <stdio.h>


void increase(int *number) {
    *number = *number + 1;
}

int main(void) {
    int age = 25;

    // Store the address of age
    int *ptr = &age;

    printf("Variable value: %d\n", age);
    printf("Variable address: %p\n", (void *)&age);

    printf("\nPointer value: %p\n", (void *)ptr);
    printf("Value through pointer: %d\n", *ptr);

    // Modify age through the pointer
    *ptr = 30;

    printf("\nAfter modifying through pointer:\n");
    printf("age = %d\n", age);
    printf("*ptr = %d\n", *ptr);

    int value = 10;

    increase(&value);

    printf("%d\n", value); 



    return 0;
}
