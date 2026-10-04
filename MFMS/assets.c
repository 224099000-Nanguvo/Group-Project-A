#include <stdio.h>
#include <string.h>
#include "assets.h"

Asset assets[MAX_ASSETS];
int assetCount = 0;

int readInt(const char *prompt, int min, int max) {
    int value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &value) == 1 && value >= min && value <= max) {
            while (getchar() != '\n') {
            }
            return value;
        }
        while (getchar() != '\n') {
        }
        printf("Invalid input. Enter a number from %d to %d.\n", min, max);
    }
}

void addAsset(void) {
    Asset a;
    int i;

    if (assetCount >= MAX_ASSETS) {
        printf("Asset register is full.\n");
        return;
    }

    a.id = readInt("Asset ID: ", 1, 999999);
    for (i = 0; i < assetCount; i++) {
        if (assets[i].id == a.id) {
            printf("That ID already exists.\n");
            return;
        }
    }

    printf("Asset name: ");
    if (fgets(a.name, sizeof(a.name), stdin) == NULL) {
        return;
    }
    a.name[strcspn(a.name, "\n")] = '\0';

    printf("Asset type: ");
    if (fgets(a.type, sizeof(a.type), stdin) == NULL) {
        return;
    }
    a.type[strcspn(a.type, "\n")] = '\0';

    do {
        printf("Purchase value: ");
        if (scanf("%f", &a.purchaseValue) != 1) {
            while (getchar() != '\n') {
            }
            a.purchaseValue = -1;
        }
        while (getchar() != '\n') {
        }
    } while (a.purchaseValue <= 0);

    printf("Department: ");
    if (fgets(a.department, sizeof(a.department), stdin) == NULL) {
        return;
    }
    a.department[strcspn(a.department, "\n")] = '\0';

    printf("Condition: ");
    if (fgets(a.condition, sizeof(a.condition), stdin) == NULL) {
        return;
    }
    a.condition[strcspn(a.condition, "\n")] = '\0';

    assets[assetCount++] = a;
    printf("Asset added.\n");
}

void displayAsset(void) {
    int i;

    if (assetCount == 0) {
        printf("No assets recorded.\n");
        return;
    }

    printf("%-6s %-20s %-12s %-12s %-15s %-10s\n", "ID", "Name", "Type", "Value", "Department", "Condition");
    for (i = 0; i < assetCount; i++) {
        printf("%-6d %-20s %-12s %-12.2f %-15s %-10s\n",
               assets[i].id, assets[i].name, assets[i].type, assets[i].purchaseValue,
               assets[i].department, assets[i].condition);
    }
}

void displayAssets(void) {
    displayAsset();
}

void searchAsset(void) {
    int id = readInt("Enter Asset ID to search: ", 1, 999999);
    int i;

    for (i = 0; i < assetCount; i++) {
        if (assets[i].id == id) {
            printf("Found: %s (%s), %.2f, %s, %s\n",
                   assets[i].name, assets[i].type, assets[i].purchaseValue,
                   assets[i].department, assets[i].condition);
            return;
        }
    }
    printf("Asset not found.\n");
}

void assetMenu(void) {
    int choice;

    do {
        printf("\n--- ASSET MANAGEMENT ---\n");
        printf("1. Add asset\n2. Display assets\n3. Search asset\n4. Back\n");
        choice = readInt("Enter your choice: ", 1, 4);

        switch (choice) {
            case 1:
                addAsset();
                break;
            case 2:
                displayAsset();
                break;
            case 3:
                searchAsset();
                break;
            case 4:
                printf("Returning to main menu.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);
}
