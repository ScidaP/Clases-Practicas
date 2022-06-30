#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "adtFilaListaEnlazada.h"

const int cant = 10;
const int base = 3; // Numeros de 3 dígitos

void Radix(int[]);
void guardarArreglo(int[], Fila[]);

int main() {
    int arreglo[] = {255, 812, 412, 994, 675, 342, 988, 119, 716, 476};
    Radix(arreglo);
    return 0;
}

void Radix(int a[]) {
    // Creo el arreglo de filas
    Fila arregloSort[10];
    for (int x = 0; x < cant; x++) {
        arregloSort[x] = FilaVacia();
    }

    int aux, m=0;
    for (int i=0; i < base; i++) {
        for (int j=0; j < cant; j++) {
            aux = (int)(a[j]/pow(10, i)) % 10;
            arregloSort[aux] = EnFila(arregloSort[aux], a[j]);
        }
        guardarArreglo(&a, arregloSort);
    }
    //Imprimo el resultado
    printf("ARREGLO ORDENADO: \n");
    for (int p = 0; p < cant; p++) {
        printf("%d - ", arregloSort[p].frente->dato);
    }
    getchar();getchar();
}

void guardarArreglo(int a[], Fila sort[]) {
    for (int i = 0; i < cant; i++) {
        if (Frente(sort[i]) != NULL) {
            a[i] = Frente(sort[i]);
        }
    }
}