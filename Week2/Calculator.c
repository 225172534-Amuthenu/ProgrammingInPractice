#include <stdio.h>

int main() {

    double revenue;
    double expenses;
    double balance;

    int departments;
    double payroll;
    double procurement;
    double assets;

    printf("========================================\n");
    printf("       MUNICIPAL BUDGET CALCULATOR\n");
    printf("========================================\n\n");

    // Enter revenue and expenses
    printf("Enter Total Revenue: ");
    scanf("%lf", &revenue);

    printf("Enter Total Expenses: ");
    scanf("%lf", &expenses);

    // Calculate balance
    balance = revenue - expenses;

    // Display basic budget
    printf("\n========================================\n");
    printf("          MUNICIPAL BUDGET\n");
    printf("========================================\n");

    printf("Revenue : %.2f\n", revenue);
    printf("Expenses: %.2f\n", expenses);
    printf("Balance : %.2f\n", balance);

    // Extension exercise
    printf("\n========================================\n");
    printf("      MUNICIPAL FINANCIAL SUMMARY\n");
    printf("========================================\n");

    printf("Enter number of departments: ");
    scanf("%d", &departments);

    printf("Enter payroll amount: ");
    scanf("%lf", &payroll);

    printf("Enter procurement amount: ");
    scanf("%lf", &procurement);

    printf("Enter assets value: ");
    scanf("%lf", &assets);

    // Display financial summary
    printf("\n========================================\n");
    printf("        FINANCIAL SUMMARY\n");
    printf("========================================\n");

    printf("Departments : %d\n", departments);
    printf("Payroll     : %.2f\n", payroll);
    printf("Procurement : %.2f\n", procurement);
    printf("Assets      : %.2f\n", assets);

    printf("========================================\n");

    return 0;
}