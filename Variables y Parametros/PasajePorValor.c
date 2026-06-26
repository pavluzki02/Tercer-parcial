/*Pasaje por Valor*/
#include <stdio.h>

// "x" es una COPIA del argumento que se le pasa a la función.
// Cualquier cambio que se haga acá adentro queda en esa copia local,
// no afecta a la variable original que está en main.
void duplicar(int x) {
    x = x * 2; // modificamos la copia local, no el "numero" de main
    printf("Dentro de la funcion: %d\n", x); // acá ya vale 10
}

int main() {
    int numero = 5;
    duplicar(numero); // se le pasa el VALOR de numero (una copia de 5)
    printf("Fuera de la funcion: %d\n", numero); // sigue valiendo 5, no cambió
    return 0;
}
