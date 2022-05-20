#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define indefinido -9999
typedef int item;
struct nodo {
    item dato;
    struct nodo* sig;
};

typedef struct ListaCircular {
    struct nodo* primerNodo;
}ListaCircular;

ListaCircular LCVacia();
ListaCircular LCInsertar(ListaCircular, item);
ListaCircular LCBorrar(ListaCircular);
ListaCircular LCValor(item);
int EsLCVacia(ListaCircular);
ListaCircular LCRotar(ListaCircular);

int main() {
    ListaCircular nuevaLista = LCVacia();
    nuevaLista = LCInsertar(nuevaLista, 2);
        nuevaLista = LCInsertar(nuevaLista, 3);
            nuevaLista = LCInsertar(nuevaLista, 4);
                nuevaLista = LCInsertar(nuevaLista, 5);
    getchar();getchar();getchar();
    return 0;
}

ListaCircular LCVacia() {
    ListaCircular Lista;
    Lista.primerNodo = NULL;
    return Lista;
}

ListaCircular LCInsertar (ListaCircular Lista, item item1) {
    struct nodo * nuevoNodo = malloc(sizeof(struct nodo));
    struct nodo * aux = malloc(sizeof(struct nodo));
    nuevoNodo->dato = item1;
    if (EsLCVacia(Lista)) {
        Lista.primerNodo = nuevoNodo;
        nuevoNodo->sig = nuevoNodo; // Se apunta a sí mismo
        return Lista;
    } else if (Lista.primerNodo->sig == Lista.primerNodo) { // En caso que la LC sólo tenga un nodo (primerNodo se apunta a sí mismo)
        nuevoNodo->sig = Lista.primerNodo;
        Lista.primerNodo->sig = nuevoNodo;
        return Lista;
    } else { // Para cuando la LC tiene más de un nodo
        nuevoNodo->sig = Lista.primerNodo;
        Lista.primerNodo->sig->sig = nuevoNodo;
        return Lista;
    }
}

int EsLCVacia(ListaCircular Lista) {
    if (Lista.primerNodo == NULL) {
        return 1;
    } else {
        return 0;
    }
}