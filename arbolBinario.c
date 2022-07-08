#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int EsABVacio(AB); // Bool
int Pertenece(AB, item); // Bool
void inorden(AB);
AB izquierdo(AB);
AB derecho(AB);
item raiz(AB);

int main() {
    AB arbolVacio = ABVacio();
    izquierdo(arbolVacio);
    getchar();getchar();getchar();getchar();
    return 0;
}

item raiz(AB arbolBinario) {
    if (EsABVacio(arbolBinario)) {
        return indefinido;
    } else {
        return arbolBinario->dato;
    }
}

AB derecho(AB arbolBinario) {
    return arbolBinario->der;
}

AB izquierdo(AB arbolBinario) {
    return arbolBinario->izq;
}

void inorden(AB arbol) {
    if (!EsABVacio(arbol)) {
        inorden(arbol->izq);
        printf("%c ", arbol->dato);
        inorden(arbol->der);
    }
}

int EsABVacio(AB arbolBinario) {
    if (arbolBinario == NULL) {
        return 1;
    } else {
        return 0;
    }
}

AB ArmarAB(AB izq, item item1, AB der) {
    AB nuevoArbolBinario = (AB)malloc(sizeof(struct nodo));
    nuevoArbolBinario->izq = izq;
    nuevoArbolBinario->dato = item1;
    nuevoArbolBinario->der = der;
    return nuevoArbolBinario;
}

AB ABVacio() {
    return NULL;
}