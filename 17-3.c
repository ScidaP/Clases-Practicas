#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

Nodo * crearListaVacia() { // Funciona
    return NULL;
}

int esListaVacia(Nodo * Lista) { // Funciona
    if (Lista == NULL) {
        return 1;
    } else {
        return 0;
    }
}

Nodo * CrearNodo(int X) { // Funciona
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

void primerElemento(Nodo * Lista) { // Funciona
    printf("Numero del primer elemento de la lista: %d\n", Lista->dato);
}

Nodo * borrar(Nodo * Lista) { // Funciona
    if (Lista == NULL) {
        printf("La lista esta vacia, no se puede eliminar nodos.");
        return Lista;
    } else {
        Nodo * aux = CrearNodo(0);
        aux = Lista;
        Lista = aux->siguiente;
        free(aux);
        return Lista;
    }

}

int main() {
    srand(time(NULL));
    Nodo * ListaNueva = (Nodo*)malloc(sizeof(ListaNueva));
    ListaNueva = crearListaVacia();
    ListaNueva = insertar(ListaNueva);
    ListaNueva = insertar(ListaNueva);
    ListaNueva = insertar(ListaNueva);
    ListaNueva = insertar(ListaNueva);
    primerElemento(ListaNueva);
    ListaNueva = borrar(ListaNueva);
    getchar();getchar();getchar();getchar();
    return 0;
}