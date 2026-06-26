#include <stdio.h>
#include <stdlib.h>

// Nodo de la lista: guarda un dato entero y un puntero al siguiente
struct Nodo
{
    int dato;
    struct Nodo *siguiente;
};

// Inserta un nodo nuevo AL INICIO de la lista (siempre pasa a ser la cabeza)
void insertarAlInicio(struct Nodo **cabeza, int valor)
{
    struct Nodo *nuevoNodo = (struct Nodo *)malloc(sizeof(struct Nodo)); // Reservamos memoria
    nuevoNodo->dato = valor;                                             // Asignamos el valor al nodo
    nuevoNodo->siguiente = *cabeza;                                      // El nuevo nodo apunta al nodo actual de la cabeza
    *cabeza = nuevoNodo;                                                 // La cabeza de la lista ahora es el nuevo nodo
}

// Recorre e imprime todos los valores de la lista
void mostrarLista(struct Nodo *nodo)
{
    while (nodo != NULL)
    {
        printf("%d -> ", nodo->dato); // Mostramos el valor del nodo
        nodo = nodo->siguiente;       // Avanzamos al siguiente nodo
    }
    printf("NULL\n"); // Indicamos el final de la lista
}

// Función principal del programa
int main()
{
    struct Nodo *lista = NULL; // Creamos la lista vacía (sin nodos todavía)

    // Como insertarAlInicio siempre pone el nuevo nodo primero,
    // el orden final queda invertido respecto al orden de inserción
    insertarAlInicio(&lista, 10); // Lista: 10
    insertarAlInicio(&lista, 20); // Lista: 20 -> 10
    insertarAlInicio(&lista, 30); // Lista: 30 -> 20 -> 10
    insertarAlInicio(&lista, 40); // Lista: 40 -> 30 -> 20 -> 10

    printf("Lista actual:\n");
    mostrarLista(lista); // Muestra la lista completa

    return 0; // Fin del programa
}
