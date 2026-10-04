#include <stdio.h>
#include <string.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"

void reportsMenu(void) {
    int choice;

    do {
        printf("\nREPORTS\n");
        printf("1. Employee Report\n");
        printf("2. Budget report\n");
        printf("3. Supplier report\n");
        printf("4. Asset report\n");
        printf("5. Return to main menu\n");
        choice = readInt("Enter choice: ", 1, 5);

        if (choice == 1) {
            employeeReport();
        } else if (choice == 2) {
            budgetReport();
        } else if (choice == 3) {
            supplierReport();
        } else if (choice == 4) {
            assetReport();
        }
    } while (choice != 5);
}

void employeeReport(void) {
    int i;
    double sumOfSalaries = 0.0;
    double highestSalary;
    double lowestSalary;
    double averageSalary;

    printf("\nEMPLOYEE REPORT\n");

    if (count == 0) {
        printf("No employees registered.\n");
        return;
    }

    highestSalary = empList[0].basic;
    lowestSalary = empList[0].basic;

    for (i = 0; i < count; i++) {
        sumOfSalaries += empList[i].basic;
        if (empList[i].basic > highestSalary) {
            highestSalary = empList[i].basic;
        }
        if (empList[i].basic < lowestSalary) {
            lowestSalary = empList[i].basic;
        }
    }

    averageSalary = sumOfSalaries / count;
    printf("Total number of employees: %d\n", count);
    printf("Average salary: N$%.2f\n", averageSalary);
    printf("Highest salary: N$%.2f\n", highestSalary);
    printf("Lowest salary: N$%.2f\n", lowestSalary);
}

void budgetReport(void) {
    int i;
    double totalAllocated = 0.0;
    double totalSpent = 0.0;
    double totalRemaining;
    int numberOverBudget = 0;

    printf("\nBUDGET REPORT\n");

    if (departmentCount == 0) {
        printf("Zero budgets registered.\n");
        return;
    }

    for (i = 0; i < departmentCount; i++) {
        totalAllocated += budgets[i];
        totalSpent += expenditures[i];
    }

    totalRemaining = totalAllocated - totalSpent;
    printf("Total Allocated budget: N$%.2f\n", totalAllocated);
    printf("Total Spent budget: N$%.2f\n", totalSpent);
    printf("Total Remaining budget: N$%.2f\n", totalRemaining);

    printf("Departments that spent over budget:\n");
    for (i = 0; i < departmentCount; i++) {
        if (expenditures[i] > budgets[i]) {
            printf("- %s (over by N$%.2f)\n", departmentNames[i], expenditures[i] - budgets[i]);
            numberOverBudget++;
        }
    }

    if (numberOverBudget == 0) {
        printf("None\n");
    }
}

void supplierReport(void) {
    int i;

    printf("\nSUPPLIER REPORT\n");
    if (supplierCount == 0) {
        printf("No Suppliers registered.\n");
        return;
    }

    printf("Total Suppliers: %d\n", supplierCount);
    for (i = 0; i < supplierCount; i++) {
        printf("%d. %s | %s | %s | %s\n", i + 1,
               supplier[i].suppName, supplier[i].suppEmail1,
               supplier[i].suppPhone1, supplier[i].suppTown);
    }
}

void assetReport(void) {
    int i;
    double totalValue = 0.0;

    printf("\nASSET REPORT\n");
    if (assetCount == 0) {
        printf("No assets registered.\n");
        return;
    }

    for (i = 0; i < assetCount; i++) {
        printf("%d. %s | %s | N$%.2f | %s | %s\n", i + 1,
               assets[i].name, assets[i].type, assets[i].purchaseValue,
               assets[i].department, assets[i].condition);
        totalValue += assets[i].purchaseValue;
    }

    printf("Total Assets: %d\n", assetCount);
    printf("Total Value: N$%.2f\n", totalValue);
}

            