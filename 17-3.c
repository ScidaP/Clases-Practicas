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

Nodo * insertar(Nodo * Lista) { // Funciona
    int numeroRandom = rand() % 15 + 1; //Numero random entre 1 y 100
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

int longitud(Nodo * Lista) { // Funciona
    if (Lista == NULL) {
        return 0;
    } else {
        int i = 0;
        while (Lista != NULL) {
            i++;
            Lista = Lista->siguiente;
        }
        return i;
    }
}

int pertenece(Nodo * Lista, int dato) { // Funciona
    if (Lista == NULL) {
        return 0;
    } else {
        while (Lista != NULL) {
            if (Lista->dato == dato) {
                return 1;
                break;
            } else {
                Lista = Lista->siguiente;
            }
        }
    }
}

Nodo * borrarK(Nodo * Lista, int datoABorrar) { // En desarrollo
    if (Lista == NULL) {
        return Lista;
    } else {
        Nodo * aux = CrearNodo(0);
        aux = Lista;
        while (aux != NULL) {
            if (aux->dato == datoABorrar) {
                Nodo * NuevaLista = borrar(Lista);
            }
        }
    }
}

int estaContenida(Nodo * Lista1, Nodo * Lista2) { // En desarrollo
    int coincidencias = 0;
    Nodo * aux = CrearNodo(0);
    aux = Lista1;
    int longitudLista1 = longitud(Lista1);
    int longitudLista2 = longitud(Lista2);
    for (int i = 0; i < longitudLista1; i++) {
        Nodo * aux2 = CrearNodo(0);
        aux2 = Lista2;
        for (int k = 0; k < longitudLista2; k++) {
            if (aux->dato == aux2->dato) {
                coincidencias++;
                aux = borrar(aux); // Una vez que termina de iterar buscando coincidencias del primer nodo de la primera lista, lo elimino así en la proxima iteración, busca por el segundo.
                break; // Si se encuentra una coincidencia, se termina con la iteración del for y se 
            } else {
                aux2 = borrar(aux2); //Si el primer nodo de la primera lista no coincide, entonces borro el priemr nodo de la segunda lista, de esta manera se comparará el primer nodo con el segundo de la segunda lista y así.
            }
        }
    }
    //RETURN
    if (longitudLista1 == coincidencias) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    srand(time(NULL));
    Nodo * ListaNueva = (Nodo*)malloc(sizeof(ListaNueva));
    ListaNueva = crearListaVacia();
    ListaNueva = insertar(ListaNueva);
    ListaNueva = insertar(ListaNueva);
    ListaNueva = insertar(ListaNueva);
    /* primerElemento(ListaNueva);
    int longitudLista = longitud(ListaNueva);
    printf("Longitud de la lista: %d\n", longitudLista);
    int valorAEncontrar = 8;
    int valorEncontrado = pertenece(ListaNueva, valorAEncontrar);
    printf("Resultado de la coincidencia de %d en la Lista: %d (1=Encontrado|0=No Encontrado)", valorAEncontrar, valorEncontrado); */
    Nodo * ListaNueva2 = (Nodo*)malloc(sizeof(ListaNueva2));
    ListaNueva2 = crearListaVacia();
    ListaNueva2 = insertar(ListaNueva2);
    ListaNueva2 = insertar(ListaNueva2);
    ListaNueva2 = insertar(ListaNueva2);
    ListaNueva2 = insertar(ListaNueva2);
    ListaNueva2 = insertar(ListaNueva2);
    ListaNueva2 = insertar(ListaNueva2);
    ListaNueva2 = insertar(ListaNueva2);
    ListaNueva2 = insertar(ListaNueva2);
    ListaNueva2 = insertar(ListaNueva2);
    ListaNueva2 = insertar(ListaNueva2);
    ListaNueva2 = insertar(ListaNueva2);
    ListaNueva2 = insertar(ListaNueva2);
    ListaNueva2 = insertar(ListaNueva2);
    ListaNueva2 = insertar(ListaNueva2);
    ListaNueva2 = insertar(ListaNueva2);
    ListaNueva2 = insertar(ListaNueva2);
    ListaNueva2 = insertar(ListaNueva2);
    ListaNueva2 = insertar(ListaNueva2);
    ListaNueva2 = insertar(ListaNueva2);
    ListaNueva2 = insertar(ListaNueva2);
    ListaNueva2 = insertar(ListaNueva2);
    ListaNueva2 = insertar(ListaNueva2);
    int esContenida = estaContenida(ListaNueva, ListaNueva2);
    printf("[0 = No contenida | 1 = Esta contenida]. Resultado: %d", esContenida);
    getchar();getchar();getchar();getchar();
    return 0;
}