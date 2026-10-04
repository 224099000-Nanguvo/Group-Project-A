#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "supplier.h"
#include <stdlib.h>

Supplier suppliers[MAX_SUPPLIERS];


int supplierCount = 0;

} 

void addSupplier(void);
void viewSuppliers(void);
void searchSupplier(void);
void supplierMenu(void);

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


supplier[supplierCount++] = s;

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

void addSupplier(void)
{
    if (supplierCount >= MAX_SUPPLIERS)
    {
        printf("\nMaximum supplier limit reached!\n");
        return;
    }

    Supplier *s = &suppliers[supplierCount];

    s->suppID = supplierCount + 1;

    printf("\nEnter Supplier Name: ");
    scanf(" %[^\n]", s->suppName);

    printf("Enter Primary Email: ");
    scanf("%s", s->suppEmail1);

    printf("Enter Secondary Email: ");
    scanf("%s", s->suppEmail2);

    printf("Enter Primary Phone: ");
    scanf("%s", s->suppPhone1);

    printf("Enter Secondary Phone: ");
    scanf("%s", s->suppPhone2);

    printf("Enter Town: ");
    scanf(" %[^\n]", s->suppTown);

    printf("Enter Address: ");
    scanf(" %[^\n]", s->suppAddr);

    supplierCount++;

    printf("\nSupplier added successfully.\n");
}


void viewSuppliers(void)

{
    int i;

    if (supplierCount == 0)
    {
        printf("\nNo suppliers available.\n");
        return;
    }

    printf("\n================ SUPPLIERS ================\n");

    for (i = 0; i < supplierCount; i++)
    {
        printf("\nSupplier ID : %d\n", suppliers[i].suppID);
        printf("Name        : %s\n", suppliers[i].suppName);
        printf("Email 1     : %s\n", suppliers[i].suppEmail1);
        printf("Email 2     : %s\n", suppliers[i].suppEmail2);
        printf("Phone 1     : %s\n", suppliers[i].suppPhone1);
        printf("Phone 2     : %s\n", suppliers[i].suppPhone2);
        printf("Town        : %s\n", suppliers[i].suppTown);
        printf("Address     : %s\n", suppliers[i].suppAddr);
        printf("-------------------------------------------\n");
    }
}


void searchSupplier(void)
{
 char searchName[60];
 int i;
 int found = 0;

printf("\nEnter Supplier Name: ");
	
 scanf(" %[^\n]", searchName);

  for (i = 0; i < supplierCount; i++)
    {
        
        if (strcmp(searchName, suppliers[i].suppName) == 0)
        {
            printf("Name    : %s\n", suppliers[i].suppName);
            printf("Email   : %s\n", suppliers[i].suppEmail1);
            printf("Phone   : %s\n", suppliers[i].suppPhone1);
            printf("Town    : %s\n", suppliers[i].suppTown);
            found = 1;
            break;
        }
    }

   if (!found)
    {
        printf("\n Supplier not in DataBase .\n");
    }
}


void supplierMenu(void)
{
    int choice;

   do
    {
        printf("\n========================================\n");
        printf("      SUPPLIER MANAGEMENT SYSTEM\n");
        printf("========================================\n");
        printf("1. Add Supplier\n");
        printf("2. View Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Exit\n");
        printf("========================================\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addSupplier();
                break;

            case 2:
                viewSuppliers();
                break;

            case 3:
                searchSupplier();
                break;

            case 4:
            printf("\n Exiting Supplier Module...\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while (choice != 4);
}
