
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[30];
    double salary;
} Employee;

int main(void)
{
    int capacity = 2;
    int count = 0;
    int i;

    Employee *employees = NULL;
    Employee *bigger;
    Employee e;

    /* TODO 1: Allocate initial memory */
    employees = malloc(capacity * sizeof(Employee));

    if (employees == NULL) {
        printf("Out of memory!\n");
        return 1;
    }

    printf("Employee ID (0 to stop): ");

    if (scanf("%d", &e.id) != 1) {
        free(employees);
        return 1;
    }

    while (e.id != 0) {

        printf("Name (one word): ");
        scanf("%29s", e.name);

        printf("Salary: ");
        scanf("%lf", &e.salary);

        /* TODO 2: Grow the array if full */
        if (count == capacity) {

            capacity = capacity * 2;

            bigger = realloc(
                employees,
                capacity * sizeof(Employee)
            );

            if (bigger == NULL) {
                printf("Out of memory!\n");
                free(employees);
                return 1;
            }

            employees = bigger;

            printf("(grown to %d slots)\n", capacity);
        }

        /* TODO 3: Store employee and increase count */
        employees[count] = e;
        count++;

        printf("Employee ID (0 to stop): ");

        if (scanf("%d", &e.id) != 1) {
            free(employees);
            return 1;
        }
    }

    /* TODO 4: Display all employees */
    printf("\n--- EMPLOYEE LIST ---\n");

    for (i = 0; i < count; i++) {
        printf("%d  %-10s N$%.2f\n",
               employees[i].id,
               employees[i].name,
               employees[i].salary);
    }

    printf("\nEmployees: %d | Capacity: %d\n",
           count, capacity);

    /* TODO 5: Release allocated memory */
    free(employees);
    employees = NULL;

    return 0;
}
