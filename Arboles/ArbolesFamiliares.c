#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura del nodo del árbol: representa UNA persona.
// Acá "hijoIzquierdo" e "hijoDerecho" no significan "menor" o "mayor" como en un
// árbol de búsqueda; son simplemente el primer y segundo hijo de esa persona
// (este árbol está limitado a 2 hijos por persona, no es un árbol genealógico real
// donde alguien podría tener 3, 4 o más hijos).
struct Persona {
    char nombre[50];
    struct Persona* hijoIzquierdo;
    struct Persona* hijoDerecho;
};

// Crea una nueva persona (un nodo) sin hijos todavía
struct Persona* crearPersona(const char* nombre) {
    struct Persona* nueva = (struct Persona*)malloc(sizeof(struct Persona));
    strcpy(nueva->nombre, nombre);
    nueva->hijoIzquierdo = NULL;
    nueva->hijoDerecho = NULL;
    return nueva;
}

// Conecta a un padre con sus dos hijos (los "engancha" como hijoIzquierdo e hijoDerecho)
void agregarHijos(struct Persona* padre, struct Persona* hijo1, struct Persona* hijo2) {
    padre->hijoIzquierdo = hijo1;
    padre->hijoDerecho = hijo2;
}

// Función recursiva para imprimir el árbol genealógico con sangría según el nivel
// (nivel 0 = la raíz, nivel 1 = sus hijos, nivel 2 = sus nietos, etc.)
void imprimirArbol(struct Persona* raiz, int nivel) {
    if (raiz == NULL) return; // caso base: no hay nadie en esta rama, no imprimimos nada

    // Imprimimos espacios según el nivel para que se vea la jerarquía con sangría
    for (int i = 0; i < nivel; i++) {
        printf("    ");
    }

    // Mostramos el nombre de la persona actual
    printf("└─ %s\n", raiz->nombre);

    // Llamadas recursivas para los hijos, un nivel más profundo (nivel + 1)
    imprimirArbol(raiz->hijoIzquierdo, nivel + 1);
    imprimirArbol(raiz->hijoDerecho, nivel + 1);
}

int main() {
    // Creamos cada persona como un nodo individual (todavía sin conectar entre sí)
    struct Persona* abuelo = crearPersona("Juan");

    struct Persona* hijo1 = crearPersona("Carlos");
    struct Persona* hijo2 = crearPersona("Ana");

    struct Persona* nieto1 = crearPersona("Lautaro");
    struct Persona* nieto2 = crearPersona("Micaela");
    struct Persona* nieto3 = crearPersona("Pedro");
    struct Persona* nieto4 = crearPersona("Sofia");

    // Armamos las relaciones familiares conectando padres con hijos
    agregarHijos(abuelo, hijo1, hijo2);   // Juan es padre de Carlos y Ana
    agregarHijos(hijo1, nieto1, nieto2);  // Carlos es padre de Lautaro y Micaela
    agregarHijos(hijo2, nieto3, nieto4);  // Ana es padre de Pedro y Sofia

    // Árbol resultante:
    // Juan
    //  ├─ Carlos
    //  │   ├─ Lautaro
    //  │   └─ Micaela
    //  └─ Ana
    //      ├─ Pedro
    //      └─ Sofia

    // Imprimimos el árbol completo arrancando desde el abuelo (la raíz), nivel 0
    printf("Árbol de descendencia:\n");
    imprimirArbol(abuelo, 0);

    return 0;
}
