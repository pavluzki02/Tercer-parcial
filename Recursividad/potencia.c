#include <stdio.h>

// OJO: a pesar del nombre, esta función NO calcula una potencia (num elevado a algo).
// Lo que hace es calcular el FACTORIAL de num: num * (num-1) * (num-2) * ... * 1
// Es la misma lógica que un factorial clásico, solo que está nombrada "potencia".
int potencia(int num)
{
  if (num < 1)
  {
    return 1; // Caso base: cuando llegamos a 0 (o menos), devolvemos 1 y se frena la recursión
              // devuelve 1 ya q todo num elevado a la potencia d 0 es 1
  }
  else
  {
    // Caso recursivo: multiplicamos num por el resultado de la misma función con num-1
    // Ejemplo con num=3: 3 * potencia(2) = 3 * (2 * potencia(1)) = 3 * (2 * (1 * potencia(0))) = 3*2*1*1 = 6
    return num * potencia(num - 1); // multiplica el num - 1 x si mismo hasta llegar a 1
  }
}

int main()
{
  printf("%d", potencia(3)); // imprime 6 (que es 3! = 3*2*1, NO es 2 elevado a 3 ni nada parecido)
  return 0;
}
