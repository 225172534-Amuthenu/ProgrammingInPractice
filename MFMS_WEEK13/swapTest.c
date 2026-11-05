#include <stdio.h>

/* Correct version: using pointers */
void swapSalaries(double *a, double *b)
{
    double temp = *a;

    *a = *b;
    *b = temp;
}

/* Wrong version: using normal parameters */
void wrongSwap(double a, double b)
{
    double temp = a;

    a = b;
    b = temp;
}

int main(void)
{
    double salary1 = 15000;
    double salary2 = 20000;

    printf("BEFORE WRONG SWAP\n");
    printf("Salary 1: %.2f\n", salary1);
    printf("Salary 2: %.2f\n", salary2);

    wrongSwap(salary1, salary2);

    printf("\nAFTER WRONG SWAP\n");
    printf("Salary 1: %.2f\n", salary1);
    printf("Salary 2: %.2f\n", salary2);

    swapSalaries(&salary1, &salary2);

    printf("\nAFTER CORRECT SWAP\n");
    printf("Salary 1: %.2f\n", salary1);
    printf("Salary 2: %.2f\n", salary2);

    return 0;
}