#  Árbol BST Empresarial en C++

##  Descripción

Este proyecto implementa un Árbol Binario de Búsqueda (BST) en C++ para la gestión jerárquica de empleados en una empresa.
Cada empleado se organiza mediante un código numérico único, permitiendo inserciones, búsquedas y recorridos eficientes.

##  Objetivo

Implementar en C++ un Árbol Binario de Búsqueda (BST) para organizar empleados de una empresa usando un código numérico como clave,
permitiendo una estructura jerárquica similar a un organigrama empresarial.

##  Integrantes

| Rol                 | Nombre                                     |
|---------------------|--------------------------------------------|
| Líder               | [Nombre del líder]                         |
| Programador 1       | [Nombre - Implementación Nodo e inserción] |
| Programador 2       | [Nombre - Búsqueda y recorridos]           |
| Programador 3       | [Nombre - Altura y hojas]                  |
| Documentador        | [Nombre - README y capturas]               |
| Expositor           | [Nombre - Presentación]                    |

##  Funcionalidades

| # | Funcionalidad | Descripción |
|---|---------------|-------------|
| 1 | **Insertar empleado** | Agrega un nuevo empleado al árbol ordenado por código |
| 2 | **Buscar empleado** | Localiza un empleado por su código numérico |
| 3 | **Mostrar raíz** | Muestra el empleado que se encuentra en la raíz del árbol |
| 4 | **Recorrido inorden** | Visita: izquierdo → raíz → derecho (orden ascendente) |
| 5 | **Recorrido preorden** | Visita: raíz → izquierdo → derecho |
| 6 | **Recorrido postorden** | Visita: izquierdo → derecho → raíz |
| 7 | **Mostrar altura** | Calcula el número de niveles del árbol |
| 8 | **Mostrar hojas** | Lista todos los nodos sin hijos (empleados sin subordinados) |


##  Estructura del Proyecto

arbol-bst-empresa-cpp/
│
├── README.md # Este archivo
├── src/
│ └── main.cpp # Código fuente completo
└── capturas/ # Capturas de ejecución
├── 01_menu_principal.png
├── 02_insercion.png
├── 03_busqueda.png
├── 04_recorridos.png
└── 05_altura_hojas.png


##  Código Fuente

### Librerías utilizadas
````
#include <iostream>  // Entrada/salida de datos
#include <string>    // Manejo de cadenas (nombre, cargo)

````
#### Estructuras principales ####
*Empleado: Almacena la información de cada trabajador
````
struct Empleado {
    int codigo;      // Clave única para el BST
    string nombre;   // Nombre del empleado
    string cargo;    // Cargo que ocupa
};
````
*Nodo: Representa cada elemento del árbol
````
struct Nodo {
    Empleado dato;           // Información del empleado
    Nodo* izquierdo;         // Apuntador al hijo izquierdo
    Nodo* derecho;           // Apuntador al hijo derecho
};
````
#### Compilación y Ejecución ####
*Requisitos
Compilador de C++ (g++, clang++, o MSVC)

Terminal o consola
# 1. Compilar el programa
g++ src/main.cpp -o arbol

# 2. Ejecutar
./arbol          # En Linux/Mac
arbol.exe        # En Windows

Datos de Prueba Sugeridos
Para probar el árbol, inserte los empleados en el siguiente orden:

|Código |Nombre            |Cargo         |Tipo de nodo |
|-------|------------------|--------------|-------------|
|50	    |Empresa UTA	     |Raíz	        |Raíz         |
|30	    |Gerente Ventas	   |Nodo interno	|Nodo interno |
|70	    |Gerente Finanzas	 |Nodo interno	|Nodo interno |
|20	    |Emp 1	           |Hoja	        |Hoja         |
|40	    |Emp 2	           |Hoja	        |Hoja         |
|60	    |Emp 3	           |Hoja	        |Hoja         |
|80	    |Emp 4	           |Hoja	        |Hoja         |

#### Estructura esperada del árbol  #### 
``
              50 (Raíz)
           /      \
         30        70
        /  \      /  \
      20   40    60   80
   (Hoja)(Hoja)(Hoja)(Hoja)
   
### Menú de Opciones ####

===== MENU PRINCIPAL =====
1. Insertar empleado
2. Buscar empleado por codigo
3. Mostrar raiz
4. Recorrido inorden
5. Recorrido preorden
6. Recorrido postorden
7. Mostrar altura del arbol
8. Mostrar nodos hoja
0. Salir

#### Conceptos Teóricos Aplicados ####

| Concepto	| Definición	                                    | En el proyecto                 |
|-----------|-------------------------------------------------|--------------------------------|
| Raíz	    | Nodo principal del árbol, no tiene padre	      | Empleado con código 50         | 
| Nodo      | interno	Nodo que tiene al menos un hijo	        | Códigos 30 y 70                |
| Hoja	    | Nodo sin hijos (izquierdo y derecho = nullptr)	| Códigos 20, 40, 60, 80         |
| Nivel	    | Distancia desde la raíz + 1	                    | Raíz nivel 1, hijos nivel 2    |
| Altura	  | Máximo número de niveles	                      |Árbol con 3 niveles = altura 3  |

#### Recorridos explicados ####
* Inorden (ascendente): 20, 30, 40, 50, 60, 70, 80
* Preorden (raíz primero): 50, 30, 20, 40, 70, 60, 80
* Postorden (hojas primero): 20, 40, 30, 60, 80, 70, 50
#### Conclusión ####
El Árbol Binario de Búsqueda (BST) implementado permite:

* Organizar empleados de forma jerárquica y eficiente
* Buscar en tiempo O(log n) gracias a la propiedad de ordenamiento
* Visualizar la estructura mediante diferentes recorridos
* Identificar elementos clave como raíz, nodos internos y hojas

Este proyecto demuestra la utilidad práctica de los árboles binarios en problemas reales como organigramas empresariales, 
sistemas de archivos y bases de datos jerárquicas.
