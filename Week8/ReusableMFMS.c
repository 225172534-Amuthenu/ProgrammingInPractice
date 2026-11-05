#include <stdio.h>

/* Function declarations (prototypes) */
void displayWelcome(void);
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
void displayMenu(void);
int searchEmployee(int id, int ids[], int size);

int main(void)
{
    /* Variables */
    int choice;
    float amount, vat;
    float basic, housing, transport, grossSalary;
    float revenue, expenses, balance;

    /* Task 1: Welcome message */
    displayWelcome();

    /* Task 6: Employee ID search */
    int employeeIDs[] = {101, 102, 103, 104, 105};
    int id;
    int position;

    printf("\nEnter employee ID to search: ");
    scanf("%d", &id);

    position = searchEmployee(id, employeeIDs, 5);

    if (position != -1)
    {
        printf("Employee found at position %d.\n", position);
    }
    else
    {
        printf("Employee not found.\n");
    }

    /* Task 5: Display and process menu */
    do
    {
        displayMenu();

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                /* Task 2: Calculate VAT */
                printf("Enter amount: ");
                scanf("%f", &amount);

                vat = calculateVAT(amount);

                printf("VAT: %.2f\n", vat);
                break;

            case 2:
                /* Task 3: Calculate salary */
                printf("Basic salary: ");
                scanf("%f", &basic);

                printf("Housing allowance: ");
                scanf("%f", &housing);

                printf("Transport allowance: ");
                scanf("%f", &transport);

                grossSalary = calculateSalary(basic, housing, transport);

                printf("Gross salary: %.2f\n", grossSalary);
                break;

            case 3:
                /* Task 4: Calculate budget */
                printf("Enter revenue: ");
                scanf("%f", &revenue);

                printf("Enter expenses: ");
                scanf("%f", &expenses);

                balance = calculateBudget(revenue, expenses);

                printf("Budget balance: %.2f\n", balance);

                if (balance > 0)
                {
                    printf("SURPLUS\n");
                }
                else if (balance < 0)
                {
                    printf("DEFICIT\n");
                }
                else
                {
                    printf("BALANCED\n");
                }
                break;

            case 4:
                printf("Exiting MFMS. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}

/* Task 1: Welcome function */
void displayWelcome(void)
{
    printf("\nWelcome to the Municipal Financial Management System\n");
}

/* Task 2: VAT function */
float calculateVAT(float amount)
{
    return amount * 0.15;
}

/* Task 3: Salary function */
float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

/* Task 4: Budget function */
float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}

/* Task 5: Menu function */
void displayMenu(void)
{
    printf("\n==================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
    printf("==================================\n");
    printf("1. Calculate VAT\n");
    printf("2. Calculate Salary\n");
    printf("3. Calculate Budget\n");
    printf("4. Exit\n");
}

/* Task 6: Search employee function */
int searchEmployee(int id, int ids[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (ids[i] == id)
        {
            return i;
        }
    }

    return -1;
}