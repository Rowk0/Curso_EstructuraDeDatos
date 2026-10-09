/**
 * @file producto.h
 * @brief Funciones relacionadas con productos
*/

#include "producto.h"

/**
 * @brief Crea la instancia de un producto
 * 
 * @param nombre Nombre del producto
 * @param precio Precio del producto
 * @param stock Stock del producto
 * @param proveedor Proveedor del producto
 * @return Producto 
*/
Producto crear_producto(char* nombre, float precio, int stock, char* proveedor){
	Producto producto;

	producto.nombre = malloc(strlen(nombre) + 1);
	strcpy(producto.nombre, nombre);

	producto.precio = precio;

	producto.stock = stock;

	producto.proveedor = malloc(strlen(proveedor) + 1);
	strcpy(producto.proveedor, proveedor);

	return producto;
}


/**
 * @brief Imprime por consola un producto
 * 
 * @param producto Instance de producto
*/
void imprimir_producto(Producto producto){
	printf("%s\n", producto.nombre);
	printf("  - Precio: %.2f\n", producto.precio);
	printf("  - Stock: %d\n", producto.stock);
	printf("  - Proveedor: %s\n", producto.proveedor);
}

/**
 * @brief Elimina un producto
 * 
 * @param producto 
*/
void eliminar_producto(Producto producto){
	free(producto.nombre);
	free(producto.proveedor);
}