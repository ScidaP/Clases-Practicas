#include <stdio.h>
#include <stdlib.h>

typedef char item;
const item indefinido = '%';
const int cant = 5;

typedef struct nodo {
    struct nodo* izq;
    item raiz;
    struct nodo* der;
}*AB;

AB ABVacio();
AB armarAB(AB, item, AB);
int esABVacio(AB);
AB izquierdo(AB);
item raiz(AB);
AB derecho(AB);

int main() {
    AB arbolNuevo = armarAB(ABVacio(), 5, ABVacio());
    izquierdo(arbolNuevo);
    return 0;
}

item raiz(AB arbolBinario) {
    if (esABVacio(arbolBinario)) {
        return indefinido;
    } else {
        return arbolBinario->raiz;
    }
}

AB derecho(AB arbolBinario) {
    if (esABVacio(arbolBinario)) {
        return NULL;
    } else {
        return arbolBinario->der;
    }
}

AB izquierdo(AB arbolBinario) {
    if (esABVacio(arbolBinario)) {
        return NULL;
    } else {
        return arbolBinario->izq;
    }
}

int esABVacio(AB arbolBinario) {
    if (arbolBinario == NULL) {
        return 1;
    } else {
        return 0;
    }
}

AB armarAB(AB izq_, item raiz_, AB der_) {
    AB nuevoArbol = malloc(sizeof(struct nodo));
    nuevoArbol->izq = izq_;
    nuevoArbol->raiz = raiz_;
    nuevoArbol->der = der_;
    return nuevoArbol;
}

AB ABVacio(){
    return NULL;
}