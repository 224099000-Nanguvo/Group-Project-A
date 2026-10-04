#include <stdio.h>
#include <string.h>
#include "suppliers.h"
#include <stdlib.h>


typedef struct {
int suppID;
char suppName[60];
char suppEmail1[40];
char suppEmail2[40];
char suppPhone1[15];
char suppPhone2[15];
char suppTown[30];
char suppAddr[50];
char searchName [60];


} Supplier;

Supplier suppliers[60];  
int supplierCount = 0;

int main() {
int choice;

 do {
printf("\n Supplier Management System Menu \n");
printf("==============================================================\n ");
printf("1. Add New Supplier\n");
printf("2. Search For a Registered Supplier\n");
printf("3. Compare Two Suppliers\n");
printf("4. Exit  \n");
printf("==============================================================\n ");
printf("Select choice: ");


 if (scanf("%d", &choice) != 1) {
 printf("Invalid choice.\n");
 return 1;
 }
 getchar();

  if (choice == 1) {
  Supplier s;
  s.suppID = supplierCount + 1;

 printf("\n WELCOME TO SUPPLIER REGISTRATION SECTION \n");
 printf("==============================================================\n ");
 
 
 printf("\n Supplier Name :  ");
 fgets(s.suppName, sizeof(s.suppName), stdin);
 s.suppName[strcspn(s.suppName, "\n")] = '\0';

 printf("\n Supplier first Email :  ");
 fgets(s.suppEmail1, sizeof(s.suppEmail1), stdin);
 s.suppEmail1[strcspn(s.suppEmail1, "\n")] = '\0';

printf("\n Supplier Second Optional Email : ");
fgets(s.suppEmail2, sizeof(s.suppEmail2), stdin);
s.suppEmail2[strcspn(s.suppEmail2, "\n")] = '\0';

printf("Supplier Office Phone Number ");
fgets(s.suppPhone1, sizeof(s.suppPhone1), stdin);
s.suppPhone1[strcspn(s.suppPhone1, "\n")] = '\0';

printf("Supplier Second Optional Tell/Cell Number :  ");
fgets(s.suppPhone2, sizeof(s.suppPhone2), stdin);
s.suppPhone2[strcspn(s.suppPhone2, "\n")] = '\0';

printf("Supplier Suburb / Town :  ");
fgets(s.suppTown, sizeof(s.suppTown), stdin);
s.suppTown[strcspn(s.suppTown, "\n")] = '\0';

printf("Supplier Physical Address :  ");
fgets(s.suppAddr, sizeof(s.suppAddr), stdin);
s.suppAddr[strcspn(s.suppAddr, "\n")] = '\0';


suppliers[supplierCount++] = s;

printf("==============================================================\n ");
printf("\n Continue to Register Section \n");
printf("==============================================================\n ");

 }

else

 if (choice == 2) {
 
char searchName[60];

printf("==============================================================\n ");
printf("\n Supplier Name to search: ");
printf("==============================================================\n ");
fgets(searchName, sizeof(searchName), stdin);
searchName[strcspn(searchName, "\n")] = '\0';

int found = 0;

for (int i = 0; i < supplierCount; i++) {

 if (strcmp(suppliers[i].suppName, searchName) == 0) {
 printf("\nSUPPLIER DETAILS \n");
 printf("==============================================================\n ");
 printf("ID: %d\n", suppliers[i].suppID);
 printf("Name: %s\n", suppliers[i].suppName);
 printf("Email1: %s\n", suppliers[i].suppEmail1);
printf("Email2: %s\n", suppliers[i].suppEmail2);
printf("Phone1: %s\n", suppliers[i].suppPhone1);
printf("Phone2: %s\n", suppliers[i].suppPhone2);
printf("Town: %s\n", suppliers[i].suppTown);
printf("Address: %s\n", suppliers[i].suppAddr);
printf("==============================================================\n ");
found = 1;
break;

   }
  }
if (!found) {
printf("==============================================================\n ");
printf("Supplier is Not Registered.\n");
printf("\nIf You Would like to Register Please Visit the Main Menu\n");
printf("\n Continue to Register Section  \n ");
printf("==============================================================\n ");

}
 }

else 
if (choice == 3) {
 printf("\n SUPPLIERS COMPARISON SECTION \n");
printf("==============================================================\n ");

char name1[60], name2[60];
printf("Enter first supplier name: ");
fgets(name1, sizeof(name1), stdin);
name1[strcspn(name1, "\n")] = '\0';

printf("Enter second supplier name: ");
fgets(name2, sizeof(name2), stdin);
name2[strcspn(name2, "\n")] = '\0';

Supplier *s1 = NULL, *s2 = NULL;

for (int i = 0; i < supplierCount; i++) {

if (strcmp(suppliers[i].suppName, name1) == 0) {
s1 = &suppliers[i];

  }
if (strcmp(suppliers[i].suppName, name2) == 0) {

 s2 = &suppliers[i];
 
   }
 
  }

if (s1 && s2) {


printf("\n%-15s %-25s %-25s\n", "Field", "Supplier 1", "Supplier 2");
printf("==============================================================\n ");
printf("%-15s %-25d %-25d\n", "ID", s1->suppID, s2->suppID);
printf("%-15s %-25s %-25s\n", "Name", s1->suppName, s2->suppName);
printf("%-15s %-25s %-25s\n", "Email1", s1->suppEmail1, s2->suppEmail1);
printf("%-15s %-25s %-25s\n", "Email2", s1->suppEmail2, s2->suppEmail2);
printf("%-15s %-25s %-25s\n", "Phone1", s1->suppPhone1, s2->suppPhone1);
printf("%-15s %-25s %-25s\n", "Phone2", s1->suppPhone2, s2->suppPhone2);
printf("%-15s %-25s %-25s\n", "Town", s1->suppTown, s2->suppTown);
printf("%-15s %-25s %-25s\n", "Address", s1->suppAddr, s2->suppAddr);
printf("==============================================================\n ");


 }

else {
printf("\nOne or more compared Supplier is not found in the directory.\n");
printf("\n Visit Reports Section to see registered Suppliers \n ");
printf("==============================================================\n ");

   }
   
  }
  
 } 

while (choice != 4);

printf("==============================================================\n ");
printf("You are now Exiting the Supplier Management System\n");
printf("==============================================================\n ");



   return 0;
   
   
}
