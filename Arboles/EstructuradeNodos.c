#include <stdio.h>
#include <stdlib.h>

// Estructura del nodo: a diferencia de una lista, acá cada nodo tiene DOS punteros,
// uno para el hijo de la izquierda y otro para el de la derecha. Esto es un árbol
// binario de búsqueda (ABB / BST): los valores menores van a la izquierda y los
// mayores (o iguales) a la derecha.
struct Nodo {
    int dato;
    struct Nodo* izquierdo;
    struct Nodo* derecho;
};

// Crea un nodo nuevo, sin hijos (las dos ramas arrancan en NULL)
struct Nodo* nuevoNodo(int valor) {
    struct Nodo* nodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nodo->dato = valor;
    nodo->izquierdo = NULL;
    nodo->derecho = NULL;
    return nodo;
}

// Inserta un valor en el árbol y devuelve la raíz (puede ser una raíz nueva si el
// árbol estaba vacío). Es recursiva: en cada nodo decide si seguir por la izquierda
// o por la derecha, hasta encontrar un lugar vacío (NULL) donde colgar el nodo nuevo.
struct Nodo* insertar(struct Nodo* raiz, int valor) {
    if (raiz == NULL) {
        // caso base: llegamos a un lugar vacío, ahí va el nodo nuevo
        return nuevoNodo(valor);
    }

    if (valor < raiz->dato) {
        // el valor es menor, así que se inserta en el subárbol izquierdo
        raiz->izquierdo = insertar(raiz->izquierdo, valor);
    } else {
        // el valor es mayor o igual, así que se inserta en el subárbol derecho
        raiz->derecho = insertar(raiz->derecho, valor);
    }

    return raiz; // devolvemos la raíz sin cambios (solo cambió algo más abajo)
}

// Recorrido inorden: primero todo el subárbol izquierdo, después el nodo actual,
// y al final todo el subárbol derecho. En un ABB esto imprime los valores
// ORDENADOS de menor a mayor.
void inorden(struct Nodo* raiz) {
    if (raiz != NULL) {
        inorden(raiz->izquierdo);      // primero lo que es menor que raiz
        printf("%d ", raiz->dato);     // después el valor de este nodo
        inorden(raiz->derecho);        // por último lo que es mayor que raiz
    }
}

int main() {
    struct Nodo* raiz = NULL; // árbol vacío al arrancar

    // Insertamos algunos valores. Ojo: solo la primera llamada guarda el resultado
    // en "raiz" porque ahí el árbol estaba vacío y necesitamos que raiz apunte al
    // nodo nuevo. En las siguientes llamadas raiz ya existe, así que el árbol se
    // modifica "desde adentro" (por los punteros izquierdo/derecho) y no hace
    // falta reasignar raiz (aunque no está mal hacerlo, por las dudas).
    raiz = insertar(raiz, 10); // 10 se convierte en la raíz
    insertar(raiz, 5);         // 5 < 10 -> va a la izquierda de 10
    insertar(raiz, 15);        // 15 >= 10 -> va a la derecha de 10
    insertar(raiz, 3);         // 3 < 10 -> izquierda; 3 < 5 -> izquierda de 5
    insertar(raiz, 7);         // 7 < 10 -> izquierda; 7 >= 5 -> derecha de 5

    // Árbol resultante:
    //        10
    //       /  \
    //      5    15
    //     / \
    //    3   7

    printf("Recorrido inorden del árbol: ");
    inorden(raiz);  // Debería imprimir: 3 5 7 10 15 (siempre ordenado en un ABB)

    return 0;
}
