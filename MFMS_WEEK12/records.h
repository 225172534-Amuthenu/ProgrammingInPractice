
/* records.h - The five MFMS record types */

#ifndef RECORDS_H
#define RECORDS_H

#define MAX_RECORDS 100

/* Date structure */
typedef struct
{
    int day;
    int month;
    int year;
} Date;

/* Employee structure */
typedef struct
{
    int id;
    char name[30];
    char department[20];
    double salary;
} RecordEmployee;

/* Supplier structure */
typedef struct
{
    int id;
    char name[40];
    char email[40];
    char phone[15];
    char town[20];
} Supplier;

/* Asset structure */
typedef struct
{
    int id;
    char description[40];
    double value;
    Date acquired;
} Asset;

/* Budget structure */
typedef struct
{
    char department[20];
    double allocated;
    double spent;
} Budget;

/* Project structure */
typedef struct
{
    int id;
    char title[40];
    double budget;
    Date startDate;
    Date endDate;
} Project;

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
void recordsUpdateEmployeeSalary(void);

void updateSalary(RecordEmployee *e, double newSalary);

RecordEmployee *findEmployee(RecordEmployee list[], int n, int id);

void recordsUpdateEmployeeSalary(void);

#endif
