#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define indefinido -9999
typedef int item;
struct nodo {
    item dato;
    struct nodo* sig;
};

typedef struct Fila {
    struct nodo* frente;
    struct nodo* final;
}Fila;

Fila FilaVacia();
int EsFilaVacia(Fila); // Uso int pero en realidad devuelve bool
Fila EnFila(Fila, item);
item Frente(Fila);
Fila deFila(Fila);

Fila deFila(Fila F) {
    if (EsFilaVacia(F)) {
        return F;
    } else if (F.final == F.frente) { // En caso que la fila tenga sólo 1 nodo
        struct nodo * aux;
        aux = F.frente; // Apunto aux al nodo del frente de la fila (para así poder liberar la memoria más adelante)
        F.final = NULL;
        F.frente = NULL;
        free(aux);
    } else {
        struct nodo * aux;
        aux = F.frente;
        F.frente = F.frente->sig;
        free(aux);
    }
    return F;
}

item Frente(Fila F) {
    if (EsFilaVacia(F)) {
        return indefinido;
    } else {
        return F.frente->dato;
    }
}

Fila EnFila(Fila F, item x) {
    struct nodo * nuevoNodo = (struct nodo *)malloc(sizeof(struct nodo));
    nuevoNodo->dato = x;
    nuevoNodo->sig = NULL;
    if (EsFilaVacia(F)) {
        F.final = nuevoNodo;
        F.frente = nuevoNodo;
    } else {
        F.final->sig = nuevoNodo;
        F.final = nuevoNodo;
    }
    return F;
}

int EsFilaVacia(Fila F) {
    if (F.final == NULL) { // Con que solo el frente o el final sean null, ya significa que la fila es vacía.
        return 1;
    } else {
        return 0;
    }
}

Fila FilaVacia() {
    Fila F;
    F.frente = NULL;
    F.final = NULL;
    return F;
}