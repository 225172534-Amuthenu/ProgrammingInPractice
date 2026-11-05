#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "reports.h"

int main(void)
{
    int choice;

    do
    {
        printf("\n==================================\n");
        printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
        printf("==================================\n");

        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Enter Budget\n");
        printf("5. Display Budget Summary\n");
        printf("6. Display General Reports\n");
        printf("7. Exit\n");
        printf("8. Save Data\n");
        printf("9. Load Data\n");
        printf("10. Save Employees (Binary)\n");
        printf("11. Load Employees (Binary)\n");

        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
        {
            int ch;

            while ((ch = getchar()) != '\n' && ch != EOF)
            {
                /* Clear invalid input */
            }

            printf("Invalid choice. Enter a number.\n");
            continue;
        }

        /* Remove the newline left by scanf */
        {
            int ch;

            while ((ch = getchar()) != '\n' && ch != EOF)
            {
                /* Clear remaining input */
            }
        }

        switch (choice)
        {
            case 1:
                addEmployee();
                break;

            case 2:
                displayEmployees();
                break;

            case 3:
                searchEmployee();
                break;

            case 4:
                enterBudget();
                break;

            case 5:
                displayBudgetSummary();
                break;

            case 6:
                displayReports();
                break;

            case 7:
                printf("Exiting MFMS. Goodbye!\n");
                break;
            case 8:
                 saveEmployees();
                 saveBudget();
                 break;

            case 9:
                 loadEmployees();
                 loadBudget();
                 break;
      
            case 10:
                 saveEmployeesBinary();
                 break;

            case 11:
                 loadEmployeesBinary();
                 break;    

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 7);

    return 0;
}