#include <stdio.h>
#include <stdlib.h>

typedef int item;
const item indefinido=-9999;

struct nodo{
                    item dato;
                    struct nodo* siguiente;
};

typedef struct {
                      struct nodo* Frente;
                      struct nodo* Final;
} Fila;

Fila FilaVacia();
int EsFilaVacia(Fila); // Uso int pero en realidad devuelve bool
Fila EnFila(Fila, item);
item Frente(Fila);
Fila deFila(Fila);
int contarImpares(Fila);

int main(){
    Fila filaNueva = FilaVacia();
    printf("cantidad impares: %d", contarImpares(filaNueva));
    return 0;
}

int contarImpares(Fila F) {
    if (EsFilaVacia(F)) {
        return 0;
    } else {
        if (F.Frente->dato % 2 != 0) {
            return (1 + contarImpares(deFila(F)));
        } else {
            return contarImpares(deFila(F));
        }
    }
}

Fila deFila(Fila F) {
    if (EsFilaVacia(F)) {
        return F;
    } else if (F.Final == F.Frente) { // En caso que la fila tenga sólo 1 nodo
        struct nodo * aux;
        aux = F.Frente; // Apunto aux al nodo del Frente de la fila (para así poder liberar la memoria más adelante)
        F.Final = NULL;
        F.Frente = NULL;
        free(aux);
    } else {
        struct nodo * aux;
        aux = F.Frente;
        F.Frente = F.Frente->siguiente;
        free(aux);
    }
    return F;
}

item Frente(Fila F) {
    if (EsFilaVacia(F)) {
        return indefinido;
    } else {
        return F.Frente->dato;
    }
}

Fila EnFila(Fila F, item x) {
    struct nodo * nuevoNodo = (struct nodo *)malloc(sizeof(struct nodo));
    nuevoNodo->dato = x;
    nuevoNodo->siguiente = NULL;
    if (EsFilaVacia(F)) {
        F.Final = nuevoNodo;
        F.Frente = nuevoNodo;
    } else {
        F.Final->siguiente = nuevoNodo;
        F.Final = nuevoNodo;
    }
    return F;
}

int EsFilaVacia(Fila F) {
    if (F.Final == NULL) { // Con que solo el Frente o el Final sean null, ya significa que la fila es vacía.
        return 1;
    } else {
        return 0;
    }
}

Fila FilaVacia() {
    Fila F;
    F.Frente = NULL;
    F.Final = NULL;
    return F;
}