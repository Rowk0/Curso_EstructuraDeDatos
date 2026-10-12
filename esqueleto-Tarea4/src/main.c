#include <stdio.h>
#include <string.h>
#include "inventory.h"
#include "product.h"

int main(){

	Inventory I = NULL;
	Product *test;
	int vacio = -1;

	I = inv_make_empty(I);
	vacio = inv_is_empty(I);
	printf("\n%d\n", vacio);
	I = inv_insert_first(prod_create("Pepitolinas", 1000, 2, "SNAD"), I);
	inv_print(I);
	test = inv_find_by_name("Pepe", I);
	if (test != NULL)
	{
		printf("%s\n", test->name);
	}
	printf("=====================================================\n");
	I = inv_insert(prod_create("Galletas de Avena", 850, 15, "AlimentosSur"), I, inv_header(I));
	inv_print(I);
	printf("=====================================================\n");
	I = inv_insert_last(prod_create("Jugo de Naranja", 1200, 8, "BebidasLtda"), I);
	inv_print(I);
	printf("=====================================================\n");
	I = inv_insert(prod_create("Chocolate Amargo", 1500, 12, "SweetCorp"), I, inv_first(I));
	inv_print(I);
	printf("=====================================================\n");
	test = inv_find_by_name("Chocolate Amargo", I);
	printf("%s\n", test->name);
	printf("=====================================================\n");
	I = inv_delete(I->next, I);
	inv_print(I);
	printf("=====================================================\n");
	test = inv_find_by_name("Pepitolinas", I);
	printf("%s\n", test->name);
	printf("=====================================================\n");
	test = inv_retrieve(I->next, I);
	printf("%s\n", test->name);
	printf("=====================================================\n");
	I = inv_make_empty(I);
	inv_print(I);
	printf("=====================================================\n");
	return 0;
}
