#ifndef PRODUCT
#define PRODUCT
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _product
{
    char *name;
    int price;
    int cantity;
    char *supplier;
} Product;

Product crear_producto(char *name, int price, int cantity, char *supplier);
void print_producto(Product p);
void eliminar_producto(Product p);

#endif