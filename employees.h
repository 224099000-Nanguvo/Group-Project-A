#ifndef EMPLOYEES_H
#define EMPLOYEES_H

// employees.h - for employee management
// Student 1: 

#define MAX 100

struct Employee {
    int id;
    char name[50];  // employee name - string
    char department[30]; // department - string
    float basic;
    float housing;
    float transport;
    float total;
};

// global - so main can see it
extern struct Employee empList[MAX];
extern int count;

// functions
void addEmp();
void displayAll();
void searchEmp();
float calcTotal(float b, float h, float t);
void employeeMenu();
void clearBuffer();

#endif