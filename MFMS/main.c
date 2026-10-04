#ifndef FUNCTIONS_H
#define FUNCTIONS_H


//Employee Management 
void employeeMenu(void);
void addEmployee(void);
void displayEmployees(void);
void searchEmployee(void);
double calculateSalary(double basicSalary, double housing, double transport);

//Budget Management 
void budgetMenu(void);
void addBudget(void);
void displayBudgets(void);
void displayBudgetReport(void);
double calculateBudget(double budget, double expenditure);

//Supplier Management 
void supplierMenu(void);
void addSupplier(void);
void displaySuppliers(void);
void searchSupplier(void);

//Asset Management 
int readInt(const char *prompt, int min, int max);
void addAsset(void);
void displayAssets(void);
void searchAsset(void);
void assetMenu(void);

//Reports Module 
void reportsMenu(void);
void employeeReport(void);
void budgetReport(void);
void supplierReport(void);
void assetReport(void);

#endif