#include <stdio.h>
//Factorial de un número
// El factorial de n (n!) es el producto de todos los números desde 1 hasta n.
// Por definición, 0! = 1 y 1! = 1, por eso esos dos casos van juntos como caso base.
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // Caso base: frena la recursión
    } else {
        // Caso recursivo: n! = n * (n-1)!
        // Ejemplo con n=4: 4 * factorial(3) = 4 * (3 * factorial(2)) = ... = 4*3*2*1 = 24
        return n * factorial(n - 1); // Llamada recursiva
    }
}

int main() {
    int num = 4;
    printf("El factorial de %d es %d\n", num, factorial(num)); // imprime: El factorial de 4 es 24
    return 0;
}
