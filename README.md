Franco Rodríguez

/////////////////////////////////////////////// BUSQUEDA SECUENCIAL

int busqueda_secuencial(int arr[], int n, int
x)
{
 for (int i = 0; i < n; i++) {
 if (arr[i] == x)
 return i; // encontrado
 }
 return -1; // no encontrado
}

///////////////////////////////////////////// BUSQUEDA BINARIA

int busqueda_binaria(int arr[], int n, int x) {
 int izq = 0, der = n - 1;
 while (izq <= der) {
 int med = izq + (der - izq) / 2;
 if (arr[med] == x) return med;
 else if (arr[med] < x) izq = med + 1;
 else der = med - 1;
 }
 return -1;
}

/////////////////////////////////////////// ORDENAMIENTO BURBUJA

id bubbleSort(int arr[], int n) {
 for (int i = 0; i < n-1; i++) {
 	for (int j = 0; j < n - i - 1; j++) {
 		if (arr[j] > arr[j + 1]) {
 			int temp = arr[j];
 			arr[j] = arr[j + 1];
 			arr[j + 1] = temp;
 		}
 	}
 }
}
