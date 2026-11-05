#include <stdio.h>

int main(void)
{
    int number = 10;

    int *p = &number;

    printf("Original value: %d\n", number);

    printf("Address: %p\n", (void *)&number);

    printf("Value through pointer: %d\n", *p);

    *p = 25;

    printf("\nAfter changing through pointer:\n");

    printf("New value: %d\n", number);

    printf("New pointer value: %d\n", *p);

    return 0;
}