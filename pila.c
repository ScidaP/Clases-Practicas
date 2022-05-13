#include <stdio.h>
#include <stdlib.h>

#define N 100
#define indefinido -9999
typedef int item;
typedef struct {
    int tope;
    item elementos[N]
} tipopila;

void pilavacia(tipopila*);
int espilavacia(tipopila);
item top (tipopila);
void pop (tipopila*);
void push(tipopila*, item);

void pilavacia(tipopila *pila) {
    pila->tope = N;
}

int espilavacia(tipopila pila) {
    return (pila.tope == N);
}

item top (tipopila pila) {
    if (espilavacia(pila)) {
        return (indefinido);
    } else {
        return (pila.elementos[pila.tope]);
    }
}

void pop (tipopila *pila) {
    if (!espilavacia(*pila)) {
        pila->tope++;
    }
}

void push (tipopila *pila, item x) {
    if (pila->tope != 0) {
        pila->elementos[--pila->tope] = x;
    }
}
