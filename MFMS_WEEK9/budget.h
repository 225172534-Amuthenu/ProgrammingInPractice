#ifndef BUDGET_H
#define BUDGET_H

void enterBudget(void);
float calculateBudget(float revenue, float expenses);
void displayBudgetSummary(void);
float getRevenue(void);
float getExpenses(void);

int saveBudget(void);
int loadBudget(void);

#endif