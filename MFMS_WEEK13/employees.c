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

    employees[employeeCount].id = readInt("Enter employee ID: ");

    readLine("Enter employee name: ",
             employees[employeeCount].name,
             sizeof(employees[employeeCount].name));

    employees[employeeCount].basicSalary = readFloat("Enter basic salary: ");
    employees[employeeCount].housing = readFloat("Enter housing allowance: ");
    employees[employeeCount].transport = readFloat("Enter transport allowance: ");

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

    for (i = 0; i < employeeCount; i++)
    {
        printf("\nEmployee ID: %d\n", employees[i].id);
        printf("Name: %s\n", employees[i].name);
        printf("Gross Salary: %.2f\n",
               calculateSalary(employees[i].basicSalary,
                               employees[i].housing,
                               employees[i].transport));
    }
}

void searchEmployee(void)
{
    int id = readInt("Enter employee ID to search: ");
    int i;

    for (i = 0; i < employeeCount; i++)
    {
        if (employees[i].id == id)
        {
            printf("Employee found!\n");
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
        total += calculateSalary(employees[i].basicSalary,
                                 employees[i].housing,
                                 employees[i].transport);
    }

    return total;
}
int saveEmployees(void)
{
    FILE *file = fopen("data/employees.txt", "w");
    int i;

    if (file == NULL)
    {
        printf("Error: Could not open employees.txt for saving.\n");
        return 0;
    }

    for (i = 0; i < employeeCount; i++)
    {
        fprintf(file, "%d|%s|%.2f|%.2f|%.2f\n",
                employees[i].id,
                employees[i].name,
                employees[i].basicSalary,
                employees[i].housing,
                employees[i].transport);
    }

    fclose(file);

    printf("Employees saved successfully.\n");
    return 1;
}
int loadEmployees(void)
{
    FILE *file = fopen("data/employees.txt", "r");
    char line[200];

    if (file == NULL)
    {
        printf("Error: Could not open employees.txt for loading.\n");
        return 0;
    }

    employeeCount = 0;

    while (fgets(line, sizeof(line), file) != NULL)
    {
        Employee employee;

        if (employeeCount >= MAX_EMPLOYEES)
        {
            printf("Maximum employee capacity reached.\n");
            break;
        }

        if (sscanf(line, "%d|%49[^|]|%f|%f|%f",
                   &employee.id,
                   employee.name,
                   &employee.basicSalary,
                   &employee.housing,
                   &employee.transport) == 5)
        {
            employees[employeeCount] = employee;
            employeeCount++;
        }
    }

    fclose(file);

    printf("%d employee record(s) loaded.\n", employeeCount);
    return 1;
}int saveEmployeesBinary(void)
{
    FILE *file = fopen("data/employees.dat", "wb");

    if (file == NULL)
    {
        printf("Error: Could not create employees.dat.\n");
        return 0;
    }

    if (fwrite(&employeeCount, sizeof(employeeCount), 1, file) != 1)
    {
        fclose(file);
        printf("Error saving employee count.\n");
        return 0;
    }

    if (fwrite(employees, sizeof(Employee), employeeCount, file)
        != (size_t)employeeCount)
    {
        fclose(file);
        printf("Error saving employee records.\n");
        return 0;
    }

    fclose(file);

    printf("Employees saved in binary format.\n");
    return 1;
}int loadEmployeesBinary(void)
{
    FILE *file = fopen("data/employees.dat", "rb");
    int count;

    if (file == NULL)
    {
        printf("Error: Could not open employees.dat.\n");
        return 0;
    }

    if (fread(&count, sizeof(count), 1, file) != 1 ||
        count < 0 || count > MAX_EMPLOYEES)
    {
        fclose(file);
        printf("Invalid binary employee file.\n");
        return 0;
    }

    if (fread(employees, sizeof(Employee), count, file)
        != (size_t)count)
    {
        fclose(file);
        printf("Error reading employee records.\n");
        return 0;
    }

    employeeCount = count;

    fclose(file);

    printf("%d employee record(s) loaded from binary file.\n",
           employeeCount);

    return 1;
}
