#include <stdio.h>
int main() {
    float Salary;
    float total = 0;
    float highest = 0;
    float lowest = 0;
    float average = 0;

    for (int i = 1; i <= 50; i++) {
       printf("Enter employee salary %d:", i);
       scanf("%f", &Salary);

       total = total + Salary;

       if (i == 1) {
           highest = Salary;
           lowest = Salary;
        }
        if (Salary > highest) {
            highest = Salary;
        }
        if(Salary < lowest) {
            lowest = Salary;
        }
    }
    average = total/50;

    printf("\n--- Salary Report ---\n");
    printf("Average salary: %.2f\n", average);
    printf("Highest salary: %.2f\n", highest);
    printf("Lowest salary: %.2f\n", lowest);

    return 0;
}