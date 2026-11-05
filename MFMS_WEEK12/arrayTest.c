#include <stdio.h>

/* Task 5: Display salaries */
void displaySalaries(const double salaries[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("Employee %d: N$%.2f\n", i + 1, salaries[i]);
    }
}

/* Task 6: Find highest salary */
double findHighest(const double salaries[], int n)
{
    if (n <= 0)
    {
        return 0.0;
    }

    double highest = salaries[0];
    int i;

    for (i = 1; i < n; i++)
    {
        if (salaries[i] > highest)
        {
            highest = salaries[i];
        }
    }

    return highest;
}

/* Task 6: Calculate average salary */
double calculateAverage(const double salaries[], int n)
{
    double total = 0.0;
    int i;

    if (n <= 0)
    {
        return 0.0;
    }

    for (i = 0; i < n; i++)
    {
        total += salaries[i];
    }

    return total / n;
}

/* Task 7: Give employees a salary increase */
void giveRaise(double salaries[], int n, double percent)
{
    int i;

    for (i = 0; i < n; i++)
    {
        salaries[i] = salaries[i] +
                      (salaries[i] * percent / 100.0);
    }
}

int main(void)
{
    double salaries[3] = {15000.00, 18500.50, 21000.75};

    int count = 3;

    printf("===== ORIGINAL SALARIES =====\n");

    displaySalaries(salaries, count);

    printf("\n===== HIGHEST SALARY =====\n");

    printf("Highest salary: N$%.2f\n",
           findHighest(salaries, count));

    printf("\n===== AVERAGE SALARY =====\n");

    printf("Average salary: N$%.2f\n",
           calculateAverage(salaries, count));

    printf("\n===== GIVING 10%% RAISE =====\n");

    giveRaise(salaries, count, 10);

    printf("\n===== UPDATED SALARIES =====\n");

    displaySalaries(salaries, count);

    return 0;
}
