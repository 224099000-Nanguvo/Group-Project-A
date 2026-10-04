#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "suppliers.h"
#include "assets.h"

Supplier supplier[MAX_SUPPLIERS];
int supplierCount = 0;

void addSupplier(void) {
    if (supplierCount >= MAX_SUPPLIERS) {
        printf("Supplier list is full.\n");
        return;
    }

    Supplier s = {0};
    s.suppID = supplierCount + 1;

    printf("\nSupplier Name: ");
    if (fgets(s.suppName, sizeof(s.suppName), stdin) == NULL) {
        return;
    }
    s.suppName[strcspn(s.suppName, "\n")] = '\0';

    printf("Supplier first Email: ");
    if (fgets(s.suppEmail1, sizeof(s.suppEmail1), stdin) == NULL) {
        return;
    }
    s.suppEmail1[strcspn(s.suppEmail1, "\n")] = '\0';

    printf("Supplier second optional email: ");
    if (fgets(s.suppEmail2, sizeof(s.suppEmail2), stdin) == NULL) {
        return;
    }
    s.suppEmail2[strcspn(s.suppEmail2, "\n")] = '\0';

    printf("Supplier office phone number: ");
    if (fgets(s.suppPhone1, sizeof(s.suppPhone1), stdin) == NULL) {
        return;
    }
    s.suppPhone1[strcspn(s.suppPhone1, "\n")] = '\0';

    printf("Supplier second optional phone: ");
    if (fgets(s.suppPhone2, sizeof(s.suppPhone2), stdin) == NULL) {
        return;
    }
    s.suppPhone2[strcspn(s.suppPhone2, "\n")] = '\0';

    printf("Supplier town: ");
    if (fgets(s.suppTown, sizeof(s.suppTown), stdin) == NULL) {
        return;
    }
    s.suppTown[strcspn(s.suppTown, "\n")] = '\0';

    printf("Supplier address: ");
    if (fgets(s.suppAddr, sizeof(s.suppAddr), stdin) == NULL) {
        return;
    }
    s.suppAddr[strcspn(s.suppAddr, "\n")] = '\0';

    supplier[supplierCount++] = s;
    printf("Supplier registered successfully.\n");
}

void displaySuppliers(void) {
    int i;

    if (supplierCount == 0) {
        printf("No suppliers registered.\n");
        return;
    }

    printf("\nID  Name\n");
    for (i = 0; i < supplierCount; i++) {
        printf("%d  %s\n", supplier[i].suppID, supplier[i].suppName);
    }
}

void searchSupplier(void) {
    char searchName[60];
    int i, found = 0;

    printf("\nSupplier name to search: ");
    if (fgets(searchName, sizeof(searchName), stdin) == NULL) {
        return;
    }
    searchName[strcspn(searchName, "\n")] = '\0';

    for (i = 0; i < supplierCount; i++) {
        if (strcmp(supplier[i].suppName, searchName) == 0) {
            printf("\nSupplier found:\n");
            printf("ID: %d\nName: %s\nEmail1: %s\nEmail2: %s\nPhone1: %s\nPhone2: %s\nTown: %s\nAddress: %s\n",
                   supplier[i].suppID, supplier[i].suppName, supplier[i].suppEmail1,
                   supplier[i].suppEmail2, supplier[i].suppPhone1, supplier[i].suppPhone2,
                   supplier[i].suppTown, supplier[i].suppAddr);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Supplier not registered.\n");
    }
}

void compareSuppliers(void) {
    char name1[60], name2[60];
    Supplier *s1 = NULL, *s2 = NULL;
    int i;

    printf("Enter first supplier name: ");
    if (fgets(name1, sizeof(name1), stdin) == NULL) {
        return;
    }
    name1[strcspn(name1, "\n")] = '\0';

    printf("Enter second supplier name: ");
    if (fgets(name2, sizeof(name2), stdin) == NULL) {
        return;
    }
    name2[strcspn(name2, "\n")] = '\0';

    for (i = 0; i < supplierCount; i++) {
        if (strcmp(supplier[i].suppName, name1) == 0) {
            s1 = &supplier[i];
        }
        if (strcmp(supplier[i].suppName, name2) == 0) {
            s2 = &supplier[i];
        }
    }

    if (!s1 || !s2) {
        printf("One or more suppliers were not found.\n");
        return;
    }

    printf("\n%-15s %-25s %-25s\n", "Field", "Supplier 1", "Supplier 2");
    printf("%-15s %-25d %-25d\n", "ID", s1->suppID, s2->suppID);
    printf("%-15s %-25s %-25s\n", "Name", s1->suppName, s2->suppName);
    printf("%-15s %-25s %-25s\n", "Email1", s1->suppEmail1, s2->suppEmail1);
    printf("%-15s %-25s %-25s\n", "Email2", s1->suppEmail2, s2->suppEmail2);
    printf("%-15s %-25s %-25s\n", "Phone1", s1->suppPhone1, s2->suppPhone1);
    printf("%-15s %-25s %-25s\n", "Phone2", s1->suppPhone2, s2->suppPhone2);
    printf("%-15s %-25s %-25s\n", "Town", s1->suppTown, s2->suppTown);
    printf("%-15s %-25s %-25s\n", "Address", s1->suppAddr, s2->suppAddr);
}

void supplierMenu(void) {
    int choice;

    do {
        printf("\nSupplier Management System\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Compare Suppliers\n");
        printf("5. Back\n");
        choice = readInt("Select choice: ", 1, 5);

        switch (choice) {
            case 1:
                addSupplier();
                break;
            case 2:
                displaySuppliers();
                break;
            case 3:
                searchSupplier();
                break;
            case 4:
                compareSuppliers();
                break;
            case 5:
                printf("Returning to main menu.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 5);
}

void displayMenu(void) {
    supplierMenu();
}
