#ifndef BUDGET_H
#define BUDGET_H

extern char departmentNames[15][60];
extern double budgets[15];
extern double expenditures[15];
extern int departmentCount;

void budgetMenu(void);
void addBudget(void);
void displayBudgets(void);
void displayBudgetReport(void);
double calculateBudget(double budget, double expenditure);

#endif