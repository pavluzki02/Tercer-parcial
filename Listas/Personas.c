#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Nodo de la lista: representa UNA persona
struct Persona
{
  char nombre[50];
  char apellido[50];
  int dni;
  struct Persona *siguiente; // puntero al siguiente nodo de la lista
};

// Crea un nodo nuevo y lo agrega COMO PRIMERO de la lista
void insertarAlInicio(struct Persona **cabeza, const char *nombre, const char *apellido, int dni)
{
  struct Persona *nuevoNodo = (struct Persona *)malloc(sizeof(struct Persona)); // reservamos memoria para el nodo
  strcpy(nuevoNodo->nombre, nombre);
  strcpy(nuevoNodo->apellido, apellido);
  nuevoNodo->dni = dni;
  nuevoNodo->siguiente = *cabeza; // el nuevo nodo apunta a lo que antes era la cabeza
  *cabeza = nuevoNodo;            // ahora la cabeza es el nodo nuevo
}

// Crea un nodo nuevo y lo agrega AL FINAL de la lista
void insertarAlFinal(struct Persona **cabeza, const char *nombre, const char *apellido, int dni)
{
  struct Persona *nuevoNodo = (struct Persona *)malloc(sizeof(struct Persona));
  strcpy(nuevoNodo->nombre, nombre);
  strcpy(nuevoNodo->apellido, apellido);
  nuevoNodo->dni = dni;
  nuevoNodo->siguiente = NULL; // como va al final, no apunta a nada

  if (*cabeza == NULL) // si la lista está vacía, este nodo es la cabeza
  {
    *cabeza = nuevoNodo;
    return;
  }

  // recorremos hasta el último nodo (el que tiene siguiente == NULL)
  struct Persona *temp = *cabeza;
  while (temp->siguiente != NULL)
  {
    temp = temp->siguiente;
  }
  temp->siguiente = nuevoNodo; // lo conectamos al final
}

// Busca una persona por DNI y la elimina de la lista
void eliminarPersona(struct Persona **cabeza, int dni)
{
  struct Persona *temp = *cabeza;
  struct Persona *anterior = NULL; // vamos guardando el nodo de atrás para poder saltearlo después

  while (temp != NULL && temp->dni != dni) // recorremos hasta encontrar el dni o llegar al final
  {
    anterior = temp;
    temp = temp->siguiente;
  }

  if (temp == NULL)
    return; // no se encontró el dni, no hay nada que eliminar

  if (anterior == NULL) // la persona a eliminar es la cabeza
  {
    *cabeza = temp->siguiente;
  }
  else // está en medio o al final
  {
    anterior->siguiente = temp->siguiente; // saltamos el nodo a eliminar
  }

  free(temp); // liberamos la memoria del nodo eliminado
}

// Recorre la lista buscando un DNI. Devuelve 1 si lo encuentra, 0 si no
int buscar(struct Persona *cabeza, int dni)
{
  struct Persona *temp = cabeza;
  while (temp != NULL)
  {
    if (temp->dni == dni)
    {
      return 1; // encontrado
    }
    temp = temp->siguiente;
  }
  return 0; // recorrió toda la lista y no lo encontró
}

// Recorre e imprime todos los nodos de la lista
void mostrarLista(struct Persona *nodo)
{
  while (nodo != NULL)
  {
    printf("%s %s (DNI: %d) -> ", nodo->nombre, nodo->apellido, nodo->dni);
    nodo = nodo->siguiente;
  }
  printf("NULL\n"); // así se ve claro dónde termina la lista
}

int main()
{
  struct Persona *lista = NULL; // lista vacía al arrancar

  // insertarAlInicio agrega siempre adelante, por eso el orden queda invertido:
  // primero entra Juan -> queda [Juan]
  // después entra Maria -> queda [Maria, Juan]
  insertarAlInicio(&lista, "Juan", "Perez", 12345678);
  insertarAlInicio(&lista, "Maria", "Gomez", 87654321);

  // insertarAlFinal agrega siempre atrás, respetando el orden de llamada
  insertarAlFinal(&lista, "Carlos", "Lopez", 11223344);
  insertarAlFinal(&lista, "Ana", "Martinez", 55667788);

  printf("Lista actual:\n");
  mostrarLista(lista);

  eliminarPersona(&lista, 87654321); // borramos a Maria por su dni
  printf("Luego de eliminar DNI 87654321:\n");
  mostrarLista(lista);

  // probamos la función buscar con un dni que sabemos que existe
  if (buscar(lista, 11223344))
  {
    printf("La persona con DNI 11223344 está en la lista.\n");
  }
  else
  {
    printf("La persona con DNI 11223344 no está en la lista.\n");
  }

  return 0;
}
