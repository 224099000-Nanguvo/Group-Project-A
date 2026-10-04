#include <stdio.h>
#include "budget.h"
#include <string.h>

char departmentNames[15][60];
double budgets[15];
double expenditures[15];
int departmentCount = 0;

double calculateBudget(double budget, double expenditure){
    return budget - expenditure;
}

void addBudget(){
    if (departmentCount < 10){
        printf("\nEnter department name: ");
        fgets(departmentNames[departmentCount], 50, stdin);                                                          
        departmentNames[departmentCount][strcspn(departmentNames[departmentCount],"\n")] = '\0';    

        do{
            printf("Enter allocated budget: N$ ");
            scanf("%lf", &budgets[departmentCount]);

            if (budgets[departmentCount] < 0){
                printf("Budget cannot be negative.\n");
            }

        } while (budgets[departmentCount] < 0);

        do{
            printf("Enter expenditure: N$ ");
            scanf("%lf", &expenditures[departmentCount]);

            if (expenditures[departmentCount] < 0){
                printf("Expenditure cannot be negative.\n");
            }

        } while (expenditures[departmentCount] < 0);

        departmentCount++;

        printf("\nBudget information added successfully.\n");
    }
    else{
        printf("\nMaximum number of departments reached.\n");
    }
}
void displayBudgets(){
    int i;
    double remaining;

    if (departmentCount == 0){
        printf("\nNo budget information has been entered.\n");
    }
    else{
        printf("\n========== BUDGET INFORMATION ==========\n");
        for (i = 0; i < departmentCount; i++){
            remaining = calculateBudget(budgets[i], expenditures[i]);

            printf("\nDepartment: %s\n", departmentNames[i]);
            printf("Allocated Budget: N$ %.2f\n", budgets[i]);
            printf("Expenditure: N$ %.2f\n", expenditures[i]);
            printf("Remaining Budget: N$ %.2f\n", remaining);

            if (expenditures[i] <= budgets[i]){
                printf("Status: WITHIN THE BUDGET\n");
            }
            else{
                printf("Status: EXCEEDED BUDGET\n");
            }
        }
    }
}

void displayBudgetReport(){
    int i;
    double totalBudget = 0;
    double totalExpenditure = 0;
    double remainingBudget;
    double averageBudget;

    if (departmentCount == 0){
        printf("\nNo budget information has been entered.\n");
    }
    else{
        for (i = 0; i < departmentCount; i++){
            totalBudget = totalBudget + budgets[i];
            totalExpenditure = totalExpenditure + expenditures[i];
        }

        remainingBudget = totalBudget - totalExpenditure;
        averageBudget = totalBudget / departmentCount;

        printf("\n================= BUDGET REPORT ==================\n");
        printf("Total Allocated Budget: N$ %.2f\n", totalBudget);
        printf("Total Expenditure: N$ %.2f\n", totalExpenditure);
        printf("Remaining Budget: N$ %.2f\n", remainingBudget);
        printf("Average Department Budget: N$ %.2f\n", averageBudget);
        printf("\nDepartments Exceeding Budget:\n");

        for (i = 0; i < departmentCount; i++){
            if (expenditures[i] > budgets[i])
            {
                printf("- %s\n", departmentNames[i]);
            }
        }
    }
}

void budgetMenu(){
    int choice;

    do
    {
        printf("\n================ BUDGET MANAGEMENT ==============\n");
        printf("1. Enter Department Budget\n");
        printf("2. Display Budget Information\n");
        printf("3. Budget Report\n");
        printf("4. Return to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1){
            addBudget();
        }
        else if (choice == 2){
            displayBudgets();
        }
        else if (choice == 3){
            displayBudgetReport();
        }
        else if (choice == 4){
            printf("\nReturning to Main Menu...\n");
        }
        else{
            printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 4);