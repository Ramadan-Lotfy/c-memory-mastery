
#include <stdio.h>

int main(void) {
    int age = 25;
    float height = 1.80f;
    char grade = 'A';

    printf("Age: %d\n", age);
    printf("Height: %.2f\n", height);
    printf("Grade: %c\n", grade);

    printf("\nMemory addresses:\n");
    printf("age: %p\n", (void *)&age);
    printf("height: %p\n", (void *)&height);
    printf("grade: %p\n", (void *)&grade);

    printf("\nMemory sizes:\n");
    printf("int: %zu bytes\n", sizeof(age));
    printf("float: %zu bytes\n", sizeof(height));
    printf("char: %zu bytes\n", sizeof(grade));

    return 0;
}
