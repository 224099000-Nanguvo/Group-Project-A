#include <stdio.h>
#include <string.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "utils.h"

///Reports require other modules to show///

void reportsMenu() { 
    
    int choice;

do { 
    printf("\nREPORTS\n"); 
    printf("1. Employee Report\n"); 
    printf("2. Budget report\n"); 
    printf("3.Supplier report\n"); 
    printf("4. Asset report\n"); 
    printf("5.Return to main menu\n"); 
    choice = readInt("Enter choice: ", 1, 5);

///Select choice or report /// 
if(choice == 1) { 
    employeeReport(); 

 } else if(choice == 2) { 
    budgetReport(); 

 } else if(choice == 3) { 
    supplierReport(); 

 } else if(choice == 4) { 
    assetReport();
 } 
} while(choice != 5);

}

void employeeReport() 
{ int i; 
    double sumOfSalaries; 
    double highestSalary; 
    double lowestSalary; 
    double averageSalary;

printf("\nEMPLOYEE REPORT\n");

///If no one is on list no calculations can take place///
if(employeeCount == 0) { 
    printf("No employees registered.\n"); 
    return;

}

///We assume the first employee is both hightest and lowest/// 
sumOfSalaries = 0; 
highestSalary = employees[0].basicSalary; 
lowestSalary = employees[0].basicSalary;

for(i=0;i<employeeCount;i = i +1) { 
    sumOfSalaries = sumOfSalaries + employees[i].basicSalary;

///Salary becomes highest if it is bigger/// 
if(employees[i].basicSalary > highestSalary) { 
    highestSalary = employees[i].basicSalary; }

///Salary becomes lowest if it is smaller/// 
if(employees[i].basicSalary < lowestSalary) { 
    lowestSalary = employees[i].basicSalary; }

}

averageSalary = sumOfSalaries / employeeCount; 
printf("Total number of employees: %d\n", employeeCount); 
printf("Average salary: N$%.2f\n", averageSalary); 
printf("Highest salary: N$%.2f\n", highestSalary); 
printf("Lowest salary: N$%.2f\n", lowestSalary);

}

void budgetReport() { 
    int i; 
    double totalAllocated; 
    double totalSpent; 
    double totalRemaining; 
    int numberOverBudget;

printf("\nBUDGET REPORT\n");

if(budgetCount == 0)
{
    printf("Zero budgets registered.\n");
    return;
}
///All allocated amounts and spending for departments/// 

totalAllocated = 0; totalSpent = 0;

for(i=0;i<budgetCount;i = i + 1) { 
    totalAllocated = totalAllocated + budget[i].allocated; 
    totalSpent = totalSpent + budget[i].spent;

}

totalRemaining = totalAllocated - totalSpent;

printf("Total Allocated budget: N$%.2f\n", totalAllocated); 
printf("Total Spent budget: N$%.2f\n", totalSpent); 
printf("Total Remaining budget: N$%.2f\n", totalRemaining);

///Go through the list again and show any department that over spent/// 
printf("Departments that spent over budget:\n"); 

numberOverBudget = 0;

///String will collect all over-budget department in one line/// 

char overBudgetList[500];
overBudgetList[0] = '\0';

////start empty so strcat has nothing to hold onto///

for(i=0;i<budgetCount;i = i + 1) { 
    if(budget[i].spent > budget[i].allocated) { 
        printf("- %s(over by N$%.2f)\n", budget[i].department, budget[i].spent - budget[i].allocated);

///Adding departments names to summary string we are building/// 
if(numberOverBudget == 0) strcpy(overBudgetList,budget[i].department); 
else { strcat(overBudgetList,", "); 
    strcat(overBudgetList,budget[i].department); 
}

numberOverBudget = numberOverBudget + 1; } 
}

///If nothing is displayed, no one went over-budget/// 
if(numberOverBudget == 0) { 
    printf("None\n"); 
} 
    else { printf("Summary of Departments over budget: %s\n",overBudgetList); }

}

void supplierReport() { 
    int i; 
    printf("\nSUPPLIER REPORT\n"); 
    if(supplierCount == 0) { 
        printf("No Suppliers registered.\n"); 
        return; 
    }

printf("Total Suppliers: %d\n", supplierCount);

for(i=0;i<supplierCount;i = i + 1)
{
    printf("%d. %s | %s | %s |%s\n",i + 1, suppliers[i].name,suppliers[i].email,suppliers[i].cellNumber,suppliers[i].town);

}

}

void assetReport() {
    int i;
    double totalValue;
    printf("\nASSET Report\n");
    if(assetCount == 0) 
    {
        printf("No assets registered.\n");
        return;
    }

        totalValue = 0;
        for(i = 0;i < assetCount; i++) 
        {
            printf("%d. %s | %s | N$%.2f | %s | %s\n", i + 1,assets[i].name,
                assets[i].type, assets[i].value, assets[i].department,assets[i].condition);

                totalValue = totalValue + assets[i].value;
            }

                printf("Total Assets: %d\n", assetCount);
                printf("Total Value: N$%.2f\n", totalValue);
            }
            
            