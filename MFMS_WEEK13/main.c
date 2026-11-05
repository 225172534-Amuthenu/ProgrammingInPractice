#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "reports.h"
#include "records.h"

/* Week 11 record functions */
void recordsAddEmployee(void);
void recordsDisplayEmployees(void);

void recordsAddSupplier(void);
void recordsDisplaySuppliers(void);

void recordsAddAsset(void);
void recordsDisplayAssets(void);

void recordsAddBudget(void);
void recordsDisplayBudgets(void);

void recordsAddProject(void);
void recordsDisplayProjects(void);

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
        printf("12. Add Week 11 Employee\n");
        printf("13. Display Week 11 Employees\n");
        printf("14. Add Supplier\n");  
        printf("15. Display Suppliers\n");
        printf("16. Add Asset\n");
        printf("17. Display Assets\n");
        printf("18. Add Department Budget\n");
        printf("19. Display Department Budgets\n");
        printf("20. Add Project\n");
        printf("21. Display Projects\n");
        printf("22. Update Employee Salary\n");
        printf("23. Search Week 11 Employee by ID\n");

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
                 recordsFreeEmployees();
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
                 
            case 12:
                 recordsAddEmployee();
                break;

            case 13:
                 recordsDisplayEmployees();
                 break;

            case 14:
                 recordsAddSupplier();
                 break;

            case 15:
                 recordsDisplaySuppliers();
                 break;

            case 16:
                 recordsAddAsset();
                 break;

            case 17:
                 recordsDisplayAssets();
                 break;

            case 18:
                 recordsAddBudget();
                 break;

            case 19:
                 recordsDisplayBudgets();
                 break;

            case 20:
                 recordsAddProject();
                 break;

            case 21:
                 recordsDisplayProjects();
                 break;  
            case 22:
                 recordsUpdateEmployeeSalary();
                 break;    
            case 23:
                 recordsSearchEmployee();
                 break;    

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 7);

    return 0;
}