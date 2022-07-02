#include <stdio.h>
#include <stdlib.h>

typedef char item;
const item indefinido = '@';
const int cant = 5;
typedef struct nodo {
    struct nodo * izq;
    item dato;
    struct nodo * der;
}*AB;


AB ABVacio();
AB ArmarAB(AB, item, AB);
void resetearValores(int*,int*,int*,int*);
int encontrarIndiceMenor(int[]);
int encontrarIndiceSegundoMenor(int[], int);

int main() {
    char valores[] = {'A', 'B', 'C', 'D', 'E'};
    int frecuencia[] = {35, 10, 25, 13, 17};  // Frecuencia de cada letra de cada 100
    AB arboles[cant];
    for (int k = 0; k < cant; k++) {
        arboles[k] = ArmarAB(ABVacio(), valores[k], ABVacio());
    }
    for (int i = 0; i < cant; i++) {
        int indiceMenor = encontrarIndiceMenor(frecuencia);
        int menor = frecuencia[indiceMenor];
        int indiceSegundoMenor = encontrarIndiceSegundoMenor(frecuencia, menor);
        int segundomenor = frecuencia[indiceSegundoMenor];
        frecuencia[indiceMenor] = menor+segundomenor;
        frecuencia[indiceSegundoMenor] = 999999;
        AB arbolIzquierdo = arboles[indiceMenor];
        AB arbolDerecho = arboles[indiceSegundoMenor];
        AB arbolResultado = ArmarAB(arbolIzquierdo, 0, arbolDerecho);
        arboles[indiceMenor] = arbolResultado;
    }
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

AB ArmarAB(AB izq, item item1, AB der) {
    struct nodo * nuevoArbolBinario = (struct nodo*)malloc(sizeof(struct nodo));
    nuevoArbolBinario->izq = izq;
    nuevoArbolBinario->dato = item1;
    nuevoArbolBinario->der = der;
    return nuevoArbolBinario;
}

AB ABVacio() {
    return NULL;
}