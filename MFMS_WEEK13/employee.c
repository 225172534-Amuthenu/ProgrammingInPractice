#include <stdio.h>
#include "employees.h"
#include "utilities.h"

static Employee employees[MAX_EMPLOYEES];
static int employeeCount = 0;

float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

void addEmployee(void)
{
    if (employeeCount >= MAX_EMPLOYEES)
    {
        printf("Employee list is full.\n");
        return;
    }

    employees[employeeCount].id =
        readInt("Enter employee ID: ");

    readLine("Enter employee name: ",
             employees[employeeCount].name,
             sizeof(employees[employeeCount].name));

    employees[employeeCount].basicSalary =
        readFloat("Enter basic salary: ");

    employees[employeeCount].housing =
        readFloat("Enter housing allowance: ");

    employees[employeeCount].transport =
        readFloat("Enter transport allowance: ");

    employeeCount++;

    printf("Employee added successfully.\n");
}

void displayEmployees(void)
{
    int i;

    if (employeeCount == 0)
    {
        printf("No employees registered.\n");
        return;
    }

    printf("\n========== EMPLOYEE LIST ==========\n");

    for (i = 0; i < employeeCount; i++)
    {
        printf("\nEmployee ID: %d\n", employees[i].id);
        printf("Name: %s\n", employees[i].name);

        printf("Gross Salary: %.2f\n",
               calculateSalary(
                   employees[i].basicSalary,
                   employees[i].housing,
                   employees[i].transport
               ));
    }
}

void searchEmployee(void)
{
    int id;
    int i;

    id = readInt("Enter employee ID to search: ");

    for (i = 0; i < employeeCount; i++)
    {
        if (employees[i].id == id)
        {
            printf("\nEmployee found!\n");
            printf("ID: %d\n", employees[i].id);
            printf("Name: %s\n", employees[i].name);
            return;
        }
    }

    printf("Employee not found.\n");
}

int getEmployeeCount(void)
{
    return employeeCount;
}

float getTotalPayroll(void)
{
    int i;
    float total = 0.0f;

    for (i = 0; i < employeeCount; i++)
    {
        total += calculateSalary(
            employees[i].basicSalary,
            employees[i].housing,
            employees[i].transport
        );
    }

    return total;
}