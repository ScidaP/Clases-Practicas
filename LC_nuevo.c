#include <stdio.h>
#include <stdlib.h>

#define indefinido -9999
typedef char item;
struct nodo {
    item dato;
    struct nodo* sig;
};

typedef struct ListaCircular {
    struct nodo* primerNodo;
}LC;

LC * ListaVacia();
int esLcVacia(LC);
void LCInsertar(LC*, item);
void LCBorrar(LC*); // Borra el último item agregado
void LCRotar(LC*);

int main() {
    LC * nuevaLista = ListaVacia();
    LCInsertar(nuevaLista, 'A');
    LCInsertar(nuevaLista, 'B');
    LCInsertar(nuevaLista, 'C');
    LCInsertar(nuevaLista, 'D');
    LCRotar(nuevaLista);
    getchar();getchar();getchar();
    return 0;
}

void LCRotar(LC * Lc) {
    Lc->primerNodo = Lc->primerNodo->sig;
}

void LCBorrar(LC * Lc) {
    if (!esLcVacia(*Lc)) {
        struct nodo * aux = Lc->primerNodo->sig;
        Lc->primerNodo->sig = aux->sig;
        free(aux);
    }
}

void LCInsertar(LC * Lc, item datoNuevo) {
    if (esLcVacia(*Lc)) {
        struct nodo * nuevoNodo = malloc(sizeof(struct nodo));
        nuevoNodo->dato = datoNuevo;
        nuevoNodo->sig = nuevoNodo;
        Lc->primerNodo = nuevoNodo;
    } else { 
        struct nodo * nuevoNodo = malloc(sizeof(struct nodo));
        nuevoNodo->dato = datoNuevo;
        nuevoNodo->sig = Lc->primerNodo->sig;
        Lc->primerNodo->sig = nuevoNodo;
    }
}

int esLcVacia(LC Lc) {
    if (Lc.primerNodo == NULL) {
        return 1;
    } else {
        return 0;
    }
}

LC * ListaVacia() {
    LC * nuevaListaCircular = malloc(sizeof(LC));
    nuevaListaCircular->primerNodo = NULL;
    return nuevaListaCircular;
}