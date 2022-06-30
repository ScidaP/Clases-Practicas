#include <stdio.h>
#include <stdlib.h>

typedef int item;
const item indefinido = -9999;
const int cant = 5;
typedef struct nodo {
    struct nodo * izq;
    item dato;
    struct nodo * der;
}AB;


AB ABVacio(int);
AB * ArmarAB(AB*, item, AB*);
void resetearValores(int*,int*,int*,int*);
int encontrarMenor(int[]);
int encontrarSegundoMenor(int[], int);
int encontrarIndiceMenor(int[]);
int encontrarIndiceSegundoMenor(int[], int);

int main() {
    char valores[] = {'A', 'B', 'C', 'D', 'E'};
    int frecuencia[] = {35, 10, 25, 13, 17};  // Frecuencia de cada letra de cada 100
    AB * arboles[cant];
    for (int i = 0; i < cant; i++) {
        AB arbolIzquierdo;
        AB arbolDerecho;
        AB * arbolResultado;
        int menor = encontrarMenor(frecuencia);
        int segundomenor = encontrarSegundoMenor(frecuencia, menor);
        int indiceMenor = encontrarIndiceMenor(frecuencia);
        int indiceSegundoMenor = encontrarIndiceSegundoMenor(frecuencia, menor);
        frecuencia[indiceMenor] = menor+segundomenor;
        frecuencia[indiceSegundoMenor] = 999999;
        arbolIzquierdo = ABVacio(menor);
        arbolDerecho = ABVacio(segundomenor);
        AB * arbolResultado = ArmarAB(&arbolIzquierdo, 0, &arbolDerecho);
        arboles[i] = arbolResultado;
    }
}

int encontrarMenor(int a[]) {
    int menor = 10000;
    for (int k = 0; k < cant; k++) { // Uso este bucle para obtener la menor frecuencia
        if (a[k] < menor) {
            menor = a[k];
        }
    }
    return menor;
}

int encontrarSegundoMenor(int a[], int menor) {
    int segundoMenor = 10000;
    for (int x = 0; x < cant; x++) { // Con este bucle obtengo el segundo con menor frecuencia
        if (a[x] != menor) {
            if (a[x] < segundoMenor) {
                segundoMenor = a[x]; 
            }
        }
    }
    return segundoMenor;
}

int encontrarIndiceMenor(int a[]) {
    int menor = 10000;
    int indiceMenor;
    for (int k = 0; k < cant; k++) { // Uso este bucle para obtener la menor frecuencia
        if (a[k] < menor) {
            menor = a[k];
            indiceMenor = k;
        }
    }
    return indiceMenor;
}

int encontrarIndiceSegundoMenor(int a[], int menor) {
    int indiceMenor;
    int numeroMenor = 10000;
    for (int k = 0; k < cant; k++) { // Uso este bucle para obtener la menor frecuencia
        if (a[k] != menor) {
            if (a[k] < numeroMenor) {
                numeroMenor = a[k];
                indiceMenor = k;
            }
        }
    }
    return indiceMenor;
}

void resetearValores(int*a, int*b, int*c, int*d) {
    *a = 10000;
    *b = 0;
    *c = 10000;
    *d = 0;
}

AB * ArmarAB(AB * izq, item item1, AB * der) {
    AB * nuevoArbolBinario = (AB*)malloc(sizeof(AB));
    nuevoArbolBinario->izq = izq;
    nuevoArbolBinario->dato = item1;
    nuevoArbolBinario->der = der;
    return nuevoArbolBinario;
}

AB ABVacio(int datoNuevo) {
    AB arbolBinario;
    arbolBinario.dato = datoNuevo;
    arbolBinario.der = NULL;
    arbolBinario.izq = NULL;
    return arbolBinario;
}