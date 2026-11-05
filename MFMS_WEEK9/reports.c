#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"

void displayReports(void)
{
    printf("\n========== MFMS GENERAL REPORT ==========\n");

    printf("\nEMPLOYEE INFORMATION\n");
    printf("Number of employees: %d\n", getEmployeeCount());
    printf("Total employee payroll: N$%.2f\n",
           getTotalPayroll());

    printf("\nBUDGET INFORMATION\n");
    printf("Municipal revenue: N$%.2f\n", getRevenue());
    printf("Municipal expenses: N$%.2f\n", getExpenses());

    displayBudgetSummary();

    printf("\n=========================================\n");
}