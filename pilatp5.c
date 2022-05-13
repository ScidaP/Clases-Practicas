#include <stdlib.h>
#include <stdio.h>

typedef int item;
const item indefinido=9999;
 //PILA CON LISTA ENLAZADA
struct nodo{
    item dato;
    struct nodo *siguiente;
};

typedef struct {
    struct nodo *tope;
    int altura;
}Pila;

Pila * pilavacia();
int espilavacia(Pila*);
item top(Pila*);
Pila *pop(Pila*);
Pila *push(Pila*, item);

int main() {
    Pila * nuevaPila = pilavacia();
    printf("Es pila vacia? : %d", espilavacia(nuevaPila));
    item dato1 = 1;
    item dato2 = 5;
    item dato3 = 9;
    nuevaPila = push(nuevaPila, dato1);
    nuevaPila = push(nuevaPila, dato2);
    nuevaPila = push(nuevaPila, dato3);
    printf("\nvalor del tope de la pila: %d", top(nuevaPila));
    nuevaPila = pop(nuevaPila);
    printf("\nvalor del tope de la pila: %d", top(nuevaPila));
    return 0;
}

Pila *pop(Pila*pila) {
    struct nodo * aux;
    pila->tope = pila->tope->siguiente;
    pila->altura = pila->altura - 1;
    return pila;
}

Pila *push(Pila*pila, item datoNuevo) { // FUNCIONA XDDDDDDD
    struct nodo *nuevoNodo = (struct nodo*)malloc(sizeof(struct nodo)); // Creo el espacio de memoria
    nuevoNodo->dato = datoNuevo; // Asigno el valor pasado por parámetro
    nuevoNodo->siguiente = pila->tope; // Como nuevoNodo ahora es el tope, nuevoNodo va a apuntar al tope anterior
    pila->tope = nuevoNodo; // Ahora el tope de la pila será el nuevoNodo
    pila->altura = pila->altura + 1; // Le sumo uno a la altura
    return pila; // Devuelvo la pila nueva
}

item top(Pila * pila) {
    if (espilavacia(pila)) {
        return indefinido;
    } else {
        return pila->tope->dato;
    }
}

int espilavacia(Pila * pila) { // Funciona
    if (pila->altura == 0) {
        return 1;
    } else {
        return 0;
    }
}

Pila * pilavacia() { // Funciona
    Pila *pila;
    pila = malloc(sizeof(Pila));
    pila->tope = NULL;
    pila->altura = 0;
    return pila;
}