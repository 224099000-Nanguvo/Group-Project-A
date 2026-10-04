#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "suppliers.h"

Supplier suppliers[MAX_SUPPLIERS];


int supplierCount = 0;


void addSupplier(void);
void viewSuppliers(void);
void searchSupplier(void);
void supplierMenu(void);


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
