#include <stdio.h>
#include <stdlib.h>

typedef int item;
const item indefinido = -9999;
typedef struct nodo {
    struct nodo * izq;
    item dato;
    struct nodo * der;
}AB;


AB ABVacio();
AB * ArmarAB(AB*, item, AB*);

int main() {
    AB nodoIzq = ABVacio();
    AB nodoDer = ABVacio();
    AB * arbolBinario = ArmarAB(&nodoIzq, 5, &nodoDer);
    getchar();getchar();getchar();getchar();
    return 0;
}

AB * ArmarAB(AB * izq, item item1, AB * der) {
    AB * nuevoArbolBinario = (AB*)malloc(sizeof(AB));
    nuevoArbolBinario->izq = izq;
    nuevoArbolBinario->dato = item1;
    nuevoArbolBinario->der = der;
    return nuevoArbolBinario;
}

AB ABVacio() {
    AB arbolBinario;
    arbolBinario.dato = indefinido;
    arbolBinario.der = NULL;
    arbolBinario.izq = NULL;
    return arbolBinario;
}