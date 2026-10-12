/**
 * @file inventory.c
 * @brief Funciones relacionadas con inventarios de productos
*/
#include "inventory.h"

//==============================================================================
//        FUNCIONES RELACIONADAS CON LOS PRODUCTOS DEL INVENTARIO
//==============================================================================

Inventory inv_insert(Product P, Inventory I, InventoryElement Position) 
{
    if (I == NULL || P.name == NULL || P.provider == NULL || Position == NULL)
    {
        printf("ERROR");
        return I;
    }

    InventoryElement aux = malloc(sizeof(struct Node));

    if (aux == NULL)
    {
        printf("Error");
        return I;
    }
    
    aux->product = P;
    aux->next = Position->next;
    aux->prev = Position;

    Position->next = aux;
    aux->next->prev = aux;

    return I;
}

Inventory inv_insert_first(Product P, Inventory I)
{
    if (I == NULL || P.name == NULL || P.provider == NULL)
    {
        printf("ERROR");
        return I;
    }

    InventoryElement aux = malloc(sizeof(struct Node));

    if (aux == NULL)
    {
        printf("Error");
        return I;
    }

    aux->product = P;
    aux->next = I->next;
    aux->prev = I;

    I->next = aux;
    
    aux->next->prev = aux;

    return I;
}

Inventory inv_insert_last(Product P, Inventory I)
{
    if (I == NULL || P.name == NULL || P.provider == NULL)
    {
        printf("ERROR");
        return I;
    }

    InventoryElement aux = malloc(sizeof(struct Node));

    if (aux == NULL)
    {
        printf("Error");
        return I;
    }

    aux->product = P;
    aux->next = I;
    aux->prev = I->prev;

    I->prev->next = aux;
    I->prev = aux;

    return I;
}

Inventory inv_delete(InventoryElement Position, Inventory I)
{
    if (Position == I || Position == NULL)
    {
        printf("Error");
        return I;
    }

    prod_delete(Position->product);

    Position->prev->next = Position->next;
    Position->next->prev = Position->prev;
    free(Position);

    return I;
}

Product* inv_retrieve(InventoryElement Position, Inventory I)
{
    if (Position == I || Position == NULL)
    {
        printf("Error");
        return NULL;
    }

    return &Position->product;
}

//==============================================================================
//        FUNCIONES RELACIONADAS CON LOS ÍNDICES DEL INVENTARIO
//==============================================================================

InventoryElement inv_header(Inventory I)
{
    return I;
}

InventoryElement inv_first(Inventory I)
{
    return inv_forward(I);
}

InventoryElement inv_last(Inventory I)
{
    return inv_backward(I);
}

InventoryElement inv_forward(InventoryElement Position)
{
    return Position->next;
}

InventoryElement inv_backward(InventoryElement Position)
{
    return Position->prev;
}

//==============================================================================
//        FUNCIONES RELACIONADAS CON LA TOTALIDAD DEL INVENTARIO
//==============================================================================

void inv_destroy(Inventory I)
{
    if (I == NULL) return;

    InventoryElement elemento_actual = I->next;
    
    while (elemento_actual != I)
    {
        InventoryElement nodo_siguiente = elemento_actual->next;

        prod_delete(elemento_actual->product);

        free(elemento_actual);

        elemento_actual = nodo_siguiente;
    }

    free(I);
}

Inventory inv_make_empty(Inventory I)
{
    if (I != NULL) inv_destroy(I);

    I = malloc(sizeof(struct Node));
    I->next = I;
    I->prev = I;
    return I;
}

void inv_print(Inventory I)
{
    if (I == NULL) return;

    if (I->next == I)
    {
        printf("\nLa lista esta vacia\n");
        return;
    }

    int cant_productos = 0;

    InventoryElement elemento_actual_cant = I->next;

    while (elemento_actual_cant != I)
    {
        cant_productos++;
        
        elemento_actual_cant = elemento_actual_cant->next;
    }

    printf("\nHay %d productos\n", cant_productos);

    InventoryElement elemento_actual = I->next;

    while (elemento_actual != I)
    {
        prod_print(elemento_actual->product);
        
        elemento_actual = elemento_actual->next;
    }
}

//==============================================================================
//        FUNCIONES DE COMPROBACIÓN DE ESTADO
//==============================================================================

int inv_is_empty(Inventory I)
{
    if (I == NULL || I->next == I)
    {
        return 1; // Vacio
    }
    else
    {
        return 0; // Con elementos
    }
}

int inv_is_last(InventoryElement Position, Inventory I)
{
    if (I == NULL)
    {
        return 0;
    }
    
    if (Position == I->prev)
    {
        return 1; // El elemento es el ultimo
    }
    else
    {
        return 0;
    }
}

//==============================================================================
//        FUNCIONES DE BUSQUEDA
//==============================================================================

Product* inv_find_by_name(char* name, Inventory I)
{
    if (I == NULL || name == NULL || I->next == I)
    {
        return NULL;
    }

    InventoryElement busqueda_der = I->next;
    InventoryElement busqueda_izq = I->prev;
    int iteraciones = 0;

    while (1)
    {
        iteraciones++;

        /*Se comprueba si ambos encontraron el mismo elemento*/
        if ((strcmp(name, busqueda_der->product.name) == 0) && strcmp(name, busqueda_izq->product.name) == 0)
        {
            printf("\nSe encontro el elemento en %d iteraciones, por ambos punteros\n", iteraciones);
            return &busqueda_der->product; //Puede retornar busqueda_izq, da lo mismo
        }

        /*Derecha*/
        if (strcmp(name, busqueda_der->product.name) == 0)
        {
            printf("\nSe encontro el elemento en %d iteraciones, por el puntero de avance\n", iteraciones);
            return &busqueda_der->product;
        }

        /*Izquierda*/
        if (strcmp(name, busqueda_izq->product.name) == 0)
        {
            printf("\nSe encontró el elemento en %d iteraciones, por el puntero de retroceso\n", iteraciones);
            return &busqueda_izq->product;
        }

        /*Detener si es impar o par*/
        if (busqueda_der == busqueda_izq || busqueda_der->prev == busqueda_izq)
        {
            printf("\nElemento no encontrado\n");
            return NULL;
        }

        busqueda_der = busqueda_der->next;
        busqueda_izq = busqueda_izq->prev;
    }
}