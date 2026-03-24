#include "ColaCircular.h"
#include <stdlib.h>
#include <stdio.h>

int cola_circ_init(ColaCircular *c, int capacidad) {
    if (!c || capacidad <= 0) return 0;
    c ->head= NULL;
    c ->tail= NULL;
    c ->tam= 0;
    c->capacidad = capacidad;
    return 1;
}

int cola_circ_esta_vacia( ColaCircular *c) {
    if (!c) 
        return 1;
    return (c->tam == 0) ? 1 : 0;
}

int cola_circ_esta_llena( ColaCircular *c) {
    if (!c) 
        return 0;
    return (c->tam == c->capacidad) ? 1 : 0;
}

int cola_circ_tamano( ColaCircular *c) {
    if (!c) 
        return 0;
    return c->tam;
}

int cola_circ_capacidad( ColaCircular *c) {
    if (!c) 
        return 0;
    return c->capacidad;
}

int cola_circ_encolar(ColaCircular *c, int valor) {
    //Verifica el tamaño de la cola y su capacidad
    if (!c || c->tam == c-> capacidad)  
        return 0;
    
    //Se crea el nodo para ingresarlo a la cola 
    Nodo *n = (Nodo *)malloc(sizeof(Nodo));
    if(!n) return 0; //Este if se agrega en el caso de que malloc falle
    n ->dato = valor;
    
    if (c->tam ==0){
        //Aqui se analiza el primer nodo ingresado
        c->head = n; //Se inizializa el nodo 
        c ->tail = n;// Al ser una cola circular, la cola apuntara al nodo anterior, que es head
        n -> sig = n;
    } else {
        n ->sig = c->head;
        c ->tail ->sig = n;
        c ->tail = n;
    }

    c->tam++;
    return 1;
}

int cola_circ_desencolar(ColaCircular *c, int *salida) {
    if (!c || c->tam == 0)
        return 0;

    Nodo *prim = c->head;
    if (salida)  *salida = prim->dato;

    if(c->tam ==1){
        c->head = NULL;
        c->tail= NULL;
    } else {
        c->head = c -> head ->sig; // se mueve  al siguiente
        c->tail->sig =c->head; // El ultimo nodo apunta al nuevo que esta enfrente 
    }

    free(prim);
    c->tam--;
    return 1;
}

int cola_circ_frente( ColaCircular *c, int *salida) {
    if (!c || c->tam == 0 || !salida)
        return 0;
    *salida = c->head->dato;
    return 1;
}

void cola_circ_clear(ColaCircular *c) {
    if (!c)
        return;
    int x;
    while (cola_circ_desencolar(c, &x)) {
        /* vaciando... */
    }
}

void cola_circ_destroy(ColaCircular *c) {
    if (!c)
        return;
    cola_circ_clear(c);
    c -> head= NULL;//La cabeza ahora no esta apuntando a nada 
    c -> tail= NULL;// La cola de igual forma tampoco apunta a ningun valor
    c->capacidad = 0;
    c ->tam = 0;
}
/*Esta funcion void al inicio no limpiaba los datos de head y tail, entonces se le agregaron estas variables 
para que se pueda ejecutar esta acción*/