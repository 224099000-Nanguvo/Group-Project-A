#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 100
#define MAX MAX_EMPLOYEES

typedef struct {
    int id;
    char name[50];
    char department[30];
    float basic;
    float housing;
    float transport;
    float total;
} Employee;

extern Employee empList[MAX_EMPLOYEES];
extern int count;

void clearBuffer(void);
float calcTotal(float basicSalary, float houseAllowance, float transportAllowance);
void addEmp(void);
void displayAll(void);
void searchEmp(void);
void employeeMenu(void);

#endif