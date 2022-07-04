#include <stdio.h>
#include <stdlib.h>

typedef int item;
const int indefinido = -9999;

struct nodo {
    item dato;
    struct nodo * sig;
};

typedef struct {
    struct nodo * tope;
    int altura;
} Pila;

Pila * pilaVacia();
int esPilaVacia(Pila);
item top(Pila);
void pop(Pila*);
void push(Pila*, item);

int main() {
    Pila * nuevaPila = pilaVacia();
    printf("Es pila vacia ? = %d", esPilaVacia(*nuevaPila));
    push(nuevaPila, 5);push(nuevaPila, 3);push(nuevaPila, 185);
    printf("Tope de la pila: %d", top(*nuevaPila));
    pop(nuevaPila);
    printf("Nuevo tope de la pila: %d", top(*nuevaPila));
    return 0;
}

void push(Pila * pila, item dato1) {
    if (esPilaVacia(*pila)) {
        struct nodo * nuevoNodo = malloc(sizeof(struct nodo));
        nuevoNodo->dato = dato1;
        nuevoNodo->sig = NULL;
        pila->tope = nuevoNodo;
    } else {
        struct nodo * nuevoNodo = malloc(sizeof(struct nodo));
        nuevoNodo->dato = dato1;
        nuevoNodo->sig = pila->tope;
        pila->tope = nuevoNodo;
    }
    pila->altura += 1;
}

void pop(Pila* pila) {
    if (!esPilaVacia(*pila)) {
        struct nodo * aux = pila->tope;
        pila->tope = pila->tope->sig;
        pila->altura -= 1;
        free(aux);
    }
}

item top(Pila pila) {
    if (esPilaVacia(pila)) {
        return indefinido;
    } else {
        return pila.tope->dato;
    }
}

int esPilaVacia(Pila pila) {
    if (pila.altura == 0) {
        return 1;
    } else {
        return 0;
    }
}

Pila * pilaVacia() {
    Pila * nuevaPila = malloc(sizeof(Pila));
    nuevaPila->altura = 0;
    nuevaPila->tope = NULL;
    return nuevaPila;
}