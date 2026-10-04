#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 60

typedef struct
{
    int suppID;
    char suppName[60];
    char suppEmail1[40];
    char suppEmail2[40];
    char suppPhone1[15];
    char suppPhone2[15];
    char suppTown[30];
    char suppAddr[50];
    
} Supplier;

extern Supplier suppliers[MAX_SUPPLIERS];.

extern Supplier supplier[MAX_SUPPLIERS];
extern int supplierCount;

void addSupplier(void);
void viewSuppliers(void);
void searchSupplier(void);
void supplierMenu(void);

#endif