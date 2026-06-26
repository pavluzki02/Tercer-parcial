#include <stdio.h>
//Contar hacia atrás
// Esta función imprime el número ANTES de hacer la llamada recursiva, y recién
// imprime "¡Listo!" cuando llega al caso base (n == 0). A diferencia de
// contadorDos.c, acá el 0 nunca se imprime como número, directamente se
// muestra el mensaje de que ya terminamos.
void contarAtras(int n) {
    if (n == 0) {
        printf("¡Listo!\n"); // Caso base: cuando llegamos a 0, frenamos la recursión
    } else {
        printf("%d\n", n);          // Mostrar el número actual
        contarAtras(n - 1);         // Llamada recursiva con un número menos
    }
}

int main() {
    contarAtras(5);  // Comenzamos desde 5 -> imprime: 5, 4, 3, 2, 1, ¡Listo!
    return 0;
}
