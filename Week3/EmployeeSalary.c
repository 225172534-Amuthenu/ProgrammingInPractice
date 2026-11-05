#include <stdio.h>
int main() {
    float basicSalary;
    float housing;
    float transport;
    float tax;
    float grossSalary;
    float netSalary;

    printf("Enter basic salary: ");
    scanf("%f", &basicSalary);
    
    printf("Enter housing: ");
    scanf("%f", &housing);

    printf("Enter transport: ");
    scanf("%f", &transport);

    printf("Enter tax: ");
    scanf("%f", &tax);

    grossSalary = basicSalary + housing + transport;
    netSalary = grossSalary - tax;

    printf("\nGross Salary: %.2f\n", grossSalary);
    printf("\nNet Salary: %.2f\n", netSalary);

    return 0;
}   
  