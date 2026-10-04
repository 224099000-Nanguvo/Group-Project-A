#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX_SUPPLIERS 60

typedef struct {

    
    int suppID;
    char suppName[60];
    char suppEmail1[40];
    char suppEmail2[40];
    char suppPhone1[15];
    char suppPhone2[15];
    char suppTown[30];
    char suppAddr[50];
    char searchName[60];


} Supplier;


extern Supplier suppliers[MAX_SUPPLIERS];
extern int supplierCount;


void addSupplier(void);
void searchSupplier(void);
void compareSuppliers(void);
void displayMenu(void);


#endif