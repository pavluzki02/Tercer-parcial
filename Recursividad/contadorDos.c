#include <stdio.h>

// Función recursiva que cuenta hacia atrás, pero imprime ANTES de hacer el caso base.
// Como el printf está antes del if, se imprime el número en CADA llamada, incluyendo
// la última (cuando numero llega a 0).
void contador(int numero)
{

  printf(" - %d", numero); // imprimimos el número actual (esto pasa siempre, en cada llamada)
  if (numero < 1)
  {
    return; // Caso base: si llegamos a 0 (o menos), frenamos la recursión
  }
  else
  {
    contador(numero - 1); // Caso recursivo: llamamos de nuevo con un número menos
  }
}

int main()
{
  contador(5); // Comenzamos desde 5 -> imprime: " - 5 - 4 - 3 - 2 - 1 - 0"
  return 0;
}
