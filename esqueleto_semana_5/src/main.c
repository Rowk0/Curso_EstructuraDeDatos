#include <stdio.h>
#include <string.h>
#include "producto.h"

/* COLORES ANSI */
// Estas cadenas se pueden colocar en medio de cadenas de caracteres para cambiar el color por terminal
#define RESET "\x1b[0m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"

void insertar_producto(Producto arr[], int k, char* nombre, float precio, int stock, char* proveedor);
void eliminar_arr_producto(Producto arr[]);


int main(){
	printf(BLUE"================================================================================\n");
	printf("  Programa para gestionar productos\n");
	printf("================================================================================\n"RESET);

	Producto productos[4];

	productos[0] = crear_producto("\0", 0, -1, "\0");
	productos[1] = crear_producto("\0", 0, -1, "\0");
	productos[2] = crear_producto("\0", 0, -1, "\0");
	productos[3] = crear_producto("\0", 0, -1, "\0");

	for (int i = 0; i < 4; i++)
	{
		imprimir_producto(productos[i]);
	}
	
	// Creamos productos
	printf(MAGENTA"Creando productos...\n"RESET);
	Producto a = crear_producto("Producto A", 10.0, 10, "Proveedor A");
	Producto b = crear_producto("Producto B", 20.0, 20, "Proveedor B");
	Producto c = crear_producto("Producto C", 30.0, 30, "Proveedor C");
	Producto d = crear_producto("Producto D", 40.0, 40, "Proveedor D");

	insertar_producto(productos, 2, "Confort", 1000, 3, "Franco");

	eliminar_arr_producto(productos);

	/*

	// Imprimimos productos
	printf(MAGENTA"Imprimiendo productos...\n"RESET);
	imprimir_producto(a);
	printf("\n");
	imprimir_producto(b);
	printf("\n");
	imprimir_producto(c);
	printf("\n");
	imprimir_producto(d);

	// Eliminamos productos
	printf(MAGENTA"Eliminando productos...\n"RESET);
	eliminar_producto(a);
	eliminar_producto(b);
	eliminar_producto(c);
	eliminar_producto(d);

	*/

	return 0;
}

void insertar_producto(Producto arr[], int k, char* nombre, float precio, int stock, char* proveedor)
{
	if (arr[k].stock == -1)
	{
		arr[k] = crear_producto(nombre, precio, stock, proveedor);
	}
	else
	{
		printf("Error, espacio ya ocupado");
	}
}

void eliminar_arr_producto(Producto arr[])
{
	for (int i = 0; i < 4; i++)
	{
		free(arr[i].nombre);
		free(arr[i].proveedor);
	}
}