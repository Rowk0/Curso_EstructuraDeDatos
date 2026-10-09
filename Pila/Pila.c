#include <stdio.h>
#include <string.h>
#include "producto.h"
#define MAX_ARR 5

//gcc -Wall -Wextra Pila.c producto.c -o programa

typedef struct 
{
    Producto *elements;
    int k;
    int p;
} _stack;

_stack make_empty(int k);
_stack push(_stack pila, Producto p);
Producto pop(_stack pila);
void print_pila(_stack pila);

int main()
{
    _stack S = make_empty(10);
    S = push(S, crear_producto("Pepe", 10, 1, "XQC"));
    print_pila(S);
    return 0;
}

_stack make_empty(int k)
{
    _stack s;
    s.elements = malloc(sizeof(s) * k);

    return s;
}

_stack push(_stack pila, Producto p)
{
    if (pila.k == pila.p)
    {
        printf("ERROR PUSH");
    }
    
    pila.elements[pila.p] = p;
    return pila;
}

Producto pop(_stack pila)
{
    if (pila.p == 0)
    {
        printf("Stack overflow");
    }
    
    pila.p --;
    return pila.elements[pila.p];
}

void print_pila(_stack pila)
{
    for (int i = 0; i > pila.p; i++)
    {
        printf("%s", pila.elements->nombre);
    }
}