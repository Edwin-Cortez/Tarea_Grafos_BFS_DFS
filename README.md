# Tarea\_Grafos\_BFS\_DFS



\# Laboratorio de Estructuras de Datos: Recorridos de Grafos (BFS \& DFS)



Este repositorio contiene la resolución e implementación práctica de 16 ejercicios de grafos no dirigidos, evaluando y comparando los algoritmos de búsqueda en amplitud (\*\*BFS\*\*) y búsqueda en profundidad (\*\*DFS\*\*). 



El proyecto incluye un análisis comparativo de rendimiento, control de memoria y abstracción entre dos lenguajes: \*\*C++ Puro\*\* (gestión manual) y \*\*Java\*\* (utilizando el Framework de Colecciones estándar).



\---



\## 🛠️ Arquitectura del Repositorio



El código se ha organizado de forma modular respetando una estructura limpia y fácil de navegar:



\*`/cpp`\*\*: Contiene la infraestructura nativa basada en punteros, structs personalizados y listas enlazadas dinámicas en C++ sin utilizar la librería estándar (STL).

\*`/java`\*\*: Contiene la solución equivalente en Java implementada dentro del paquete estructurado `ejercicio\_grafos` empleando colecciones nativas (`HashMap`, `ArrayList`, `Queue`, `LinkedList`).



\---



\## 🧪 Análisis Técnico: C++ vs Java



\### Respuestas al Cuestionario de la Guía



1\. \*\*¿Qué estructuras se implementaron manualmente en C++?\*\*

&#x20;  Se diseñaron e implementaron desde cero las estructuras primitivas utilizando punteros y memoria dinámica en el Heap: un nodo de lista enlazada para simular las \*\*Listas de Adyacencia\*\*, un puntero doble para el arreglo de listas, y una estructura de \*\*Cola Dinámica FIFO\*\* para gestionar el recorrido en amplitud (BFS).



2\. \*\*¿Qué estructuras ya existen en Java?\*\*

&#x20;  Java provee estas estructuras completamente optimizadas dentro del paquete `java.util`: `HashMap` para indexar las llaves de los nodos, `ArrayList` para manejar colecciones de tamaño dinámico como listas de vecinos, y las interfaces `Queue` acopladas a objetos `LinkedList` para el control de flujo FIFO en BFS.



3\. \*\*¿Cuál código es más largo y por qué?\*\*

&#x20;  El código en \*\*C++ Puro\*\* es considerablemente más largo (aproximadamente un 70% más de líneas). Esto se debe a la necesidad de declarar la lógica de bajo nivel de los nodos, punteros de enlace, constructores dinámicos y, de manera crítica, los métodos destructores necesarios para liberar memoria manualmente.



4\. \*\*¿Cuál código es más fácil de entender?\*\*

&#x20;  El código en \*\*Java\*\* destaca por su alta legibilidad. Al abstraer los detalles físicos del hardware y de la memoria, permite al desarrollador leer directamente las intenciones del algoritmo de grafos en lugar de la mecánica interna de los punteros.



5\. \*\*¿Cuál lenguaje exige mayor control del programador?\*\*

&#x20;  \*\*C++ Puro\*\*. Coloca toda la responsabilidad de la estabilidad de la aplicación sobre el programador. Un error al manipular un puntero desreferenciado o una dirección de memoria inválida resulta en un colapso directo del programa (\*Segmentation Fault\*).



6\. \*\*¿Qué ventajas tiene C++ en este caso?\*\*

&#x20;  Ofrece un consumo de memoria RAM minimalista y una velocidad de ejecución óptima debido a que no cuenta con la latencia del Recolector de Basura ni el intermediario de la Máquina Virtual (JVM).



7\. \*\*¿Qué ventajas tiene Java en este caso?\*\*

&#x20;  Garantiza una enorme velocidad de desarrollo y seguridad de software. El programador se enfoca en resolver el problema lógico, delegando al entorno la protección contra fugas de memoria y la portabilidad del programa.



8\. \*\*¿Qué sucede si en C++ no se libera memoria correctamente?\*\*

&#x20;  Se produce una \*\*Fuga de Memoria\*\* (\*Memory Leak\*). La memoria asignada mediante el operador `new` se queda retenida permanentemente en el sistema operativo. Si este proceso se ejecuta de manera continua o sobre grafos masivos, terminará agotando la memoria RAM libre de la máquina, forzando un cierre inesperado del programa o del sistema operativo.



9\. \*\*¿Por qué BFS necesita una cola?\*\*

&#x20;  BFS requiere un comportamiento estrictamente \*\*FIFO\*\* (First-In, First-Out). Para visitar el grafo de forma expansiva por niveles concéntricos (en amplitud), es obligatorio procesar y retirar primero los nodos vecinos que fueron descubiertos antes, asegurando el recorrido de radio mínimo de manera uniforme.



10\. \*\*¿Por qué DFS puede resolverse con recursión?\*\*

&#x20;   Porque la naturaleza de DFS requiere un comportamiento de \*\*Pila/Stack\*\* (LIFO: Last-In, First-Out) para explorar una rama hasta su máxima profundidad antes de regresar. La recursión nativa del lenguaje utiliza implícitamente la pila de llamadas del sistema (\*Call Stack\*), eliminando la necesidad de declarar una estructura de pila manual en el código.

