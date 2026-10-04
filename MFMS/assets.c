#include <stdio.h>
#include <string.h>
#include "assets.h"

Asset assets[MAX_ASSETS];
int assetCount = 0;

Asset assets[MAX_ASSETS];
int assetCount = 0;

int readint(const char *prompt, int min, int max) {
    int value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &value) == 1 && value >= min && value <= max) {
            while (getchar() != '\n');
            return value;
        }
        while (getchar() != '\n');
        printf("Invalid input. Enter a number from %d to %d.\n", min, max);
    }
}

void addAsset(void) {
    if (assetCount >= MAX_ASSETS) {
        printf("Asset register is full.\n");
        return;
    }
    Asset a;
    a.id = readint("Asset ID:", 1, 999999);
    for (int i = 0; i < assetCount; i++) {
        if (assets[i].id == a.id) {
            printf("That ID already exists.\n");
            return;
        }
    }
    printf("Asset name:");
    fgets(a.name, sizeof a.name, stdin);
    a.name[strcspn(a.name, "\n")] = '\0';
    printf("Asset type (Vehicle/Computer/Building/Equipment/Furniture):");
    fgets(a.type, sizeof a.type, stdin);
    a.type[strcspn(a.type, "\n")] = '\0';
    do {
        printf("Purchase value:");
        while (scanf("%f", &a.purchaseValue) != 1)
            {
                while (getchar() != '\n');
                printf("Invalid. Purchase value:");
            }
        while (getchar() !='\n');
    }
        while (a.purchaseValue <= 0);
    printf("Department:");
    fgets(a.department, sizeof a.department, stdin);
    a.department[strcspn(a.department, "\n")] = '\0';
    printf("Condition (Good/Fair/Poor):");
    fgets(a.condition, sizeof a.condition, stdin);
    a.condition[strcspn(a.condition, "\n")] = '\0';

        assets[assetCount++] =a;
        printf("Asset added.\n");
       
} 
void displayAsset(void) {
    if (assetCount == 0) { printf("No assets recorded.\n"); return;}
    printf("%-6s %-20s %-12s %-12s %-15s %-10s\n", "ID", "Name", "Type", "Value", "Department", "Condition");
    for (int i = 0; i < assetCount; i++)
        printf("%-6d %-20s %-12s %-12.2f %-15s %-10s\n", assets[i].id, assets[i].name, assets[i].type, assets[i].purchaseValue, assets[i].department, assets[i].condition);
}

void searchAsset(void) {
    int id = readint("Enter Asset ID to search:", 1, 999999);
    for (int i = 0; i < assetCount; i++) {
        if (assets[i].id == id) {
            printf("Found: %s (%s), %.2f, %s, %s\n", assets[i].name, assets[i].type, assets[i].purchaseValue, assets[i].department, assets[i].condition);
            return;
        }
    }
    printf("Asset not found.\n");
}

void assetMenu(void) {
    int choice;
    do {
        printf("\n--- ASSET MANAGEMENT ---\n1. Add asset\n2. Display assets\n3. Search asset\n4. Back\n");
        choice = readint("Enter your choice:", 1, 4);
        switch (choice) {
            case 1: addAsset(); break;
            case 2: displayAsset(); break;
            case 3: searchAsset(); break;
        }
    }
        while (choice != 4);
}

int main(void) {
    int choice;
    do {
        printf("\n====================================\n");
        printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
        printf("====================================\n");
        printf("1. Employment Management\n2. Budget Management\n3. Supplier Management\n");
        printf("4. Asset Management\n5. Reports\n6. Exit\n");
        choice = readint("Enter your choice:", 1, 6);
        switch (choice) {
            case 4: assetMenu(); break;
            case 1: case 2: case 3: case 5: printf("Module coming soon.\n"); break;
        }
    }
        while (choice != 6);
        printf("Goodbye.\n");
        return 0;
}