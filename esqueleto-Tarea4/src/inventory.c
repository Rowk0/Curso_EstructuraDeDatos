/**
 * @file inventory.c
 * @brief Funciones relacionadas con inventarios de productos
*/
#include "inventory.h"


//==============================================================================
//        FUNCIONES RELACIONADAS CON LOS PRODUCTOS DEL INVENTARIO
//==============================================================================

/**
 * @brief Inserta un producto en el inventario, justo después de una posición
 *
 * El inventario pasa a ser el dueño de los strings del producto. Si la
 * inserción falla (producto inválido, es decir, con name o provider en NULL,
 * o falta de memoria) se imprime "Error", el inventario queda intacto y el
 * producto sigue siendo responsabilidad de quien llama. La posición puede ser
 * la cabecera.
 */
Inventory inv_insert(Product P, Inventory I, InventoryElement Position)
{
    InventoryElement aux = malloc(sizeof(struct Node));

    aux->next = Position->next;
    aux->prev = Position;
    Position->next = aux;
    aux->next->prev = aux;
}

//REVISAR

/**
 * @brief Elimina del inventario el producto que se encuentra en una posición
 *
 * Se libera la memoria del producto y del nodo. La cabecera del inventario no
 * contiene un producto real, por lo que no se puede eliminar con esta
 * función: se imprime "Error" y no se hace nada.
 */
Inventory inv_delete(InventoryElement Position, Inventory I)
{
    prod_delete(Position->product);

    Position->prev->next = Position->next;
    Position->next->prev = Position->prev;
    free(Position);
}

//REVISAR

//==============================================================================
//        FUNCIONES RELACIONADAS CON LOS ÍNDICES DEL INVENTARIO
//==============================================================================

/**
 * @brief Devuelve la cabecera del inventario
 */
InventoryElement inv_header(Inventory I)
{
    return I;
}

/**
 * @brief Devuelve el primer elemento del inventario
 *
 * Si el inventario está vacío se retorna la cabecera.
 */
InventoryElement inv_first(Inventory I)
{
    return inv_forward(I);
}

/**
 * @brief Devuelve el último elemento del inventario
 *
 * Si el inventario está vacío se retorna la cabecera.
 */
InventoryElement inv_last(Inventory I)
{
    return inv_backward(I);
}

/**
 * @brief Devuelve el elemento siguiente del inventario
 */
InventoryElement inv_forward(InventoryElement Position)
{
    return Position->next;
}

/**
 * @brief Devuelve el elemento anterior del inventario
 */
InventoryElement inv_backward(InventoryElement Position)
{
    return Position->prev;
}

//==============================================================================
//        FUNCIONES RELACIONADAS CON LA TOTALIDAD DEL INVENTARIO
//==============================================================================

/**
 * @brief Crea un inventario vacío o vacía uno ya existente
 *
 * Si no hay memoria disponible se imprime "Error" y se retorna un puntero
 * nulo.
 *
 * @warning Si I no es NULL, el inventario se destruye (se libera I y todos sus
 * elementos) y se crea uno nuevo. Cualquier otra referencia al inventario
 * anterior queda inválida, por lo que se debe usar siempre el valor retornado.
 * Si I no está inicializado (ni es NULL ni apunta a un inventario válido) el
 * comportamiento es indefinido.
 */
Inventory inv_make_empty(Inventory I)
{
    if (I == NULL) printf("La lista no está vacia");

    I = malloc(sizeof(struct Node));
    I->next = I;
    I->prev = I;
    return I;
}

//==============================================================================
//        FUNCIONES DE COMPROBACIÓN DE ESTADO
//==============================================================================


//==============================================================================
//        FUNCIONES DE BUSQUEDA
//==============================================================================
