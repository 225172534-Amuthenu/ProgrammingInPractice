#include <stdio.h>
#include "budget.h"
#include "utilities.h"

static float revenue = 0.0f;
static float expenses = 0.0f;

void enterBudget(void)
{
    revenue = readFloat("Enter municipal revenue: ");
    expenses = readFloat("Enter municipal expenses: ");

    printf("Budget information saved successfully.\n");
}

float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}

void displayBudgetSummary(void)
{
    float balance = calculateBudget(revenue, expenses);

    printf("\n========== BUDGET SUMMARY ==========\n");
    printf("Revenue: N$%.2f\n", revenue);
    printf("Expenses: N$%.2f\n", expenses);
    printf("Balance: N$%.2f\n", balance);

    if (balance > 0)
    {
        printf("STATUS: SURPLUS\n");
    }
    else if (balance < 0)
    {
        printf("STATUS: DEFICIT\n");
    }
    else
    {
        printf("STATUS: BALANCED\n");
    }
}

float getRevenue(void)
{
    return revenue;
}

float getExpenses(void)
{
    return expenses;
}int saveBudget(void)
{
    FILE *file = fopen("data/budget.txt", "w");

    if (file == NULL)
    {
        printf("Error: Could not save budget data.\n");
        return 0;
    }

    fprintf(file, "%.2f\n%.2f\n", revenue, expenses);

    fclose(file);

    printf("Budget saved successfully.\n");
    return 1;
}

int loadBudget(void)
{
    FILE *file = fopen("data/budget.txt", "r");

    if (file == NULL)
    {
        printf("Error: Could not load budget data.\n");
        return 0;
    }

    if (fscanf(file, "%f %f", &revenue, &expenses) != 2)
    {
        fclose(file);
        printf("Invalid budget file.\n");
        return 0;
    }

    fclose(file);

    printf("Budget loaded successfully.\n");
    return 1;
}