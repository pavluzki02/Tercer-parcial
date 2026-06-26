/*Pasaje por Referencia*/
#include <stdio.h>

// "x" es un PUNTERO: guarda la dirección de memoria de la variable original.
// Por eso, al usar *x (desreferenciar), estamos accediendo y modificando
// directamente la variable de main, no una copia.
void duplicar(int *x) {
    *x = *x * 2; // modificamos el valor al que apunta x, o sea, "numero" de main
    printf("Dentro de la funcion: %d\n", *x); // acá ya vale 10
}

int main() {
    int numero = 5;
    duplicar(&numero); // le pasamos la DIRECCIÓN de numero (con &), no su valor
    printf("Fuera de la funcion: %d\n", numero); // ahora sí cambió: vale 10
    return 0;
}
