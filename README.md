ARBOL DE SUCESION REAL 

Este proyecto implementa un sistema de registro y sucesión basado en árboles binarios. Permite mantener un registro de los descendientes de un rey, calcular automáticamente la sucesión según ciertas reglas, y realizar modificaciones en los nodos del árbol.

FUNCIONALIDADES

Cargar datos desde un archivo CSV:

El programa lee los datos de sucesión desde un archivo llamado sucesion.csv y los convierte en un árbol binario.
Mostrar la línea de sucesión actual:

Muestra los nodos vivos en el orden de primogenitura.
Reasignar automáticamente al nuevo rey:

Si el rey actual muere, el programa reasigna automáticamente al nuevo rey basado en reglas definidas.
Modificar los datos de un nodo:

Permite cambiar atributos como nombre, apellido, edad, género, y estado de vida (excepto el ID y el ID del padre).
Menú interactivo:

Permite al usuario ejecutar las funciones principales del programa y seguir ejecutándolo hasta que decida salir.

ESTRUCTURA DEL PROYECTO

arbol_sucesion/
├── bin/
│   ├── arbol_sucesion.exe   # Ejecutable generado
│   ├── sucesion.csv         # Datos de prueba
├── src/
│   ├── arbol_binario.cpp    # Implementación del árbol binario
│   ├── arbol_binario.h      # Definición de la clase ArbolBinario
│   ├── nodo.cpp             # Implementación de la clase Nodo
│   ├── nodo.h               # Definición de la clase Nodo
│   ├── utils.cpp            # Funciones auxiliares (cargar CSV, etc.)
│   ├── utils.h              # Definiciones de funciones auxiliares
│   ├── main.cpp             # Menú interactivo y pruebas principales
├── README.md                # Información sobre el proyecto

REGLAS DE SUCESION

1. Si el rey muere:

Se asigna como rey el primer primogénito vivo en su árbol.
Si no tiene hijos vivos, se busca al primer primogénito vivo del árbol de su hermano.
Si no hay hermanos vivos, se busca en el árbol del tío.
Si no hay descendientes, se busca el primer ancestro con dos hijos y se elige como rey al primer primogénito vivo de su árbol.
Si no hay primogénitos vivos, se siguen las mismas reglas para los hijos segundos.

2. Si el rey actual tiene más de 70 años:

Se pasa la corona automáticamente al primer primogénito vivo de su árbol.

INSTRUCCIONES PARA EJECUTAR

1. Compilar el programa
Ejecuta el siguiente comando desde la raíz del proyecto:
g++ -o bin/arbol_sucesion.exe src/*.cpp

2. Ejecutar el programa
Ejecuta el programa con:
./bin/arbol_sucesion.exe

3. Menú Interactivo
Sigue las instrucciones del menú interactivo para:

- Cargar datos desde el archivo CSV.
- Mostrar la línea de sucesión actual.
- Reasignar al nuevo rey automáticamente.
- Modificar los datos de un nodo.
- Salir del programa.

ARCHIVO CSV DE PRUEBA
El archivo sucesion.csv incluye datos de ejemplo con el siguiente formato:

id,name,last_name,gender,age,id_father,is_dead,was_king,is_king
1,Juan,Primero,H,68,0,0,1,1
2,Carlos,Primero,H,45,1,0,0,0
3,Ana,Primera,M,42,1,0,0,0
4,Luis,Segundo,H,25,2,0,0,0
5,Marta,Tercera,M,22,3,0,0,0

COLUMNAS

id: Identificador único del nodo.
name: Nombre del individuo.
last_name: Apellido del individuo.
gender: Género (H para hombres, M para mujeres).
age: Edad actual.
id_father: ID del padre.
is_dead: Indica si está muerto (1 para sí, 0 para no).
was_king: Indica si fue rey en algún momento (1 para sí, 0 para no).
is_king: Indica si es el rey actual (1 para sí, 0 para no).

EJEMPLO DE USO 

1. Cargar el árbol:
- Selecciona la opción 1 en el menú para cargar datos desde sucesion.csv.

2. Mostrar la línea de sucesión:
- Selecciona la opción 2 para ver los nodos vivos en el orden de primogenitura.

3. Reasignar al nuevo rey:
- Marca al rey actual como muerto en el archivo CSV (is_dead = 1) y selecciona la opción 3 para reasignar.

4. Modificar un nodo:
- Selecciona la opción 4, ingresa el ID del nodo y proporciona nuevos datos.

