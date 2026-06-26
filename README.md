# Apunte Teórico — Estructuras de Datos y Programación en C

> Material de repaso para examen teórico. Sin código, solo definiciones, condiciones y conceptos.

## Índice

- [1. Conceptos Generales de Estructuras de Datos](#1-conceptos-generales-de-estructuras-de-datos)
  - [1.1 Estructura de datos](#11-estructura-de-datos)
  - [1.2 Estructuras estáticas](#12-estructuras-estáticas)
  - [1.3 Estructuras dinámicas](#13-estructuras-dinámicas)
  - [1.4 Estructuras lineales](#14-estructuras-lineales)
  - [1.5 Estructuras no lineales](#15-estructuras-no-lineales)
- [2. Punteros](#2-punteros)
  - [2.1 Puntero](#21-puntero)
  - [2.2 Operador de dirección (&)](#22-operador-de-dirección-)
  - [2.3 Operador de desreferencia (*)](#23-operador-de-desreferencia-)
  - [2.4 Memoria dinámica (malloc / free)](#24-memoria-dinámica-malloc--free)
  - [2.5 Puntero a puntero (doble puntero)](#25-puntero-a-puntero-doble-puntero)
  - [2.6 Puntero nulo (NULL)](#26-puntero-nulo-null)
  - [2.7 Puntero colgante (dangling pointer)](#27-puntero-colgante-dangling-pointer)
  - [2.8 Fuga de memoria (memory leak)](#28-fuga-de-memoria-memory-leak)
- [3. Listas Enlazadas Simples](#3-listas-enlazadas-simples)
  - [3.1 Lista simplemente enlazada](#31-lista-simplemente-enlazada)
  - [3.2 Nodo (lista simple)](#32-nodo-lista-simple)
  - [3.3 Apuntador inicial (PRIM / cabeza)](#33-apuntador-inicial-prim--cabeza)
  - [3.4 Apuntador externo](#34-apuntador-externo)
  - [3.5 Lista ordenada](#35-lista-ordenada)
  - [3.6 Lista desordenada](#36-lista-desordenada)
  - [3.7 Operaciones básicas sobre listas](#37-operaciones-básicas-sobre-listas)
  - [3.8 Insertar al principio](#38-insertar-al-principio)
  - [3.9 Insertar al final](#39-insertar-al-final)
  - [3.10 Insertar en el medio](#310-insertar-en-el-medio)
  - [3.11 Eliminar al principio](#311-eliminar-al-principio)
  - [3.12 Eliminar al final](#312-eliminar-al-final)
  - [3.13 Eliminar en el medio](#313-eliminar-en-el-medio)
  - [3.14 Búsqueda secuencial](#314-búsqueda-secuencial)
- [4. Listas Circulares](#4-listas-circulares)
  - [4.1 Lista circular](#41-lista-circular)
  - [4.2 Lista circular simple](#42-lista-circular-simple)
  - [4.3 Lista circular doble](#43-lista-circular-doble)
- [5. Listas Doblemente Enlazadas](#5-listas-doblemente-enlazadas)
  - [5.1 Lista doblemente encadenada](#51-lista-doblemente-encadenada)
  - [5.2 Nodo (lista doble)](#52-nodo-lista-doble)
  - [5.3 Apuntador inicial y final (PRIM / ULT)](#53-apuntador-inicial-y-final-prim--ult)
  - [5.4 Operaciones de listas dobles](#54-operaciones-de-listas-dobles)
  - [5.5 Recorrido bidireccional](#55-recorrido-bidireccional)
- [6. Árboles](#6-árboles)
  - [6.1 Árbol](#61-árbol)
  - [6.2 Nodo (árbol)](#62-nodo-árbol)
  - [6.3 Nodo padre](#63-nodo-padre)
  - [6.4 Nodo hijo](#64-nodo-hijo)
  - [6.5 Nodo hermano](#65-nodo-hermano)
  - [6.6 Nodo raíz](#66-nodo-raíz)
  - [6.7 Nodo hoja](#67-nodo-hoja)
  - [6.8 Nodo interior o rama](#68-nodo-interior-o-rama)
  - [6.9 Nivel](#69-nivel)
  - [6.10 Altura](#610-altura)
  - [6.11 Peso](#611-peso)
  - [6.12 Grado de un árbol](#612-grado-de-un-árbol)
  - [6.13 Árbol binario](#613-árbol-binario)
  - [6.14 Árboles binarios distintos](#614-árboles-binarios-distintos)
  - [6.15 Árboles binarios similares](#615-árboles-binarios-similares)
  - [6.16 Árboles binarios equivalentes](#616-árboles-binarios-equivalentes)
  - [6.17 Árbol binario completo](#617-árbol-binario-completo)
  - [6.18 Profundidad de un árbol](#618-profundidad-de-un-árbol)
  - [6.19 Árbol binario equilibrado (balanceado)](#619-árbol-binario-equilibrado-balanceado)
  - [6.20 Árbol binario de búsqueda (ABB)](#620-árbol-binario-de-búsqueda-abb)
  - [6.21 Recorrido Inorden](#621-recorrido-inorden)
  - [6.22 Recorrido Preorden](#622-recorrido-preorden)
  - [6.23 Recorrido Posorden](#623-recorrido-posorden)
  - [6.24 Subárbol](#624-subárbol)
- [7. Funciones en C](#7-funciones-en-c)
  - [7.1 Función](#71-función)
  - [7.2 Subprograma / módulo](#72-subprograma--módulo)
  - [7.3 Modularidad](#73-modularidad)
  - [7.4 Cohesión](#74-cohesión)
  - [7.5 Acoplamiento](#75-acoplamiento)
  - [7.6 Función main](#76-función-main)
  - [7.7 Llamada a función (invocación)](#77-llamada-a-función-invocación)
  - [7.8 Argumento / parámetro](#78-argumento--parámetro)
  - [7.9 Parámetro formal vs. argumento actual](#79-parámetro-formal-vs-argumento-actual)
  - [7.10 Sentencia return](#710-sentencia-return)
  - [7.11 Función de tipo void / procedimiento](#711-función-de-tipo-void--procedimiento)
  - [7.12 Función predefinida](#712-función-predefinida)
  - [7.13 Función definida por el usuario](#713-función-definida-por-el-usuario)
  - [7.14 Variable local](#714-variable-local)
  - [7.15 Variable global](#715-variable-global)
  - [7.16 Pasaje de parámetros por valor](#716-pasaje-de-parámetros-por-valor)
  - [7.17 Pasaje de parámetros por referencia](#717-pasaje-de-parámetros-por-referencia)
  - [7.18 Declaración / prototipo de función](#718-declaración--prototipo-de-función)
  - [7.19 Tipo de retorno](#719-tipo-de-retorno)
  - [7.20 Efecto colateral](#720-efecto-colateral)
- [8. Recursividad e Iteración](#8-recursividad-e-iteración)
  - [8.1 Recursión / función recursiva](#81-recursión--función-recursiva)
  - [8.2 Iteración](#82-iteración)
  - [8.3 Caso base](#83-caso-base)
  - [8.4 Caso recursivo](#84-caso-recursivo)
  - [8.5 Pila de llamadas (call stack)](#85-pila-de-llamadas-call-stack)
  - [8.6 Marco de pila (stack frame)](#86-marco-de-pila-stack-frame)
  - [8.7 Desbordamiento de pila (stack overflow)](#87-desbordamiento-de-pila-stack-overflow)
  - [8.8 Bucle infinito](#88-bucle-infinito)
  - [8.9 Comparación Recursión vs. Iteración](#89-comparación-recursión-vs-iteración)
  - [8.10 Casos clásicos de recursividad](#810-casos-clásicos-de-recursividad)
- [9. Glosario General (A–Z)](#9-glosario-general-az)

---

## 1. Conceptos Generales de Estructuras de Datos

### 1.1 Estructura de datos
Forma de organizar y almacenar información en la memoria de una computadora, de manera que pueda ser utilizada de forma eficiente. Se clasifican según cómo se almacenan en memoria (estáticas o dinámicas) y según la relación entre sus elementos (lineales o no lineales).

### 1.2 Estructuras estáticas
Aquellas en las que el tamaño ocupado en memoria se define antes de que el programa se ejecute (en tiempo de compilación) y no puede ser modificado durante la ejecución del programa. Ejemplos: arreglos (arrays), registros (structs) de tamaño fijo, pilas y colas implementadas sobre arreglos.

### 1.3 Estructuras dinámicas
Aquellas en las que el tamaño puede modificarse durante la ejecución del programa; teóricamente no hay límite a su tamaño, salvo el que impone la memoria disponible en la computadora. Se las llama dinámicas porque pueden cambiar de forma y de tamaño durante la ejecución. Ejemplos: listas enlazadas, árboles, pilas y colas implementadas con punteros.

### 1.4 Estructuras lineales
Aquellas en las que los elementos ocupan lugares sucesivos en la estructura, y cada uno tiene un único sucesor y un único predecesor (están ubicados uno al lado del otro, relacionados de forma lineal). Ejemplos: arreglos, registros, pilas, colas, listas.

### 1.5 Estructuras no lineales
Aquellas en las que cada elemento puede tener más de un sucesor. Ejemplos: árboles, gráficas (grafos).

---

## 2. Punteros

### 2.1 Puntero
Variable que contiene la dirección de memoria de otra variable. Es un tipo de dato que "apunta" a otro valor almacenado en memoria; en lugar de contener el dato directamente, contiene la ubicación (dirección) donde ese dato reside.

### 2.2 Operador de dirección (&)
Operador que se utiliza para obtener la dirección de memoria de una variable. Se usa, por ejemplo, al pasar parámetros por referencia a una función.

### 2.3 Operador de desreferencia (*)
Operador que se utiliza para acceder al valor almacenado en la dirección de memoria a la que apunta un puntero. También se usa en la declaración de un puntero, para indicar que la variable es de tipo puntero.

### 2.4 Memoria dinámica (malloc / free)
Memoria que se reserva y libera durante la ejecución del programa (no en tiempo de compilación). `malloc` reserva un bloque de memoria del tamaño solicitado y devuelve un puntero a él (o NULL si no hay memoria disponible); `free` libera esa memoria para que pueda ser reutilizada. Por cada reserva con malloc debe existir, en algún momento, una liberación con free.

### 2.5 Puntero a puntero (doble puntero)
Un puntero que almacena la dirección de memoria de otro puntero. Se utiliza, por ejemplo, cuando una función necesita modificar el puntero externo (como la cabeza de una lista) que vive en otra función, ya que en C el paso de parámetros es por valor y sin un doble puntero los cambios no se reflejarían fuera de la función.

### 2.6 Puntero nulo (NULL)
Valor especial que indica que un puntero no apunta a ninguna dirección de memoria válida. Se utiliza para inicializar punteros y para marcar el final de una estructura dinámica (por ejemplo, el último nodo de una lista simple apunta a NULL).

### 2.7 Puntero colgante (dangling pointer)
Puntero que continúa apuntando a una dirección de memoria que ya fue liberada (con free) o que dejó de ser válida. Acceder a través de un puntero colgante produce comportamiento indefinido.

### 2.8 Fuga de memoria (memory leak)
Situación en la que se reserva memoria dinámica (malloc) y nunca se libera (free), aun cuando ya no se necesita. Con el tiempo, esto agota la memoria disponible del programa.

---

## 3. Listas Enlazadas Simples

### 3.1 Lista simplemente enlazada
También llamada lista lineal o lista enlazada simple. Es una estructura de datos lineal y dinámica que utiliza un conjunto de nodos para almacenar datos en secuencia, enlazados mediante un apuntador o referencia.

### 3.2 Nodo (lista simple)
Unidad básica de una lista enlazada. Tiene 2 secciones: el dato (simple o compuesto) y un apuntador o referencia que enlaza al siguiente nodo en la secuencia lógica.

### 3.3 Apuntador inicial (PRIM / cabeza)
Puntero externo a la lista que siempre señala al primer nodo de la misma. Permite el acceso a toda la estructura.

### 3.4 Apuntador externo
Puntero que vive fuera de los nodos de la estructura (por ejemplo, en la función que la utiliza) y que referencia algún punto clave de la lista, como el primero o el último nodo.

### 3.5 Lista ordenada
Lista en la que se recorren lógicamente los nodos para ubicar la posición definitiva de un nuevo nodo, de manera que se mantenga el orden lógico de los datos (por ejemplo, de menor a mayor).

### 3.6 Lista desordenada
Lista en la que el nuevo dato simplemente se agrega al final (o al principio) de la estructura, sin tener en cuenta ningún criterio de orden.

### 3.7 Operaciones básicas sobre listas
Crear una lista; insertar un elemento (al principio, al final o en el medio); eliminar un elemento (al principio, al final o en el medio); mostrar (recorrer) los elementos; buscar un elemento dentro de la lista.

### 3.8 Insertar al principio
Operación en la que el nuevo nodo pasa a ser el primero de la lista: su puntero "siguiente" debe apuntar al nodo que actualmente es el primero, y luego el puntero externo (PRIM) debe actualizarse para apuntar al nuevo nodo. El orden de los pasos es crítico para no perder la referencia al resto de la lista.

### 3.9 Insertar al final
Operación que requiere recorrer la lista completa hasta encontrar el último nodo (aquel cuyo puntero "siguiente" es NULL), enlazar el nuevo nodo desde allí, y dejar el puntero "siguiente" del nuevo nodo en NULL, ya que pasa a ser el nuevo último elemento.

### 3.10 Insertar en el medio
Operación (en listas ordenadas) que recorre la lista comparando el dato a insertar con los valores existentes, hasta encontrar la posición donde corresponde insertarlo, enlazando el nuevo nodo entre el nodo anterior y el nodo actual.

### 3.11 Eliminar al principio
Operación que guarda la referencia al primer nodo, actualiza el puntero PRIM para que apunte al segundo nodo, y libera la memoria del nodo eliminado.

### 3.12 Eliminar al final
Operación que recorre la lista guardando siempre el nodo anterior, hasta llegar al último nodo; el puntero "siguiente" del anteúltimo nodo pasa a NULL, y se libera la memoria del nodo eliminado.

### 3.13 Eliminar en el medio
Operación que recorre la lista buscando el nodo a eliminar, manteniendo el puntero al nodo anterior; el nodo anterior debe enlazarse directamente con el nodo siguiente al eliminado, y luego se libera la memoria de este último.

### 3.14 Búsqueda secuencial
Recorrido de la lista desde el primer nodo, comparando el dato de cada nodo con el valor buscado, hasta encontrarlo o hasta llegar a NULL (lo que indica que el elemento no existe en la lista).

---

## 4. Listas Circulares

### 4.1 Lista circular
Estructura de datos lineal donde el último elemento apunta al primer elemento en lugar de terminar en NULL, formando un ciclo o "anillo" continuo. La condición de corte de un recorrido no puede ser "hasta llegar a NULL" (porque nunca se llega), sino "hasta volver al nodo de partida".

### 4.2 Lista circular simple
Lista circular que permite un recorrido unidireccional (solo hacia adelante); el último nodo apunta al primero.

### 4.3 Lista circular doble
Lista circular en la que el último nodo apunta al primero y el primero apunta al último, permitiendo moverse en ambas direcciones de manera continua.

---

## 5. Listas Doblemente Enlazadas

### 5.1 Lista doblemente encadenada
Estructura de datos dinámica compuesta por un conjunto de nodos en secuencia, enlazados mediante dos apuntadores: uno hacia adelante (al siguiente nodo) y otro hacia atrás (al nodo anterior).

### 5.2 Nodo (lista doble)
Tiene 3 secciones: el dato (simple o compuesto), un apuntador que enlaza al siguiente nodo, y un apuntador que enlaza al nodo anterior.

### 5.3 Apuntador inicial y final (PRIM / ULT)
La lista doble tiene un apuntador inicial (PRIM) que señala al primer nodo, y un apuntador final (ULT) que señala al último. El puntero "anterior" del primer nodo y el puntero "siguiente" del último nodo deben apuntar siempre a NULL.

### 5.4 Operaciones de listas dobles
Añadir o insertar elementos (al inicio, al final o en el medio); buscar o localizar elementos; borrar elementos; moverse a través de la lista en ambos sentidos (siguiente y anterior).

### 5.5 Recorrido bidireccional
Capacidad propia de las listas dobles (y circulares dobles) de recorrer la estructura tanto hacia adelante (usando el puntero "siguiente") como hacia atrás (usando el puntero "anterior"), a diferencia de las listas simples, que solo permiten recorrido hacia adelante.

---

## 6. Árboles

### 6.1 Árbol
Estructura jerárquica y en forma no lineal, aplicada sobre una colección de elementos u objetos llamados nodos (Cairó &amp; Guardati, 2006). Es una estructura dinámica (puede cambiar de forma y tamaño durante la ejecución) y no lineal (cada elemento puede tener más de un sucesor). Es muy utilizada como método eficiente para búsquedas grandes y complejas; casi todos los sistemas operativos almacenan sus archivos en árboles o estructuras similares.

### 6.2 Nodo (árbol)
Cada elemento que contiene el árbol.

### 6.3 Nodo padre
Todo nodo que tiene al menos un hijo.

### 6.4 Nodo hijo
Todo nodo que tiene un padre.

### 6.5 Nodo hermano
Nodos que comparten un mismo padre en común dentro de la estructura.

### 6.6 Nodo raíz
El primer nodo de un árbol. Solo un nodo del árbol puede ser la raíz.

### 6.7 Nodo hoja
Todo nodo que no tiene hijos. Siempre se encuentran en los extremos de la estructura.

### 6.8 Nodo interior o rama
Todo nodo que no es la raíz y que además tiene al menos un hijo.

### 6.9 Nivel
Distancia de un nodo respecto de la raíz. Un árbol vacío tiene 0 niveles; el nivel de la raíz es 1; el nivel de cada nodo se calcula contando cuántos nodos existen sobre él hasta llegar a la raíz, más 1 (o, de forma inversa, contando los nodos desde la raíz hasta el nodo buscado, más 1).

### 6.10 Altura
Número máximo de niveles que tiene un árbol.

### 6.11 Peso
Número total de nodos que tiene un árbol (la suma de todos los nodos de todos los niveles).

### 6.12 Grado de un árbol
Cantidad máxima de hijos que puede tener cualquier nodo del árbol. Un árbol binario es, por definición, un árbol de grado dos.

### 6.13 Árbol binario
Árbol en el que cada nodo puede tener como máximo 2 hijos (un hijo izquierdo y un hijo derecho).

### 6.14 Árboles binarios distintos
Dos árboles binarios son distintos cuando sus estructuras son diferentes.

### 6.15 Árboles binarios similares
Dos árboles binarios son similares cuando sus estructuras son idénticas, pero la información que contienen sus nodos difiere entre sí.

### 6.16 Árboles binarios equivalentes
Árboles que son similares y que, además, sus nodos contienen la misma información.

### 6.17 Árbol binario completo
Árbol binario de profundidad n en el que, para cada nivel del 0 al nivel n-1, hay un conjunto lleno de nodos, y todos los nodos hoja del nivel n ocupan las posiciones más a la izquierda del árbol.

### 6.18 Profundidad de un árbol
Longitud del camino más largo desde la raíz hasta el nodo hoja más alejado. Se calcula contando el número de nodos en esa ruta. Si el árbol está vacío, la profundidad es 0.

### 6.19 Árbol binario equilibrado (balanceado)
Árbol binario de búsqueda que realiza acomodos o balanceos después de inserciones o eliminaciones, para que la diferencia de altura entre subárboles se mantenga controlada y el rendimiento de las operaciones no se degrade cuando el árbol crece de forma descontrolada hacia un extremo.

### 6.20 Árbol binario de búsqueda (ABB)
Árbol binario cuyos nodos están ordenados de tal manera que los datos del subárbol izquierdo de cualquier nodo son menores que el dato de ese nodo, y los del subárbol derecho son mayores. Esta condición debe cumplirse para todos los nodos del árbol, no solo para la raíz. Permite realizar búsquedas de manera similar a la búsqueda binaria utilizada en arreglos. Para construir un ABB a partir de un listado de datos: el primer dato es la raíz; los siguientes se ubican como hijos izquierdos si son menores, o como hijos derechos si son mayores, repitiendo la comparación recursivamente.

### 6.21 Recorrido Inorden
Recorrido de un árbol binario en el orden: subárbol izquierdo, raíz, subárbol derecho. En un árbol binario de búsqueda, este recorrido devuelve los elementos ordenados de menor a mayor.

### 6.22 Recorrido Preorden
Recorrido de un árbol binario en el orden: raíz, subárbol izquierdo, subárbol derecho.

### 6.23 Recorrido Posorden
Recorrido de un árbol binario en el orden: subárbol izquierdo, subárbol derecho, raíz.

### 6.24 Subárbol
Cualquier nodo de un árbol, junto con todos sus descendientes, considerado como un árbol en sí mismo. Todo árbol binario está compuesto por un subárbol izquierdo y un subárbol derecho a partir de su raíz.

---

## 7. Funciones en C

### 7.1 Función
Subprograma que realiza una tarea determinada y bien acotada, a la cual se le pasan datos y que devuelve datos. Se ejecuta cuando se la llama (llamada a la función).

### 7.2 Subprograma / módulo
Parte más pequeña en la que se separa un problema complejo de desarrollo de software, para poder diseñarla, desarrollarla, probarla y modificarla de manera sencilla e independiente del resto de la aplicación.

### 7.3 Modularidad
Técnica de programación estructurada que consiste en dividir la solución de un problema complejo en módulos (funciones o procedimientos) más pequeños y manejables.

### 7.4 Cohesión
Grado en el que cada módulo del sistema se refiere a un único proceso o entidad. A mayor cohesión, mejor (el módulo es más simple de diseñar, programar, probar y mantener). Se logra alta cohesión cuando cada función realiza una única tarea sobre una sola estructura de datos. Test de cohesión: el módulo debe poder describirse con una oración simple, con un solo verbo activo.

### 7.5 Acoplamiento
Grado de relacionamiento de un módulo con los demás módulos del sistema. A menor acoplamiento, mejor. Se logra bajo acoplamiento reduciendo las interacciones entre funciones, la cantidad y complejidad de los parámetros, y minimizando los parámetros por referencia y los efectos colaterales.

### 7.6 Función main
Función obligatoria en todo programa en C. La ejecución del programa siempre comienza por las instrucciones contenidas en main; desde ella se pueden subordinar funciones adicionales.

### 7.7 Llamada a función (invocación)
Acción de acceder a una función desde alguna parte del programa, lo cual provoca que se ejecuten las instrucciones de las que consta dicha función. Una misma función puede llamarse desde varios lugares distintos del programa, y una función puede llamarse a sí misma (recursividad).

### 7.8 Argumento / parámetro
Identificadores especiales mediante los cuales se le pasa información a una función.

### 7.9 Parámetro formal vs. argumento actual
El parámetro formal es la variable declarada en la definición de la función (en el prototipo). El argumento actual (o valor real) es el valor concreto que se pasa al invocar la función. El paso de parámetros en la llamada exige una asignación posicional: el primer argumento se asigna al primer parámetro formal, y así sucesivamente.

### 7.10 Sentencia return
Instrucción que devuelve un valor desde la función y fuerza la salida inmediata de su cuerpo, retornando el control a la siguiente sentencia después de la llamada. Si la función no es de tipo void, debe tener al menos una sentencia return, y el valor devuelto debe ser del mismo tipo (o compatible) con el tipo declarado de la función. Si el tipo no coincide, se convierte automáticamente. Según su declaración, una función devuelve solamente un valor.

### 7.11 Función de tipo void / procedimiento
Función que no devuelve ningún valor. En C no se habla habitualmente de "procedimientos", sino de funciones de tipo void. Una función void no necesariamente tiene sentencia return; si la usa, no debe ir seguida de ningún valor (de lo contrario, el compilador detecta un error).

### 7.12 Función predefinida
Función ya definida en el lenguaje de programación (en sus bibliotecas estándar), que puede utilizarse directamente sin programarla. Ejemplos: pow, strlen, printf, scanf.

### 7.13 Función definida por el usuario
Función que el propio programador implementa, mediante estructuras de control adecuadas, cuando las funciones predefinidas no permiten realizar el cálculo o tarea deseada.

### 7.14 Variable local
Variable definida dentro de las llaves de una función (incluyendo main), que tiene validez únicamente dentro de dicha función.

### 7.15 Variable global
Variable que puede ser usada desde cualquier función durante todo el transcurso del programa. Se define fuera de cualquier función, normalmente debajo de los #include al comienzo del programa.

### 7.16 Pasaje de parámetros por valor
Forma de pasar un parámetro a una función en la que se le pasa, como argumento, el valor de la variable. La función recibe una copia del dato, por lo que cualquier modificación dentro de la función no afecta a la variable original.

### 7.17 Pasaje de parámetros por referencia
Forma de pasar un parámetro a una función en la que se le pasa, como argumento, la dirección de memoria de una variable (obtenida con el operador &). La variable que recibe ese parámetro debe ser un puntero. Permite que la función modifique directamente el valor de la variable original, reflejándose ese cambio fuera de la función.

### 7.18 Declaración / prototipo de función
Especificación que indica el tipo de dato que devuelve la función, su nombre, y el tipo y nombre de cada parámetro que recibe, sin necesariamente incluir el cuerpo completo (cuando se declara antes de main).

### 7.19 Tipo de retorno
Tipo de dato que devuelve una función al finalizar su ejecución (por ejemplo, int, float, void).

### 7.20 Efecto colateral
Modificación que produce una función sobre algo externo a ella (por ejemplo, una variable global, o una variable pasada por referencia), más allá del valor que devuelve mediante return. Minimizar los efectos colaterales contribuye a un menor acoplamiento.

---

## 8. Recursividad e Iteración

### 8.1 Recursión / función recursiva
Función que se llama a sí misma, directa o indirectamente, dentro de su propio cuerpo, para resolver un problema. Estructuralmente, utiliza estructuras condicionales (if-else) para detenerse.

### 8.2 Iteración
Repetición de un bloque de código mediante el uso de estructuras cíclicas explícitas (bucles for, while, do-while).

### 8.3 Caso base
Condición (o conjunto de condiciones) que detiene la recursión sin volver a llamarse a sí misma; es la solución para un caso particular y simple del problema. Puede existir más de un caso base. Si nunca se alcanza, se produce un desbordamiento de pila.

### 8.4 Caso recursivo
Parte de la función recursiva en la que el problema se resuelve llamando nuevamente a la función original, pero acercándose progresivamente al caso base (por ejemplo, decrementando un parámetro o avanzando al siguiente nodo de una estructura).

### 8.5 Pila de llamadas (call stack)
Estructura en la que el sistema guarda la información de cada llamada a función pendiente de finalizar, incluyendo las llamadas recursivas. Cada llamada recursiva genera una copia nueva de la función (sus variables y parámetros), lo que puede consumir gran cantidad de memoria.

### 8.6 Marco de pila (stack frame)
Espacio de memoria reservado en la pila de llamadas para una invocación particular de una función, donde se almacenan sus variables locales y parámetros. La recursión consume memoria de la pila por cada llamada.

### 8.7 Desbordamiento de pila (stack overflow)
Riesgo crítico de la recursión: ocurre cuando el caso base nunca se alcanza (o la recursión es demasiado profunda), agotando el espacio disponible en la pila de llamadas.

### 8.8 Bucle infinito
Riesgo crítico de la iteración: ocurre cuando la condición de continuación de un bucle nunca deja de cumplirse, lo que congela el programa por consumo continuo de CPU.

### 8.9 Comparación Recursión vs. Iteración

| Característica | Recursión | Iteración |
|---|---|---|
| Definición | Una función se llama a sí misma dentro de su propio cuerpo. | Un bloque de código se repite mediante bucles explícitos. |
| Estructura de control | Estructuras condicionales (if-else) para detenerse. | Estructuras cíclicas (for, while, do-while). |
| Condición de parada | Definida por el caso base; si no se alcanza, ocurre un desbordamiento. | Definida por la condición del bucle; si no se cumple, se genera un bucle infinito. |
| Uso de memoria | Alto: consume memoria de la pila (stack) por cada llamada. | Bajo: utiliza la misma memoria asignada, modificando variables existentes. |
| Velocidad / rendimiento | Más lenta: la creación y destrucción de marcos de pila genera sobrecarga. | Más rápida: la ejecución es directa sobre registros y variables locales. |
| Legibilidad del código | Generalmente más corto, limpio y elegante (estilo declarativo). | Puede volverse largo o complejo de leer en problemas lógicos profundos. |
| Riesgo crítico | Desbordamiento de la pila (stack overflow). | Bucle infinito que congela el programa por consumo de CPU. |
| Casos de uso ideales | Estructuras de datos complejas (árboles, grafos), algoritmos tipo Divide y Vencerás. | Recorridos simples, operaciones matemáticas repetitivas, arreglos lineales. |

Conceptos clave de la comparación:
- Tanto la iteración como la recursión se basan en una estructura de control: la iteración utiliza una estructura de repetición; la recursión utiliza una estructura de selección.
- Ambas implican repetición: la iteración la logra de forma explícita (bucle); la recursión la logra mediante llamadas de función repetidas.
- Ambas involucran una prueba de terminación: la iteración termina cuando falla la condición de continuación del ciclo; la recursión termina cuando se reconoce un caso base.
- La recursión tiene desventajas: la sobrecarga de llamadas a función puede ser costosa tanto en tiempo de procesador como en espacio de memoria, ya que cada llamada recursiva genera otra copia de la función.
- La iteración por lo regular ocurre dentro de una sola función, por lo que no se produce la sobrecarga de llamadas repetidas ni la asignación extra de memoria que sí ocurre en la recursión.

### 8.10 Casos clásicos de recursividad
- **Factorial de un número:** el caso base es n=0 o n=1 (factorial = 1); el caso recursivo multiplica n por el factorial de (n-1).
- **Sucesión de Fibonacci:** secuencia descubierta por Leonardo de Pisa (Fibonacci) en el siglo XIII. Comienza con 0 y 1, y cada número siguiente es la suma de los dos anteriores (0, 1, 1, 2, 3, 5, 8, 13, 21, 34…). El caso recursivo de Fibonacci(n) se define como Fibonacci(n-1) + Fibonacci(n-2), con casos base en n=0 y n=1.
- **Recorridos de árboles (inorden, preorden, posorden):** el caso base es que el nodo (subárbol) sea NULL.
- **Recorrido y liberación de listas y árboles:** estructuras dinámicas que se procesan naturalmente de forma recursiva, ya que cada nodo contiene una referencia a la siguiente substructura del mismo tipo.

---

## 9. Glosario General (A–Z)

- **Acoplamiento:** grado de relación de un módulo con los demás; cuanto menor, mejor diseño.
- **Altura (de un árbol):** número máximo de niveles del árbol.
- **Apuntador / Puntero:** variable que almacena una dirección de memoria.
- **Argumento:** valor concreto pasado a una función al invocarla.
- **Árbol:** estructura jerárquica no lineal compuesta por nodos.
- **Árbol binario:** árbol en el que cada nodo tiene como máximo dos hijos.
- **Árbol binario de búsqueda (ABB):** árbol binario ordenado: izquierda menor, derecha mayor.
- **Árbol equilibrado/balanceado:** árbol que se reorganiza para mantener la eficiencia de las operaciones.
- **Bucle infinito:** repetición que nunca termina por falla en la condición de corte.
- **Caso base:** condición que detiene una recursión.
- **Caso recursivo:** paso de una función recursiva que se acerca al caso base.
- **Cohesión:** grado en que un módulo realiza una única tarea bien definida.
- **Dangling pointer (puntero colgante):** puntero que referencia memoria ya liberada.
- **Dato compuesto:** dato formado por varios campos (struct).
- **Dato simple:** dato de un único valor (entero, carácter, etc.).
- **Desbordamiento de pila (stack overflow):** agotamiento de la pila de llamadas por recursión sin caso base alcanzable.
- **Estructura de datos:** forma de organizar información en memoria.
- **Estructura de datos dinámica:** estructura cuyo tamaño cambia en tiempo de ejecución.
- **Estructura de datos estática:** estructura cuyo tamaño se fija en tiempo de compilación.
- **Estructura lineal:** estructura cuyos elementos tienen un único sucesor y predecesor.
- **Estructura no lineal:** estructura cuyos elementos pueden tener más de un sucesor.
- **Free:** función de C que libera memoria reservada dinámicamente.
- **Función:** subprograma que realiza una tarea específica y puede devolver un valor.
- **Función predefinida:** función incluida en las bibliotecas estándar del lenguaje.
- **Función recursiva:** función que se llama a sí misma.
- **Función void:** función que no devuelve ningún valor.
- **Grado de un árbol:** cantidad máxima de hijos permitidos por nodo.
- **Iteración:** repetición de instrucciones mediante bucles explícitos.
- **Lista circular:** lista en la que el último nodo se enlaza con el primero.
- **Lista doblemente enlazada:** lista cuyos nodos tienen puntero al siguiente y al anterior.
- **Lista enlazada (simple):** estructura dinámica de nodos enlazados secuencialmente en una sola dirección.
- **Malloc:** función de C que reserva memoria dinámica.
- **Memoria dinámica:** memoria reservada y liberada durante la ejecución del programa.
- **Memory leak (fuga de memoria):** memoria reservada que nunca se libera.
- **Módulo:** parte independiente y manejable de un programa (función o procedimiento).
- **Modularidad:** técnica de dividir un programa en módulos.
- **Nivel (de un nodo):** distancia de un nodo respecto a la raíz de un árbol.
- **Nodo:** unidad básica de una estructura dinámica (lista o árbol), que contiene un dato y una o más referencias.
- **Nodo hermano:** nodos con el mismo padre.
- **Nodo hijo:** nodo que desciende directamente de otro.
- **Nodo hoja:** nodo sin hijos.
- **Nodo padre:** nodo con al menos un hijo.
- **Nodo raíz:** primer nodo de un árbol.
- **NULL:** valor que indica que un puntero no apunta a ninguna dirección válida.
- **Parámetro:** variable mediante la cual se pasa información a una función.
- **Parámetro formal:** variable declarada en la definición de la función.
- **Pasaje por referencia:** paso de la dirección de memoria de una variable a una función.
- **Pasaje por valor:** paso de una copia del valor de una variable a una función.
- **Peso (de un árbol):** cantidad total de nodos del árbol.
- **Pila de llamadas (call stack):** estructura que registra las llamadas a función pendientes.
- **Procedimiento:** en C, una función de tipo void.
- **Profundidad (de un árbol):** longitud del camino más largo desde la raíz hasta la hoja más alejada.
- **Puntero a puntero:** puntero que apunta a otro puntero.
- **Recorrido inorden:** recorrido de árbol: izquierda, raíz, derecha.
- **Recorrido posorden:** recorrido de árbol: izquierda, derecha, raíz.
- **Recorrido preorden:** recorrido de árbol: raíz, izquierda, derecha.
- **Recursión:** técnica en la que una función se invoca a sí misma.
- **Return:** sentencia que devuelve un valor y finaliza la ejecución de una función.
- **Stack frame (marco de pila):** espacio reservado en la pila para una llamada a función.
- **Subárbol:** árbol formado por un nodo y todos sus descendientes.
- **Variable global:** variable accesible desde cualquier función del programa.
- **Variable local:** variable accesible solo dentro de la función donde fue declarada.
