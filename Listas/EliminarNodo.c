#include <stdio.h>
#include <stdlib.h>

// Nodo de la lista: guarda un dato entero y un puntero al siguiente
struct Nodo
{
    int dato;
    struct Nodo *siguiente;
};

// Inserta un nodo nuevo AL FINAL de la lista
void insertarAlFinal(struct Nodo **cabeza, int valor)
{
    struct Nodo *nuevoNodo = (struct Nodo *)malloc(sizeof(struct Nodo)); // reservamos memoria para el nodo nuevo
    nuevoNodo->dato = valor;                                             // guardamos el valor recibido
    nuevoNodo->siguiente = NULL;                                         // como va al final, no apunta a nada
    if (*cabeza == NULL)
    {
        // si la lista está vacía, este nodo pasa a ser la cabeza
        *cabeza = nuevoNodo;
        return;
    }

    // si ya hay nodos, recorremos hasta llegar al último
    struct Nodo *temp = *cabeza;
    while (temp->siguiente != NULL)
    {
        temp = temp->siguiente;
    }
    temp->siguiente = nuevoNodo; // lo conectamos al final de la lista
}

// Busca el primer nodo con un valor dado y lo elimina de la lista
void eliminarNodo(struct Nodo **cabeza, int valor)
{
    struct Nodo *temp = *cabeza;
    struct Nodo *anterior = NULL; // guarda el nodo de atrás, para poder "saltear" el que borramos
    while (temp != NULL && temp->dato != valor)
    {
        anterior = temp;
        temp = temp->siguiente;
    }
    if (temp == NULL)
        return; // Si no lo encontramos, salimos

    if (anterior == NULL)
    {
        // El nodo a eliminar es el primero
        *cabeza = temp->siguiente;
    }
    else
    {
        // Saltamos el nodo a eliminar
        anterior->siguiente = temp->siguiente;
    }

    free(temp); // Liberamos la memoria del nodo eliminado
}

// Recorre e imprime todos los valores de la lista
void mostrarLista(struct Nodo *nodo)
{
    while (nodo != NULL)
    {
        printf("%d -> ", nodo->dato);
        nodo = nodo->siguiente;
    }
    printf("NULL\n");
}

int main()
{
    struct Nodo *lista = NULL; // arrancamos con la lista vacía

    // Insertamos varios nodos al final, quedan en este orden: 10 -> 20 -> 30 -> 40 -> 50
    insertarAlFinal(&lista, 10);
    insertarAlFinal(&lista, 20);
    insertarAlFinal(&lista, 30);
    insertarAlFinal(&lista, 40);
    insertarAlFinal(&lista, 50);

    printf("Lista actual:\n");
    mostrarLista(lista);

    eliminarNodo(&lista, 20); // borramos el nodo con valor 20 (queda 10 -> 30 -> 40 -> 50)
    mostrarLista(lista);

    return 0;
}
