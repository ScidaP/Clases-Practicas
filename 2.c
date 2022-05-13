#include <stdio.h>
#include <stdlib.h>

typedef int item; // tipo de datos que contiene la Pila
const item indefinido = -9999;

// elemento de una pila
struct nodo
{
    item dato;
    struct nodo *sig;
};

// cabecera de la pila que contiene contador

typedef struct
{
    struct nodo *tope;
    int altura;
} PILA;

// FUNCION PILA VACIA (CREA UNA PILA VACIA)
PILA PILAVACIA()
{
    PILA pila;
    pila.tope = NULL;
    pila.altura=0;
    return pila;
}
// FUNCION Q AGREGA UN ITEM AL TOPE DE  LA PILA
PILA PUSH(PILA pila, item x)
{
    struct nodo *nuevo;
    nuevo = (struct nodo *)malloc(sizeof(struct nodo));
    nuevo->dato = x;
    nuevo->sig = pila.tope;
    pila.tope = nuevo;
    pila.altura = pila.altura + 1;
    return pila;
}
// FUNCION QUE TESTEA SI UNA PILA ESTA VACIA O NO
int ESTAVACIA(PILA pila)
{
    if (pila.tope == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//  FUNCION QUE ELIMINA EL ULTIMO ELEMENTO DE LA PILA
PILA pop(PILA pila)
{
    struct nodo *aux;
    aux = pila.tope;
    pila.tope = pila.tope->sig;
    free(aux);
    pila.altura=pila.altura - 1;
    return pila;
}
// FUNCION QUE ME DEVUELVE EL ITEM QUE SE ENCUENTRA EN EL TOPE DE LA PILA
item TOP(PILA pila)
{
    return pila.tope->dato;
}

// FUNCION SELECTORA QUE DEVUELVE EL ITEM QUE SE ENCUENTRA AL FONDO DE LA PILA
item FONDO(PILA pila)
{
    struct nodo *aux;
    aux = pila.tope;
    do
    {
        aux = aux->sig;
    } while (aux->sig != NULL);
    return aux->dato;
}
// FUNCION Q DETERIMA SI UNA PILA ESTA CONTENIDA EN OTRA
int ESTACONTENIDA(PILA pila1, PILA pila2)
{

    struct nodo *aux1 = pila1.tope;
    struct nodo *aux2 = pila2.tope;
    while (aux1 != NULL && aux2 != NULL)
    {
        if (aux1->dato == aux2->dato)
        {
            aux1 = aux1->sig;
            aux2 = aux2->sig;
        }
        else
        {
            aux2 = aux2->sig;
        }
    }

    if (aux1 == NULL )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//FUNCION QUE TESTEA SI UNA PILA ES CRECIENTE 
int ESCRECIENTE(PILA pila){
    int b=1;
    struct nodo *aux1 = pila.tope;
    while (aux1->sig !=  NULL)
    {
        if (aux1->dato <= aux1->sig->dato  )
        {
            b=0;
        }
        aux1=aux1->sig;
    }
}

//OPERACION CONTAR POSITIVOS
int CONTARPOSITIVOS(PILA pila){
int contador=0;
struct nodo *AUX=pila.tope;

    while (AUX != NULL)
    {
        if (AUX->dato > 0)
        {
            contador=contador + 1;
        }
        AUX=AUX->sig;
        
    }
    return contador;
}
int main(){ 
    PILA pila1,pila2;

    pila2 = PILAVACIA();
    pila1 = PILAVACIA();
    for (int i = -1; i < 2; i++)
    {
        pila1=PUSH(pila1,i);
    }

    for (int i = 0; i < 3; i++)
    {
        pila2=PUSH(pila2,i);
    }
    printf("ALTURA PILA 1: %d \n",pila1.altura);
    printf("ALTURA PILA 2: %d \n",pila2.altura);
int b= ESTACONTENIDA(pila1,pila2);
if (b==1)
{
    printf(" ESTA CONTENIDA \n");
}
else
{
     printf("NO ESTA CONTENIDA \n");
}

int contador=CONTARPOSITIVOS(pila1);
printf("contador= %d \n",contador);


    return 0;
}





