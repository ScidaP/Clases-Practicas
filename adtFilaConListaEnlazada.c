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

Fila * FilaVacia();
int EsFilaVacia(Fila); // Uso int pero en realidad devuelve bool
void EnFila(Fila*, item);
item Frente(Fila*);
void deFila(Fila*);

int main(){
    Fila * filaNueva = FilaVacia();
    printf("Frente de la fila: %d\n", Frente(filaNueva));
    printf("Es fila vacia ? : %d\n", EsFilaVacia(*filaNueva));
    EnFila(filaNueva, 5);
    printf("Frente de la fila: %d\n", Frente(filaNueva));
    printf("Es fila vacia ? : %d\n", EsFilaVacia(*filaNueva));
    EnFila(filaNueva, 15);
    EnFila(filaNueva, 25);
    printf("Frente de la fila: %d\n", Frente(filaNueva));
    deFila(filaNueva);
    printf("Frente de la fila: %d\n", Frente(filaNueva));
    getchar();
}

item Frente(Fila * F) {
    if (EsFilaVacia(*F)) {
        return indefinido;
    } else {
        return F->frente->dato;
    }
}

void EnFila(Fila * F, item x) {
    struct nodo * nuevoNodo = (struct nodo*)malloc(sizeof(struct nodo));
    nuevoNodo->dato = x;
    nuevoNodo->sig = NULL;
    if (EsFilaVacia(*F)) {
        F->final = nuevoNodo;
        F->frente = nuevoNodo;
    } else {
        F->frente->sig = nuevoNodo;
        F->frente = nuevoNodo;
    }
}

void deFila(Fila * F) {
    if (EsFilaVacia(*F)) {
        // Si es fila vacía, entonces no hay nada que hacer :)
    } else {
        if (F->final == F->frente) { // Caso en que tenga un solo item en la Fila
            free(F->frente);
            F->final = NULL;
            F->frente = NULL;
        } else { // caso en que tengo más de un item en la fila
            struct nodo * aux = F->final;
            while (aux->sig != NULL) {
                if (aux->sig == F->frente) {
                    F->frente = aux;
                    F->frente->sig = NULL;
                    break;
                }
                aux = aux->sig;
            }
        }
    }
}

int EsFilaVacia(Fila F) {
    if (F.frente == NULL) { // Con que solo el frente o el final sean null, ya significa que la fila es vacía.
        return 1;
    } else {
        return 0;
    }
}

Fila * FilaVacia() {
    Fila * nuevaFila = malloc(sizeof(Fila));
    nuevaFila->final = NULL;
    nuevaFila->frente = NULL;
    return nuevaFila;
}