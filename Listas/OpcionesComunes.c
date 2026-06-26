#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo
typedef struct Nodo {
    int dato;               // valor que guarda el nodo
    struct Nodo* siguiente; // puntero al próximo nodo
} Nodo; // gracias al typedef podemos escribir "Nodo" en vez de "struct Nodo"

// Función para crear un nuevo nodo (reserva memoria y lo deja "suelto", sin engancharlo a nada)
Nodo* crearNodo(int dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Función para insertar un nodo al inicio de la lista
void insertarInicio(Nodo** cabeza, int dato) {
    Nodo* nuevoNodo = crearNodo(dato);
    nuevoNodo->siguiente = *cabeza; // el nuevo nodo apunta a lo que era la cabeza
    *cabeza = nuevoNodo;            // y ahora la cabeza es el nodo nuevo
}

// Función para insertar un nodo al final de la lista
void insertarFinal(Nodo** cabeza, int dato) {
    Nodo* nuevoNodo = crearNodo(dato);
    if (*cabeza == NULL) { // si la lista está vacía, el nuevo nodo pasa a ser la cabeza
        *cabeza = nuevoNodo;
        return;
    }
    Nodo* temp = *cabeza;
    while (temp->siguiente != NULL) { // recorremos hasta el último nodo
        temp = temp->siguiente;
    }
    temp->siguiente = nuevoNodo; // lo conectamos al final
}

// Función para eliminar un nodo con un valor específico
void eliminarNodo(Nodo** cabeza, int valor) {
    Nodo* temp = *cabeza;
    Nodo* anterior = NULL; // guarda el nodo de atrás para poder saltear el que borramos
    while (temp != NULL && temp->dato != valor) { // buscamos el valor recorriendo la lista
        anterior = temp;
        temp = temp->siguiente;
    }
    if (temp == NULL) { // recorrimos todo y no estaba
        printf("Valor no encontrado en la lista.\n");
        return;
    }
    if (anterior == NULL) { // el nodo a eliminar es la cabeza
        *cabeza = temp->siguiente;
    } else { // está en medio o al final
        anterior->siguiente = temp->siguiente; // saltamos el nodo eliminado
    }
    free(temp); // liberamos la memoria reservada para ese nodo
    printf("Nodo con valor %d eliminado.\n", valor);
}

// Función para buscar un valor en la lista (solo informa por consola, no devuelve nada)
void buscarValor(Nodo* cabeza, int valor) {
    Nodo* temp = cabeza;
    while (temp != NULL) {
        if (temp->dato == valor) {
            printf("Valor %d encontrado en la lista.\n", valor);
            return; // ya lo encontramos, no hace falta seguir recorriendo
        }
        temp = temp->siguiente;
    }
    printf("Valor %d no encontrado en la lista.\n", valor); // se recorrió todo sin éxito
}

// Función para mostrar todos los valores de la lista
void mostrarValores(Nodo* cabeza) {
    Nodo* temp = cabeza;
    if (temp == NULL) {
        printf("La lista está vacía.\n");
        return;
    }
    printf("Valores en la lista: ");
    while (temp != NULL) {
        printf("%d ", temp->dato);
        temp = temp->siguiente;
    }
    printf("\n");
}

// Función principal: menú interactivo para probar todas las operaciones de la lista
int main() {
    Nodo* lista = NULL; // arrancamos con la lista vacía
    int opcion, valor;

    do {
        printf("\nOperaciones con Listas:\n");
        printf("1. Insertar al inicio\n");
        printf("2. Insertar al final\n");
        printf("3. Eliminar un nodo\n");
        printf("4. Buscar un valor\n");
        printf("5. Mostrar todos los valores\n");
        printf("6. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: // pide un valor y lo inserta al inicio de la lista
                printf("Ingrese el valor a insertar al inicio: ");
                scanf("%d", &valor);
                insertarInicio(&lista, valor);
                break;
            case 2: // pide un valor y lo inserta al final de la lista
                printf("Ingrese el valor a insertar al final: ");
                scanf("%d", &valor);
                insertarFinal(&lista, valor);
                break;
            case 3: // pide un valor y borra el primer nodo que lo tenga
                printf("Ingrese el valor del nodo a eliminar: ");
                scanf("%d", &valor);
                eliminarNodo(&lista, valor);
                break;
            case 4: // pide un valor y se fija si está en la lista
                printf("Ingrese el valor a buscar: ");
                scanf("%d", &valor);
                buscarValor(lista, valor);
                break;
            case 5: // imprime todos los valores actuales
                mostrarValores(lista);
                break;
            case 6: // termina el programa
                printf("Saliendo del programa.\n");
                break;
            default: // cualquier número fuera del menú
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 6); // repite el menú hasta que se elija salir

    return 0;
}
