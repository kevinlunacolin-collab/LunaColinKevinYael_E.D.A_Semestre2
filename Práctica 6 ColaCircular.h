#ifndef COLA_CIRCULAR_DINAMICA_H
#define COLA_CIRCULAR_DINAMICA_H
#include <stdio.h>

/* Cola circular enlazada de enteros con tope de tamaño (capacidad).
   Los nodos se crean (malloc) en enqueue y se liberan (free) en dequeue. */

typedef struct Nodo {
    int dato;
    struct Nodo *sig;
} Nodo;

typedef struct ColaCircular {
    Nodo *head;      /* frente: siguiente en salir (dequeue) */
    Nodo *tail;      /**final : último en entrar (enqueue)   */
    int   tam;       /* cantidad actual de elementos         */
    int   capacidad; /* tope fijo (máximo número de elementos) */
} ColaCircular;
//Correcciones: head y tail funcionan como punteros, al inicio estos no contaban con el puntero, entonces lo unico que se hizo fue agregarles el apuntador *

/* Inicializa la cola con una capacidad fija (> 0). */
int  cola_circ_init(ColaCircular *c, int capacidad);

/* Estado y metadatos */
int  cola_circ_esta_vacia( ColaCircular *c);
int  cola_circ_esta_llena( ColaCircular *c);
int  cola_circ_tamano( ColaCircular *c);
int  cola_circ_capacidad( ColaCircular *c);

/* Operaciones (todas O(1)) */
int  cola_circ_encolar(ColaCircular *c, int valor);       /*enqueue */
int  cola_circ_desencolar(ColaCircular *c, int *salida);  /*dequeue; salida puede ser NULL */
int  cola_circ_frente( ColaCircular *c, int *salida); /* peek    */
/*Correcciones: al inicio esta parte del códgio no contaba con los apuntadores de c, lo que indicaba que estabamos trabajando 
con una copia de la estrcuctura de cola circular, es por eso que se le agrego un apuntador, para poder trabajar con la estructura original*/

/* Vacía la cola liberando todos los nodos (no cambia la capacidad). */
void cola_circ_clear(ColaCircular *c);

/* Libera todos los recursos y deja la estructura en estado seguro. */
void cola_circ_destroy(ColaCircular *c);

#endif /* COLA_CIRCULAR_DINAMICA_H */