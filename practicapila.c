#include <stdlib.h>
#include <stdio.h>

typedef int item;
const item indefinido = -9999;

struct nodo {
    item dato;
    struct nodo *sig;
};

typedef struct {
    struct nodo *tope;
    int altura;
}Pila;

Pila * pilavacia();
int espilavacia(Pila*);
item top(Pila*);
Pila * pop(Pila*);
Pila * push(Pila*, item);
item fondo(Pila*);

int main() {
    Pila * nuevaPila = pilavacia();
    printf("Es pila vacia? : %d", espilavacia(nuevaPila));
    item dato1 = 2;
    item dato2 = 4;
    item dato3 = 7;
    nuevaPila = push(nuevaPila, dato1);
    nuevaPila = push(nuevaPila, dato2);
    nuevaPila = push(nuevaPila, dato3);
    printf("\nvalor del tope de la pila: %d", top(nuevaPila));
    printf("\nEs pila vacia? : %d", espilavacia(nuevaPila));
    printf("\nFondo de la pila: %d", fondo(nuevaPila));
    return 0;
}

item fondo(Pila* pila) {
    struct nodo *aux;
    aux = pila->tope;
    do {
        aux = aux->sig;
    } while (aux->sig != NULL);
    return aux->dato;
    free (aux);
}

Pila * pilavacia() {
    Pila * nuevaPila;
    nuevaPila = malloc(sizeof(Pila));
    nuevaPila->tope = NULL;
    nuevaPila->altura = 0;
    return nuevaPila;
}

int espilavacia(Pila* pila) {
    if (pila->altura == 0) {
        return 1;
    } else {
        return 0;
    }
}

item top (Pila * pila) {
    if (espilavacia(pila)) {
        return indefinido;
    } else {
        return pila->tope->dato;
    }
}

Pila * pop (Pila * pila) {
    if (espilavacia(pila)) {
        return pila;
    } else {
        struct nodo *aux = malloc(sizeof(struct nodo));
        aux = pila->tope;
        pila->tope = pila->tope->sig;
        pila->altura = pila->altura - 1;
        free(aux);
        return pila;
    }
}

Pila * push (Pila *pila, item dato) {
    struct nodo * NuevoNodo = malloc(sizeof(struct nodo));
    NuevoNodo->dato = dato; // Le asigno el nuevo dato que viene por parámetro
    NuevoNodo->sig = pila->tope;
    pila->tope = NuevoNodo;
    pila->altura = pila->altura + 1;
    return pila;
}