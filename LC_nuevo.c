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
int pertenece(LC, item);
item LCValor(LC); // Devuelve el último item agregado (el de la ventana) (LC->primerNodo->sig)

int main() {
    LC * nuevaLista = ListaVacia();
    LCInsertar(nuevaLista, 'A');
    LCInsertar(nuevaLista, 'B');
    LCInsertar(nuevaLista, 'C');
    LCInsertar(nuevaLista, 'D');
    printf("Pertenece la C a la LC ? R: %d", pertenece(*nuevaLista, 'C'));
    getchar();getchar();getchar();
    return 0;
}

int pertenece(LC Lc, item x) {
    if (esLcVacia(Lc)) {
        return 0;
    } else {
        if (Lc.primerNodo->dato == x) {
            return 1;
        } else {
            LC aux = Lc;
            LCBorrar(&aux);
            pertenece(aux, x);
        }
    }
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