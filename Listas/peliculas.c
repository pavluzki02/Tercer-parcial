#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura de un nodo de la lista: representa UNA película
struct Pelicula
{
  char nombre[100];          // nombre de la peli (hasta 99 caracteres + \0)
  int anio;                  // año de estreno
  struct Pelicula *siguiente; // puntero al próximo nodo de la lista
};

// Prototipos (declaramos antes para poder usarlas en main aunque estén definidas más abajo)
void mosrtarMenu();
void insertarAlInicio(struct Pelicula **cabeza, const char *nombre, int anio);
void insertarAlFinal(struct Pelicula **cabeza, const char *nombre, int anio);
void mostrarLista(struct Pelicula *nodo);
void eliminarNodo(struct Pelicula **cabeza, const char *nombre);
void buscarNodo(struct Pelicula **cabeza, const char *nombre);
void modificarNodo(struct Pelicula **cabeza, const char *nombre, const char *nuevoNombre, int nuevoAnio);

int main()
{
  struct Pelicula *lista = NULL; // arrancamos con la lista vacía (sin cabeza)
  int opcion;
  do
  {
    mosrtarMenu();                 // muestra las opciones en pantalla
    printf("Seleccione una opción: ");
    scanf("%d", &opcion);          // leemos qué opción eligió el usuario
    getchar();                     // Limpiar el buffer de entrada (saca el \n que dejó el scanf)

    switch (opcion)
    {
    case 1: // Insertar al inicio
      printf("Ingrese el nombre de la película: ");
      char nombreNueva[100];
      fgets(nombreNueva, sizeof(nombreNueva), stdin); // leemos toda la línea (permite espacios, a diferencia de scanf)
      nombreNueva[strcspn(nombreNueva, "\n")] = '\0'; // Eliminar el salto de línea que deja fgets

      printf("Ingrese el año de la película: ");
      int anio;
      scanf("%d", &anio);
      getchar(); // Limpiar el buffer de entrada

      insertarAlInicio(&lista, nombreNueva, anio); // llamamos a la función que agrega el nodo al principio
      break;

    case 2: // Mostrar la lista completa
      printf("PELICULAS:\n");
      mostrarLista(lista);
      break;

    case 3: // Eliminar una película por nombre
      printf("Ingrese el nombre de la película a eliminar: ");
      char nombreEliminar[100];
      fgets(nombreEliminar, sizeof(nombreEliminar), stdin);
      nombreEliminar[strcspn(nombreEliminar, "\n")] = '\0'; // Eliminar el salto de línea
      eliminarNodo(&lista, nombreEliminar);
      break;

    case 4: // Insertar al final
      printf("Ingrese el nombre de la película: ");
      char nombreNuevaFinal[100];
      fgets(nombreNuevaFinal, sizeof(nombreNuevaFinal), stdin);
      nombreNuevaFinal[strcspn(nombreNuevaFinal, "\n")] = '\0';
      printf("Ingrese el año de la película: ");
      int anioFinal;
      scanf("%d", &anioFinal);
      getchar();
      insertarAlFinal(&lista, nombreNuevaFinal, anioFinal);
      break;

    case 5: // Buscar una película por nombre
      printf("Ingrese el nombre de la película a buscar: ");
      char nombreBuscar[100];
      fgets(nombreBuscar, sizeof(nombreBuscar), stdin);
      nombreBuscar[strcspn(nombreBuscar, "\n")] = '\0';
      buscarNodo(&lista, nombreBuscar);
      break;

    case 6: // Modificar una película existente (cambia nombre y año)
      printf("Ingrese el nombre de la película a modificar: ");
      char nombreModificar[100];
      fgets(nombreModificar, sizeof(nombreModificar), stdin);
      nombreModificar[strcspn(nombreModificar, "\n")] = '\0';

      printf("Ingrese el nuevo nombre de la película: ");
      char nuevoNombre[100];
      fgets(nuevoNombre, sizeof(nuevoNombre), stdin);
      nuevoNombre[strcspn(nuevoNombre, "\n")] = '\0';

      printf("Ingrese el nuevo año de la película: ");
      int nuevoAnio;
      scanf("%d", &nuevoAnio);
      getchar();
      modificarNodo(&lista, nombreModificar, nuevoNombre, nuevoAnio);
      break;

    case 0: // Salir del programa
      printf("Saliendo...\n");
      break;

    default: // cualquier número que no esté en el menú
      printf("Opción no válida. Intente nuevamente.\n");
    }
  } while (opcion != 0); // repetimos hasta que el usuario elija 0

  return 0;
}

// Crea un nodo nuevo y lo pone COMO PRIMERO de la lista (la cabeza pasa a ser este nodo)
void insertarAlInicio(struct Pelicula **cabeza, const char *nombre, int anio)
{
  struct Pelicula *nuevoNodo = (struct Pelicula *)malloc(sizeof(struct Pelicula)); // pedimos memoria para el nodo nuevo
  strcpy(nuevoNodo->nombre, nombre); // copiamos el nombre recibido al nodo
  nuevoNodo->anio = anio;
  nuevoNodo->siguiente = *cabeza; // el nuevo nodo apunta a lo que antes era la cabeza
  *cabeza = nuevoNodo;            // ahora la cabeza es el nodo nuevo
}

// Crea un nodo nuevo y lo agrega AL FINAL de la lista
void insertarAlFinal(struct Pelicula **cabeza, const char *nombre, int anio)
{
  struct Pelicula *nuevoNodo = (struct Pelicula *)malloc(sizeof(struct Pelicula));
  strcpy(nuevoNodo->nombre, nombre);
  nuevoNodo->anio = anio;
  nuevoNodo->siguiente = NULL; // como va al final, no apunta a nada

  if (*cabeza == NULL) // si la lista está vacía, este nodo pasa a ser la cabeza
  {
    *cabeza = nuevoNodo;
    return;
  }

  // si ya hay elementos, recorremos hasta encontrar el último nodo
  struct Pelicula *temp = *cabeza;
  while (temp->siguiente != NULL)
  {
    temp = temp->siguiente;
  }
  temp->siguiente = nuevoNodo; // el último nodo ahora apunta al nuevo
}

// Recorre la lista nodo por nodo e imprime cada película
void mostrarLista(struct Pelicula *nodo)
{
  while (nodo != NULL)
  {
    printf("%s (%d) \n", nodo->nombre, nodo->anio);
    nodo = nodo->siguiente; // avanzamos al siguiente nodo
  }
  printf("\n");
}

// Busca una película por nombre y muestra si la encontró o no
void buscarNodo(struct Pelicula **cabeza, const char *nombre)
{
  struct Pelicula *temp = *cabeza;

  // avanzamos mientras no lleguemos al final Y el nombre no coincida
  while (temp != NULL && strcmp(temp->nombre, nombre) != 0)
  {
    temp = temp->siguiente;
  }

  if (temp != NULL) // si temp no es NULL, es porque encontramos la peli
  {
    printf("Pelicula encontrada: %s (%d)\n", temp->nombre, temp->anio);
  }
  else
  {
    printf("Pelicula no encontrada: %s\n", nombre);
  }
}

// Busca una película por nombre y le cambia el nombre y el año
void modificarNodo(struct Pelicula **cabeza, const char *nombre, const char *nuevoNombre, int nuevoAnio)
{
  struct Pelicula *temp = *cabeza;

  while (temp != NULL && strcmp(temp->nombre, nombre) != 0) // strcmp devuelve 0 si las cadenas son iguales
  {
    temp = temp->siguiente; // Avanzar al siguiente nodo
  }

  if (temp == NULL)
    return; // No se encontró la película, no hay nada que modificar

  // si llegamos hasta aquí, temp apunta al nodo que hay que modificar
  strcpy(temp->nombre, nuevoNombre);
  temp->anio = nuevoAnio;

  printf("Pelicula modificada: %s (%d)\n", temp->nombre, temp->anio);
}

// Busca una película por nombre y la elimina de la lista (liberando su memoria)
void eliminarNodo(struct Pelicula **cabeza, const char *nombre)
{
  struct Pelicula *temp = *cabeza;     // arranca apuntando a la cabeza
  struct Pelicula *anterior = NULL;    // va guardando el nodo de atrás, para poder "saltear" el que eliminamos

  while (temp != NULL && strcmp(temp->nombre, nombre) != 0) // strcmp devuelve 0 si las cadenas son iguales
  {
    anterior = temp;        // Guardar el nodo anterior
    temp = temp->siguiente; // Avanzar al siguiente nodo
  }

  if (temp == NULL)
    return; // No se encontró la película, no hay nada que borrar

  if (anterior == NULL) // La película a eliminar es la cabeza de la lista
  {
    *cabeza = temp->siguiente; // la cabeza pasa a ser el segundo nodo
  }
  else // La película a eliminar está en medio o al final de la lista
  {
    anterior->siguiente = temp->siguiente; // el anterior se conecta directo con el siguiente, "salteando" a temp
  }

  free(temp); // Liberar la memoria del nodo eliminado (sino queda memoria reservada sin usar)
}

// Imprime el menú de opciones por consola
void mosrtarMenu()
{
  printf("\n");
  printf(" -------------- MENU -------------\n");
  printf("| 1. Agregar película al Inicio   |\n");
  printf("| 2. Mostrar películas            |\n");
  printf("| 3. Eliminar película            |\n");
  printf("| 4. Agregar película al Final    |\n");
  printf("| 5. Buscar película              |\n");
  printf("| 6. Modificar película           |\n");
  printf("| 0. Salir                        |\n");
  printf(" ---------------------------------\n");
}
