#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

Nodo * crearListaVacia() {
    return NULL;
}

int esListaVacia(Nodo * Lista) {
    if (Lista == NULL) {
        return 1;
    } else {
        return 0;
    }
}

Nodo * CrearNodo(int X) {
    Nodo * nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = X;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

Nodo * insertar(Nodo * Lista) {
    int numeroRandom = rand() % 100 + 1; //Numero random entre 1 y 100
    Nodo * NuevoNodo = CrearNodo(numeroRandom);
    NuevoNodo->siguiente = Lista;
    Lista = NuevoNodo;
    return Lista;
}

int main() {
    srand(time(NULL));
    Nodo * ListaNueva = (Nodo*)malloc(sizeof(ListaNueva));
    ListaNueva = crearListaVacia();
    ListaNueva = insertar(ListaNueva);
    ListaNueva = insertar(ListaNueva);
    ListaNueva = insertar(ListaNueva);
    ListaNueva = insertar(ListaNueva);
    getchar();getchar();getchar();getchar();
    return 0;
}