
#include <stdio.h>
#include <stdlib.h>
#include "records.h"
#include "utilities.h"

/* Week 13: Dynamic employee array */
static RecordEmployee *employees = NULL;
static int employeeCount = 0;
static int employeeCapacity = 0;

/* Other Week 11 record arrays remain fixed */
static Supplier suppliers[MAX_RECORDS];
static int supplierCount = 0;

static Asset assets[MAX_RECORDS];
static int assetCount = 0;

static Budget budgets[MAX_RECORDS];
static int budgetCount = 0;

static Project projects[MAX_RECORDS];
static int projectCount = 0;

/* Week 13: Add employee using dynamic memory */
void recordsAddEmployee(void)
{
    RecordEmployee newEmployee;
    RecordEmployee *bigger;

    /* Get employee information */
    newEmployee.id = readInt("Enter employee ID: ");

    readLine("Enter employee name: ",
             newEmployee.name,
             sizeof(newEmployee.name));

    readLine("Enter department: ",
             newEmployee.department,
             sizeof(newEmployee.department));

    newEmployee.salary =
        readFloat("Enter employee salary: ");

    /* TODO 1: Allocate initial memory */
    if (employees == NULL)
    {
        employeeCapacity = 2;

        employees = malloc(
            employeeCapacity * sizeof(RecordEmployee)
        );

        if (employees == NULL)
        {
            printf("Out of memory!\n");
            employeeCapacity = 0;
            return;
        }
    }

    /* TODO 2: Double capacity when full */
    if (employeeCount == employeeCapacity)
    {
        employeeCapacity *= 2;

        bigger = realloc(
            employees,
            employeeCapacity * sizeof(RecordEmployee)
        );

        if (bigger == NULL)
        {
            printf("Out of memory!\n");
            employeeCapacity /= 2;
            return;
        }

        employees = bigger;

        printf("Employee storage grown to %d slots.\n",
               employeeCapacity);
    }

    /* TODO 3: Store employee */
    employees[employeeCount] = newEmployee;
    employeeCount++;

    printf("Employee added successfully.\n");
}

/* Week 13: Display dynamic employees */
void recordsDisplayEmployees(void)
{
    int i;

    if (employeeCount == 0)
    {
        printf("No Week 11 employees registered.\n");
        printf("Employees: 0 | Capacity: %d\n",
               employeeCapacity);
        return;
    }

    printf("\n%-8s %-30s %-20s %12s\n",
           "ID", "NAME", "DEPARTMENT", "SALARY");

    printf("--------------------------------------------------------------------------\n");

    for (i = 0; i < employeeCount; i++)
    {
        printf("%-8d %-30s %-20s %12.2f\n",
               employees[i].id,
               employees[i].name,
               employees[i].department,
               employees[i].salary);
    }

    printf("\nEmployees: %d | Capacity: %d\n",
           employeeCount, employeeCapacity);
}
void recordsSearchEmployee(void)
{
    int id;
    RecordEmployee *found;

    if (employeeCount == 0)
    {
        printf("No employees registered.\n");
        return;
    }

    id = readInt("Enter employee ID to search: ");

    found = findEmployee(employees, employeeCount, id);

    if (found == NULL)
    {
        printf("Employee with ID %d not found.\n", id);
        return;
    }

    printf("\n===== EMPLOYEE FOUND =====\n");
    printf("ID: %d\n", found->id);
    printf("Name: %s\n", found->name);
    printf("Department: %s\n", found->department);
    printf("Salary: N$%.2f\n", found->salary);
}

/* Add a supplier */
void recordsAddSupplier(void)
{
    if (supplierCount >= MAX_RECORDS)
    {
        printf("Supplier list is full.\n");
        return;
    }

    suppliers[supplierCount].id =
        readInt("Enter supplier ID: ");

    readLine("Enter supplier name: ",
             suppliers[supplierCount].name,
             sizeof(suppliers[supplierCount].name));

    readLine("Enter supplier email: ",
             suppliers[supplierCount].email,
             sizeof(suppliers[supplierCount].email));

    readLine("Enter supplier phone: ",
             suppliers[supplierCount].phone,
             sizeof(suppliers[supplierCount].phone));

    readLine("Enter supplier town: ",
             suppliers[supplierCount].town,
             sizeof(suppliers[supplierCount].town));

    supplierCount++;

    printf("Supplier added successfully.\n");
}

/* Display suppliers */
void recordsDisplaySuppliers(void)
{
    int i;

    if (supplierCount == 0)
    {
        printf("No suppliers registered.\n");
        return;
    }

    printf("\n%-8s %-40s %-40s %-15s %-20s\n",
           "ID", "NAME", "EMAIL", "PHONE", "TOWN");

    printf("----------------------------------------------------------------------------------------------------------------\n");

    for (i = 0; i < supplierCount; i++)
    {
        printf("%-8d %-40s %-40s %-15s %-20s\n",
               suppliers[i].id,
               suppliers[i].name,
               suppliers[i].email,
               suppliers[i].phone,
               suppliers[i].town);
    }
}

/* Add an asset */
void recordsAddAsset(void)
{
    if (assetCount >= MAX_RECORDS)
    {
        printf("Asset list is full.\n");
        return;
    }

    assets[assetCount].id =
        readInt("Enter asset ID: ");

    readLine("Enter asset description: ",
             assets[assetCount].description,
             sizeof(assets[assetCount].description));

    assets[assetCount].value =
        readFloat("Enter asset value: ");

    printf("\nEnter acquisition date:\n");

    assets[assetCount].acquired.day =
        readInt("Day: ");

    assets[assetCount].acquired.month =
        readInt("Month: ");

    assets[assetCount].acquired.year =
        readInt("Year: ");

    assetCount++;

    printf("Asset added successfully.\n");
}

/* Display assets */
void recordsDisplayAssets(void)
{
    int i;

    if (assetCount == 0)
    {
        printf("No assets registered.\n");
        return;
    }

    printf("\n%-8s %-40s %-12s %-15s\n",
           "ID", "DESCRIPTION", "VALUE", "ACQUIRED");

    printf("--------------------------------------------------------------------------\n");

    for (i = 0; i < assetCount; i++)
    {
        printf("%-8d %-40s %-12.2f %02d/%02d/%04d\n",
               assets[i].id,
               assets[i].description,
               assets[i].value,
               assets[i].acquired.day,
               assets[i].acquired.month,
               assets[i].acquired.year);
    }
}

/* Add a budget */
void recordsAddBudget(void)
{
    if (budgetCount >= MAX_RECORDS)
    {
        printf("Budget list is full.\n");
        return;
    }

    readLine("Enter department name: ",
             budgets[budgetCount].department,
             sizeof(budgets[budgetCount].department));

    budgets[budgetCount].allocated =
        readFloat("Enter allocated budget: ");

    budgets[budgetCount].spent =
        readFloat("Enter amount spent: ");

    budgetCount++;

    printf("Budget added successfully.\n");
}

/* Display budgets */
void recordsDisplayBudgets(void)
{
    int i;
    double balance;

    if (budgetCount == 0)
    {
        printf("No budgets registered.\n");
        return;
    }

    printf("\n%-20s %15s %15s %15s\n",
           "DEPARTMENT", "ALLOCATED", "SPENT", "BALANCE");

    printf("--------------------------------------------------------------------------\n");

    for (i = 0; i < budgetCount; i++)
    {
        balance = budgets[i].allocated - budgets[i].spent;

        printf("%-20s %15.2f %15.2f %15.2f\n",
               budgets[i].department,
               budgets[i].allocated,
               budgets[i].spent,
               balance);

        if (budgets[i].spent > budgets[i].allocated)
        {
            printf("WARNING: Department has exceeded its budget!\n");
        }
    }
}
void recordsAddProject(void)
{
    if (projectCount >= MAX_RECORDS)
    {
        printf("Project list is full.\n");
        return;
    }

    projects[projectCount].id =
        readInt("Enter project ID: ");

    readLine("Enter project title: ",
             projects[projectCount].title,
             sizeof(projects[projectCount].title));

    projects[projectCount].budget =
        readFloat("Enter project budget: ");

    printf("\nEnter project start date:\n");

    projects[projectCount].startDate.day =
        readInt("Day: ");

    projects[projectCount].startDate.month =
        readInt("Month: ");

    projects[projectCount].startDate.year =
        readInt("Year: ");

    printf("\nEnter project end date:\n");

    projects[projectCount].endDate.day =
        readInt("Day: ");

    projects[projectCount].endDate.month =
        readInt("Month: ");

    projects[projectCount].endDate.year =
        readInt("Year: ");

    projectCount++;

    printf("\nProject added successfully.\n");
}


void recordsDisplayProjects(void)
{
    int i;

    if (projectCount == 0)
    {
        printf("No projects registered.\n");
        return;
    }

    printf("\n%-8s %-40s %12s %15s %15s\n",
           "ID", "TITLE", "BUDGET", "START DATE", "END DATE");

    printf("-----------------------------------------------------------------------------------------------\n");

    for (i = 0; i < projectCount; i++)
    {
        printf("%-8d %-40s %12.2f %02d/%02d/%04d %02d/%02d/%04d\n",
               projects[i].id,
               projects[i].title,
               projects[i].budget,
               projects[i].startDate.day,
               projects[i].startDate.month,
               projects[i].startDate.year,
               projects[i].endDate.day,
               projects[i].endDate.month,
               projects[i].endDate.year);
    }
}
/* Week 12: Update an employee's salary using a pointer */
void updateSalary(RecordEmployee *e, double newSalary)
{
    e->salary = newSalary;
}

/* Week 12: Find an employee by ID */
RecordEmployee *findEmployee(RecordEmployee list[], int n, int id)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (list[i].id == id)
        {
            return &list[i];
        }
    }

    return NULL;
}

/* Week 12: Menu operation to update employee salary */
void recordsUpdateEmployeeSalary(void)
{
    int id;
    double newSalary;

    RecordEmployee *found;

    if (employeeCount == 0)
    {
        printf("\nNo employees registered. Add employees first.\n");
        return;
    }

    printf("\n===== UPDATE EMPLOYEE SALARY =====\n");

    id = readInt("Enter employee ID: ");

    found = findEmployee(employees, employeeCount, id);

    if (found == NULL)
    {
        printf("\nEmployee with ID %d was not found.\n", id);
        return;
    }

    printf("\nEmployee found!\n");
    printf("Name: %s\n", found->name);
    printf("Department: %s\n", found->department);
    printf("Current salary: N$%.2f\n", found->salary);

    newSalary = readFloat("Enter new salary: ");

    updateSalary(found, newSalary);

    printf("\n===== SALARY UPDATED SUCCESSFULLY =====\n");
    printf("Employee ID: %d\n", found->id);
    printf("Employee Name: %s\n", found->name);
    printf("Department: %s\n", found->department);
    printf("Updated Salary: N$%.2f\n", found->salary);
}/* Week 13: Release employee memory */
void recordsFreeEmployees(void)
{
    free(employees);

    employees = NULL;
    employeeCount = 0;
    employeeCapacity = 0;
}
