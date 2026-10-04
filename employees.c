#include <stdio.h>
#include <string.h>
#include <stdlib.h> // added just incase we will need it later.
#include "employees.h"

// my employee array and count
struct Employee empList[MAX];
int count = 0;

// to clear buffer after scanf - learned from youtube
void clearBuffer(){
int c;
while((c = getchar()) != '\n' && c != EOF){
// do nothing
}
}

// calc total salary
float calcTotal(float b, float h, float t){
float result;
result = b + h + t; // basic + housing + transport
return result;
}

// add employee
void addEmp(){
// check if full
if(count >= MAX){
printf("Database full! cannot add more than %d\n", MAX);
return;
}

struct Employee e; // temp employee
char tempName[50]; // string declaration - for validation
char tempDept[30]; // string declaration

e.id = 1001 + count;
printf("\n--- Add Employee (ID: %d) ---\n", e.id);

printf("Enter name: ");
fgets(tempName, 50, stdin);
tempName[strcspn(tempName, "\n")] = 0;

// validation - empty name
while(strlen(tempName) == 0){
printf("Name cant be empty, try again: ");
fgets(tempName, 50, stdin);
tempName[strcspn(tempName, "\n")] = 0;
}
strcpy(e.name, tempName); // copy string using strcpy

printf("Enter department: ");
fgets(tempDept, 30, stdin);
tempDept[strcspn(tempDept, "\n")] = 0;

if(strlen(tempDept) == 0){
strcpy(tempDept, "General");
printf("No department entered, set to General\n");
}
strcpy(e.department, tempDept);

// basic salary
printf("Enter basic salary: ");
scanf("%f", &e.basic);
clearBuffer();

// check negative - validation
while(e.basic < 0){
printf("Negative not allowed! Enter basic again: ");
scanf("%f", &e.basic);
clearBuffer();
}

printf("Enter housing allowance: ");
scanf("%f", &e.housing);
clearBuffer();
while(e.housing < 0){
printf("Housing cant be negative: ");
scanf("%f", &e.housing);
clearBuffer();
}

printf("Enter transport allowance: ");
scanf("%f", &e.transport);
clearBuffer();
while(e.transport < 0){
printf("Transport cant be negative: ");
scanf("%f", &e.transport);
clearBuffer();
}

// calculate total
e.total = calcTotal(e.basic, e.housing, e.transport);

// save to main array
empList[count].id = e.id;
strcpy(empList[count].name, e.name);
strcpy(empList[count].department, e.department);
empList[count].basic = e.basic;
empList[count].housing = e.housing;
empList[count].transport = e.transport;
empList[count].total = e.total;

count++; // increase count

printf("Employee added! Total salary = %.2f\n", e.total);
}

// display all
void displayAll(){
int i;
if(count == 0){
printf("\nNo employees yet, please add first\n");
return;
}

printf("\nID   Name                 Dept           Basic      Housing    Trans      Total\n");
printf("----------------------------------------------------------------------\n");

for(i = 0; i < count; i++){
printf("%-4d %-20s %-12s %-9.2f %-9.2f %-9.2f %-9.2f\n",
empList[i].id,
empList[i].name,
empList[i].department,
empList[i].basic,
empList[i].housing,
empList[i].transport,
empList[i].total);
}

printf("----------------------------------------------------------------------\n");
printf("Total employees = %d\n", count);
}

// search employee
void searchEmp(){
int option;
char searchDept[30]; // string for dept search
char searchName[50]; // string for name search
char fullInfo[100]; // string for strcat
int searchId;
int i;
int found;

printf("\n--- Search Menu ---\n");
printf("1. Search by ID\n");
printf("2. Search by Department\n");
printf("3. Search by Name (partial)\n");
printf("Enter option: ");
scanf("%d", &option);
clearBuffer();

if(option == 1){
printf("Enter ID to search: ");
scanf("%d", &searchId);
clearBuffer();

found = 0;
for(i = 0; i < count; i++){
if(empList[i].id == searchId){
printf("Found: %d | %s | %s | Total: %.2f\n", empList[i].id, empList[i].name, empList[i].department, empList[i].total);
found = 1;
}
}
if(found == 0){
printf("No employee with ID %d\n", searchId);
}
}
else if(option == 2){
printf("Enter department name: ");
fgets(searchDept, 30, stdin);
searchDept[strcspn(searchDept, "\n")] = 0;

found = 0;
for(i = 0; i < count; i++){
if(strcmp(empList[i].department, searchDept) == 0){ // using strcmp
printf("%d - %s - %.2f\n", empList[i].id, empList[i].name, empList[i].total);
found = 1;
}
}
if(found == 0){
printf("No employees in %s department\n", searchDept);
}
}
else if(option == 3){
printf("Enter name keyword: ");
fgets(searchName, 50, stdin);
searchName[strcspn(searchName, "\n")] = 0;

found = 0;
for(i = 0; i < count; i++){
if(strstr(empList[i].name, searchName) != NULL){ // partial search using strstr
// building string using strcpy and strcat
strcpy(fullInfo, empList[i].name);
strcat(fullInfo, " - ");
strcat(fullInfo, empList[i].department);
printf("%s => Total: %.2f\n", fullInfo, empList[i].total);
found = 1;
}
}
if(found == 0){
printf("No match for %s\n", searchName);
}
}
else{
printf("Invalid search option!\n");
}
}

// main menu for this module
void employeeMenu(){
int choice;
int id;
int i;
int ok;

do{
printf("\n==============================\n");
printf(" EMPLOYEE MANAGEMENT\n");
printf("==============================\n");
printf("1. Add Employee\n");
printf("2. Display All Employees\n");
printf("3. Search Employee\n");
printf("4. Show Salary Breakdown\n");
printf("5. Display Relevant Info\n");
printf("0. Back\n");
printf("==============================\n");
printf("Enter your choice: ");
scanf("%d", &choice);
clearBuffer();

switch(choice){
case 1:
addEmp();
break;
case 2:
displayAll();
break;
case 3:
searchEmp();
break;
case 4:
if(count == 0){
printf("No employees added yet\n");
break;
}
printf("Enter employee ID for breakdown: ");
scanf("%d", &id);
clearBuffer();

ok = 0;
for(i = 0; i < count; i++){
if(empList[i].id == id){
printf("\n--- Salary Breakdown for %s ---\n", empList[i].name);
printf("Basic Salary: %.2f\n", empList[i].basic);
printf("Housing Allowance: %.2f\n", empList[i].housing);
printf("Transport Allowance: %.2f\n", empList[i].transport);
printf("TOTAL: %.2f\n", empList[i].total);
ok = 1;
}
}
if(ok == 0){
printf("ID %d not found\n", id);
}
break;
case 5:
displayAll();
break;
case 0:
printf("Going back to main menu...\n");
break;
default:
printf("Invalid choice! Please enter 0-5 only\n");
break;
}

}while(choice != 0);
}