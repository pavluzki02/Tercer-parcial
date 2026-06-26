#include <stdio.h>
#include <stdlib.h>

// Nodo de la pila
struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

// Agregar (push): siempre se agrega arriba de todo (en la "punta" de la pila).
// Es básicamente lo mismo que insertarAlInicio en una lista normal.
void push(struct Nodo** tope, int valor) {
    struct Nodo* nuevo = (struct Nodo*) malloc(sizeof(struct Nodo)); // reservamos memoria
    nuevo->dato = valor;
    nuevo->siguiente = *tope; // el nuevo nodo apunta a lo que antes era el tope
    *tope = nuevo;            // ahora el tope es el nodo nuevo
    printf("Se apiló: %d\n", valor);
}

// Sacar (pop): siempre se saca el de arriba (el último que entró).
// Devuelve el valor que sale, o -1 si la pila está vacía.
int pop(struct Nodo** tope) {
    if (*tope == NULL) {
        printf("La pila está vacía.\n");
        return -1; // no hay nada para sacar
    }
    struct Nodo* temp = *tope;   // guardamos el nodo que vamos a sacar
    int valor = temp->dato;      // guardamos su valor para devolverlo
    *tope = temp->siguiente;     // el tope pasa a ser el nodo de abajo
    free(temp);                  // liberamos la memoria del nodo que sacamos
    return valor;
}

// Recorre la pila desde el tope hacia abajo, imprimiendo cada valor
void mostrar(struct Nodo* tope) {
    printf("Contenido de la pila:\n");
    while (tope != NULL) {
        printf("%d\n", tope->dato);
        tope = tope->siguiente;
    }
}

int main() {
    struct Nodo* pila = NULL; // pila vacía al arrancar

    // Apilamos valores: en una pila, el último que entra es el primero que sale (LIFO)
    push(&pila, 10); // Pila (de arriba a abajo): 10
    push(&pila, 20); // Pila: 20 -> 10
    push(&pila, 30); // Pila: 30 -> 20 -> 10

    mostrar(pila);

    // Desapilamos uno: como es LIFO, sale el 30 (el último que entró)
    int desapilado = pop(&pila);
    printf("Se desapiló: %d\n", desapilado);

    mostrar(pila); // queda: 20 -> 10

    return 0;
}
