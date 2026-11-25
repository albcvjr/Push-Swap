*Este proyecto ha sido creado como parte del currículo de 42 por dbenjume y acuevas.*

[English version](README_EN.md)

# Push_swap

## Descripción

Push_swap es un proyecto de 42 en C cuyo objetivo es ordenar una secuencia de enteros en el stack `a`, utilizando un segundo stack `b` y un conjunto limitado de operaciones. El programa calcula el desorden inicial y puede elegir una estrategia automáticamente o recibir una estrategia mediante un argumento.

El proyecto incluye las operaciones de swap, push, rotate y reverse rotate, el cálculo del índice de desorden y un modo de benchmark que muestra la estrategia seleccionada y los contadores de operaciones.

## Instrucciones

### Requisitos

- `cc`
- `make`

### Compilación

Desde la raíz del repositorio:

```sh
make
```

Esto genera el ejecutable `push_swap` y compila la biblioteca incluida en `libft/`.

### Ejecución

Pasa los enteros como argumentos. El programa admite las opciones `--simple`, `--medium`, `--complex` y `--bench`:

```sh
./push_swap 4 2 7 1 3
./push_swap --simple 4 2 7 1 3
./push_swap --bench 4 2 7 1 3
./push_swap --complex --bench 4 2 7 1 3
```

Sin una opción de estrategia, se selecciona una automáticamente según el índice de desorden. `--bench` añade información de benchmark a la salida. Los argumentos numéricos deben ser enteros válidos.

### Reglas de Make

```sh
make        # compila push_swap
make clean  # elimina los objetos de libft
make fclean # elimina push_swap y los objetos/biblioteca de libft
make re     # recompila desde cero
```

## Operaciones disponibles

| Operación | Efecto |
|---|---|
| `sa`, `sb`, `ss` | Intercambia los dos primeros elementos de `a`, `b` o ambos. |
| `pa`, `pb` | Mueve el primer elemento de un stack al otro. |
| `ra`, `rb`, `rr` | Rota `a`, `b` o ambos hacia arriba. |
| `rra`, `rrb`, `rrr` | Rota `a`, `b` o ambos hacia abajo. |

## Estrategias y decisiones

El índice de desorden se calcula contando los pares fuera de orden y dividiéndolos entre el total de pares posibles. El valor interno se expresa en una escala de 0 a 10000; para decidir la estrategia, el código compara ese valor con 20 y 50, correspondientes al 0,2 y 0,5 del subject.

La estrategia automática usa estos umbrales:

| Desorden | Estrategia seleccionada | Complejidad indicada |
|---|---|---|
| Menor que 0,2 | Simple (selección) | O(n²) |
| De 0,2 a menos de 0,5 | Medium (buckets/chunks) | O(n√n) |
| 0,5 o superior | Complex (radix) | O(n log n) |

### Simple: selección del mínimo

La implementación busca el nodo con el valor mínimo de `a`, rota `a` hasta colocarlo al principio, lo mueve a `b` y repite. Al extraer los mínimos en orden ascendente, quedan en `b` en orden inverso; devolverlos a `a` con `pa` produce el orden ascendente. Es una adaptación directa de selection sort a las operaciones permitidas. La búsqueda y los desplazamientos repetidos justifican el coste cuadrático en operaciones.

### Medium: buckets/chunks (pendiente)

El selector reserva esta estrategia para desorden medio. La idea prevista es dividir los valores en rangos y mover cada grupo entre los stacks, limitando los desplazamientos necesarios para insertar o recuperar los elementos. Esto busca un coste intermedio, aproximado a O(n√n) en el modelo del subject.

### Complex: radix (pendiente)

El selector reserva esta estrategia para entradas muy desordenadas. Radix ordena por dígitos o bits, procesando los elementos en pasadas; con índices normalizados, el número de pasadas crece logarítmicamente y el coste esperado es O(n log n) en operaciones.

## Contribuciones

Proyecto realizado en pareja. La implementación se ha trabajado de forma colaborativa y ambos integrantes deben poder explicar el conjunto del proyecto.

| Login | Trabajo reflejado en el repositorio |
|---|---|
| `acuevas` | Operaciones y utilidades de listas enlazadas, cálculo del desorden, ajustes de integración y pruebas de apoyo. |
| `dbenjume` | Estructura inicial y cabeceras de varios módulos; parser y gestión de argumentos, benchmark, selección de estrategia y funciones de ordenación. |

El historial y las cabeceras muestran aportaciones de ambos en varios archivos; este resumen indica las áreas principales y no implica que cada parte se haya desarrollado de forma aislada.

## Recursos

- Subject de Push_swap de 42: requisitos, conjunto de operaciones, modelo de desorden y complejidades solicitadas.
- Baraja de cartas: utilizada como recurso práctico para comprender y visualizar el funcionamiento del algoritmo radix y sus pasadas de ordenación.

### Uso de inteligencia artificial

La IA se ha utilizado como apoyo para redactar este README. La descripción, los comandos y el estado de las estrategias se han contrastado con el código del repositorio y el subject.
