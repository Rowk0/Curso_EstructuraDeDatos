/**
 * @file producto.h
 * @brief Cabecera para funciones relacionadas con productos
*/

#ifndef PRODUCT_H
#define PRODUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Estructura que representa un producto
 * 
*/
typedef struct _Product {
	char* nombre; /**< Nombre del producto */
	float precio; /**< Precio del producto */
	int stock; /**< Stock del producto */
	char* proveedor; /**< Proveedor del producto */
} Producto;	

Producto crear_producto(char* nombre, float precio, int stock, char* proveedor);
void imprimir_producto(Producto producto);
void eliminar_producto(Producto producto);

#endif