#include "product.h"

Product crear_producto(char *name, int price, int cantity, char *supplier)
{
    Product p;

    p.name = (char*)malloc(strlen(name) + 1);

    if (p.name == NULL)
    {
        printf("Error al registrar el nombre");
        exit(1);
    }

    strcpy(p.name, name);

    if (price < 0) price = 0;
    p.price = price;

    if (cantity <= 0) cantity = 0;
    p.cantity = cantity;

    p.supplier = (char*)malloc(strlen(supplier) + 1);
    
    if (p.supplier == NULL)
    {
        printf("Error al registrar el proveedor");
        exit(1);
    }
    
    strcpy(p.supplier, supplier);

    return p;
}

void print_producto(Product p)
{
    printf("Nombre: %s\n", p.name);
    printf("Precio: %d\n", p.price);
    printf("Cantidad: %d\n", p.cantity);
    printf("Proveedor: %s\n", p.supplier);
}

void eliminar_producto(Product p)
{
    free(p.name);
    free(p.supplier);
}