#include <stdio.h>
#include <stdlib.h>

// Estructura de cada nodo de la cola
struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

// Encolar (agregar al final): a diferencia de una lista normal, una cola necesita
// dos punteros (frente y fin) para que encolar y desencolar sean rápidos (O(1))
// sin tener que recorrer toda la cola cada vez.
void encolar(struct Nodo** frente, struct Nodo** fin, int valor) {
    struct Nodo* nuevo = (struct Nodo*) malloc(sizeof(struct Nodo)); // reservamos memoria para el nodo nuevo
    nuevo->dato = valor;
    nuevo->siguiente = NULL; // como entra al final, todavía no apunta a nada

    if (*fin == NULL) {
        // si la cola está vacía, el nuevo nodo es a la vez el frente y el fin
        *frente = *fin = nuevo;
    } else {
        // si ya hay elementos, lo conectamos después del actual "fin"...
        (*fin)->siguiente = nuevo;
        // ...y actualizamos "fin" para que apunte al nodo recién agregado
        *fin = nuevo;
    }

    printf("Se encoló: %d\n", valor);
}

// Desencolar (sacar del frente): devuelve el valor que sale, o -1 si la cola está vacía
int desencolar(struct Nodo** frente, struct Nodo** fin) {
    if (*frente == NULL) {
        printf("La cola está vacía.\n");
        return -1; // no hay nada para sacar
    }

    struct Nodo* temp = *frente;       // guardamos el nodo que vamos a sacar
    int valor = temp->dato;            // guardamos su valor para devolverlo después
    *frente = (*frente)->siguiente;    // el frente avanza al siguiente nodo

    if (*frente == NULL) {
        // si después de sacar el nodo la cola quedó vacía, "fin" también debe quedar NULL
        // (sino quedaría apuntando a un nodo ya liberado)
        *fin = NULL;
    }

    free(temp); // liberamos la memoria del nodo que sacamos
    return valor;
}

// Recorre la cola desde el frente hasta el fin, imprimiendo cada valor
void mostrar(struct Nodo* frente) {
    printf("Contenido de la cola:\n");
    while (frente != NULL) {
        printf("%d -> ", frente->dato);
        frente = frente->siguiente;
    }
    printf("NULL\n");
}

int main() {
    struct Nodo* frente = NULL; // apunta al primer elemento (el próximo que sale)
    struct Nodo* fin = NULL;    // apunta al último elemento (donde entran los nuevos)

    // Encolamos valores: en una cola, el primero que entra es el primero que sale (FIFO)
    encolar(&frente, &fin, 10); // Cola: 10
    encolar(&frente, &fin, 20); // Cola: 10 -> 20
    encolar(&frente, &fin, 30); // Cola: 10 -> 20 -> 30

    mostrar(frente);

    // Desencolamos uno: como es FIFO, sale el 10 (el primero que entró)
    int valor = desencolar(&frente, &fin);
    printf("Se desencoló: %d\n", valor);

    mostrar(frente); // queda: 20 -> 30

    return 0;
}
