#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "product.h"

/**
 * @brief Funcion que convierte los productos en archivo csv
 * 
 * @param p representa un producto del inventario
 */
void products_to_csv(Product p[]);

int main()
{
    Product productos[5];
    char *productos_nombres[] = {"Yogurt", "Chocolate", "Leche", "Carne", "Manzana"};
    char proveedor[5];
    int precio = 0, cantidad = 0;
    int aux_proveedor = 0;

    srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {
        //Generando cantidad
        cantidad = rand() % 31; //Cantidad aleatoria de 0 a 30 elementos

        //Generando caracteres del proveedor
        for (int j = 0; j < 5; j++)
        {
            aux_proveedor = 65 + (rand() % (90 + 1 - 65));
            proveedor[j] = aux_proveedor; 
        }

        //Generando precio
        printf("Ingrese el precio de %s\n", productos_nombres[i]);

        scanf("%d", &precio);

        //Creando producto
        productos[i] = crear_producto(productos_nombres[i], precio, cantidad, proveedor);

        print_producto(productos[i]);
    }

    products_to_csv(productos);

    for (int i = 0; i < 5; i++) eliminar_producto(productos[i]);
    
    return 0;
}

void products_to_csv(Product p[])
{
    FILE *archivo;

    archivo = fopen("build/productos.csv", "w");

    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo");
        exit(1);
    }
    
    fprintf(archivo, "Nombre,Precio,Cantidad,Proveedor\n");

    for (int i = 0; i < 5; i++)
    {
        fprintf(archivo, "%s,%d,%d,%s\n", p[i].name, p[i].price, p[i].cantity, p[i].supplier);
    }
    
    fclose(archivo);
}