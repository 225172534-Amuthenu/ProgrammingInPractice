
#include <stdio.h>
#include "records.h"
#include "utilities.h"

/* Week 11 record arrays */
static Employee employees[MAX_RECORDS];
static int employeeCount = 0;

static Supplier suppliers[MAX_RECORDS];
static int supplierCount = 0;

static Asset assets[MAX_RECORDS];
static int assetCount = 0;

static Budget budgets[MAX_RECORDS];
static int budgetCount = 0;

static Project projects[MAX_RECORDS];
static int projectCount = 0;

/* Add a Week 11 employee */
void recordsAddEmployee(void)
{
    if (employeeCount >= MAX_RECORDS)
    {
        printf("Employee list is full.\n");
        return;
    }

    employees[employeeCount].id =
        readInt("Enter employee ID: ");

    readLine("Enter employee name: ",
             employees[employeeCount].name,
             sizeof(employees[employeeCount].name));

    readLine("Enter department: ",
             employees[employeeCount].department,
             sizeof(employees[employeeCount].department));

    employees[employeeCount].salary =
        readFloat("Enter employee salary: ");

    employeeCount++;

    printf("Week 11 employee added successfully.\n");
}

/* Display Week 11 employees */
void recordsDisplayEmployees(void)
{
    int i;

    if (employeeCount == 0)
    {
        printf("No Week 11 employees registered.\n");
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