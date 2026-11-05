#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 100

typedef struct
{
    int id;
    char name[50];
    float basicSalary;
    float housing;
    float transport;
} Employee;

void addEmployee(void);
void displayEmployees(void);
void searchEmployee(void);
int getEmployeeCount(void);
float getTotalPayroll(void);

float calculateSalary(float basic, float housing, float transport);

int saveEmployees(void);
int loadEmployees(void);

int saveEmployeesBinary(void);
int loadEmployeesBinary(void);

#endif