#include <stdio.h>
#include <string.h>

int main() {

    // A. Employee salaries
    float salaries[50];
    float totalSalary = 0;
    float averageSalary;
    float highestSalary;
    float lowestSalary;
    float searchSalary;
    int salaryFound = 0;

    printf("====================================\n");
    printf(" MUNICIPAL INFORMATION MANAGEMENT\n");
    printf("====================================\n");

    // Capture 50 salaries
    printf("\n--- A. EMPLOYEE SALARIES ---\n");

    for (int i = 0; i < 50; i++) {
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%f", &salaries[i]);

        totalSalary += salaries[i];
    }

    // Display salaries
    printf("\nEmployee Salaries:\n");

    for (int i = 0; i < 50; i++) {
        printf("Employee %d: %.2f\n", i + 1, salaries[i]);
    }

    // Calculate average
    averageSalary = totalSalary / 50;

    // Find highest and lowest
    highestSalary = salaries[0];
    lowestSalary = salaries[0];

    for (int i = 1; i < 50; i++) {

        if (salaries[i] > highestSalary) {
            highestSalary = salaries[i];
        }

        if (salaries[i] < lowestSalary) {
            lowestSalary = salaries[i];
        }
    }

    printf("\nTotal Salaries: %.2f\n", totalSalary);
    printf("Average Salary: %.2f\n", averageSalary);
    printf("Highest Salary: %.2f\n", highestSalary);
    printf("Lowest Salary: %.2f\n", lowestSalary);

    // Search for a salary
    printf("\nEnter salary to search for: ");
    scanf("%f", &searchSalary);

    for (int i = 0; i < 50; i++) {

        if (salaries[i] == searchSalary) {
            printf("Salary found at employee %d.\n", i + 1);
            salaryFound = 1;
        }
    }

    if (salaryFound == 0) {
        printf("Salary not found.\n");
    }


    // B. Department budgets
    float budgets[10];
    float totalBudget = 0;
    float averageBudget;
    float temp;

    printf("\n--- B. DEPARTMENT BUDGETS ---\n");

    // Capture 10 budgets
    for (int i = 0; i < 10; i++) {
        printf("Enter budget for department %d: ", i + 1);
        scanf("%f", &budgets[i]);

        totalBudget += budgets[i];
    }

    // Display budgets
    printf("\nDepartment Budgets:\n");

    for (int i = 0; i < 10; i++) {
        printf("Department %d: %.2f\n", i + 1, budgets[i]);
    }

    // Calculate total and average
    averageBudget = totalBudget / 10;

    printf("\nTotal Budget: %.2f\n", totalBudget);
    printf("Average Budget: %.2f\n", averageBudget);

    // Sort budgets from lowest to highest
    for (int i = 0; i < 9; i++) {

        for (int j = 0; j < 9 - i; j++) {

            if (budgets[j] > budgets[j + 1]) {

                temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }

    // Display sorted budgets
    printf("\nBudgets Sorted (Lowest to Highest):\n");

    for (int i = 0; i < 10; i++) {
        printf("%.2f\n", budgets[i]);
    }


    // C. Vehicle registration numbers
    char registrations[20][20];
    char searchRegistration[20];
    int registrationFound = 0;

    printf("\n--- C. VEHICLE REGISTRATIONS ---\n");

    // Capture 20 registrations
    for (int i = 0; i < 20; i++) {
        printf("Enter registration number %d: ", i + 1);
        scanf("%19s", registrations[i]);
    }

    // Display registrations
    printf("\nVehicle Registration Numbers:\n");

    for (int i = 0; i < 20; i++) {
        printf("%d. %s\n", i + 1, registrations[i]);
    }

    // Search for a registration
    printf("\nEnter registration number to search: ");
    scanf("%19s", searchRegistration);

    for (int i = 0; i < 20; i++) {

        if (strcmp(registrations[i], searchRegistration) == 0) {
            printf("Registration found at position %d.\n", i + 1);
            registrationFound = 1;
        }
    }

    if (registrationFound == 0) {
        printf("Registration number not found.\n");
    }

    printf("\n====================================\n");
    printf(" PROGRAM COMPLETED SUCCESSFULLY\n");
    printf("====================================\n");

    return 0;
}