#ifndef ASSET_H
#define ASSET_H

#define MAX_ASSETS 100

typedef struct {
    int id;
    char name[50];
    char type[30];
    float purchaseValue;
    char department[30];
    char condition[20];
} Asset;

extern Asset assets[MAX_ASSETS];
extern int assetCount;

int readInt(const char *prompt, int min, int max);

void addAsset(void);
void displayAssets(void);
void searchAsset(void);
void assetMenu(void);

#endif