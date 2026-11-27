*Este proyecto ha sido creado como parte del currículo de 42 por dbenjume y acuevas.*

# Push_swap

## Descripción

Push_swap es un proyecto de 42 escrito en C. Recibe una secuencia de enteros y genera una secuencia de operaciones para ordenarla en el stack `a`, utilizando el stack `b` como apoyo. Puede seleccionar la estrategia según el desorden inicial o recibirla mediante `--simple`, `--medium` o `--complex`. La opción `--bench` añade a la salida un resumen de la estrategia, el desorden y los contadores de operaciones.

## Instrucciones

### Requisitos

- `cc`
- `make`

### Compilación

Desde la raíz del repositorio:

```sh
make
```

Esto genera `push_swap` y compila la biblioteca incluida en `libft/`.

### Ejecución

```sh
./push_swap 4 2 7 1 3
./push_swap --simple 4 2 7 1 3
./push_swap --bench 4 2 7 1 3
./push_swap --complex --bench 4 2 7 1 3
```

Las opciones de estrategia son `--simple`, `--medium` y `--complex`; `--bench` activa el resumen. Si no se indica una estrategia, el programa elige una a partir del índice de desorden.

### Reglas de Make

```sh
make        # compila push_swap
make clean  # elimina los archivos objeto
make fclean # elimina push_swap, objetos y biblioteca
make re     # recompila desde cero
```

## Operaciones disponibles

| Operación | Efecto |
|---|---|
| `sa`, `sb`, `ss` | Intercambia los dos primeros elementos de `a`, `b` o ambos. |
| `pa`, `pb` | Pasa el primer elemento de un stack al principio del otro. |
| `ra`, `rb`, `rr` | Rota `a`, `b` o ambos hacia arriba: el primer elemento pasa al final. |
| `rra`, `rrb`, `rrr` | Rota `a`, `b` o ambos hacia abajo: el último elemento pasa al principio. |

## Estrategias y algoritmos

El desorden se calcula como el porcentaje de pares que aparecen en orden inverso. Internamente se guarda en una escala de 0 a 10000, equivalente a porcentajes con dos decimales. La selección automática compara el valor con 20 (0,20) y 50 (0,50).

| Desorden | Estrategia automática | Complejidad indicada |
|---|---|---|
| Menor que 20% | Simple: selección del mínimo | O(n²) |
| Desde 20% hasta menos de 50% | Medium: chunks | O(n√n) |
| 50% o superior | Complex: radix binario | O(n log n) |

### Simple: selección del mínimo

En cada iteración se localiza el mínimo de `a`, se rota `a` hasta llevarlo al principio y se ejecuta `pb`. Una vez extraídos los elementos, `pa` los devuelve a `a` en orden ascendente. Utiliza `ra`, `pb` y `pa`; su coste es cuadrático por las búsquedas y rotaciones repetidas.

### Medium: chunks

Se divide el conjunto restante en grupos de tamaño aproximado a √n. Para cada grupo se buscan los siguientes valores mínimos, se recorren los elementos de `a` con `ra` hasta encontrar los miembros del grupo y se pasan a `b` con `pb`. Después se localiza repetidamente el máximo de `b`, se rota `b` con `rb` hasta ponerlo arriba y se devuelve a `a` con `pa`; puede usar `rrb` para recolocar los elementos que quedaron por debajo del máximo. Utiliza `ra`, `pb`, `rb`, `rrb` y `pa`, con coste aproximado O(n√n) en operaciones.

### Complex: radix binario

Los valores se normalizan a índices consecutivos según su orden, lo que permite procesar números sin que influya su magnitud o signo. En cada pasada se examina un bit del índice: los elementos cuyo bit es 0 pasan de `a` a `b` con `pb`, y los de bit 1 se mantienen en `a` mediante `ra`. Al terminar la pasada, los elementos de `b` vuelven a `a` con `pa`. Se repite para todos los bits necesarios para representar el índice máximo. Utiliza `ra`, `pb` y `pa`; el número de pasadas crece como log n y el coste es O(n log n).

## Documentación de funciones

Las siguientes tablas describen las funciones propias del proyecto declaradas en `includes/push_swap.h` y las operaciones implementadas en `src/`. Las funciones de `libft` y `ft_printf` se documentan en sus respectivos módulos.

### Operaciones de stacks

| Función | Prototipo | Descripción |
|---|---|---|
| `ft_sa` | `void ft_sa(t_benchmark *benchmark)` | Intercambia los dos primeros índices de `a` e imprime `sa`. |
| `ft_sb` | `void ft_sb(t_benchmark *benchmark)` | Intercambia los dos primeros índices de `b` e imprime `sb`. |
| `ft_ss` | `void ft_ss(t_benchmark *benchmark)` | Intercambia los dos primeros índices de ambos stacks e imprime `ss`. |
| `ft_pa` | `void ft_pa(t_benchmark *benchmark)` | Pasa el primer índice de `b` a `a` e imprime `pa`. |
| `ft_pb` | `void ft_pb(t_benchmark *benchmark)` | Pasa el primer índice de `a` a `b` e imprime `pb`. |
| `ft_ra` | `void ft_ra(t_benchmark *benchmark)` | Rota `a` hacia arriba e imprime `ra`. |
| `ft_rb` | `void ft_rb(t_benchmark *benchmark)` | Rota `b` hacia arriba e imprime `rb`. |
| `ft_rr` | `void ft_rr(t_benchmark *benchmark)` | Rota ambos stacks hacia arriba e imprime `rr`. |
| `ft_rra` | `void ft_rra(t_benchmark *benchmark)` | Rota `a` hacia abajo e imprime `rra`. |
| `ft_rrb` | `void ft_rrb(t_benchmark *benchmark)` | Rota `b` hacia abajo e imprime `rrb`. |
| `ft_rrr` | `void ft_rrr(t_benchmark *benchmark)` | Rota ambos stacks hacia abajo e imprime `rrr`. |

### Algoritmos de ordenación

| Función | Prototipo | Descripción |
|---|---|---|
| `ft_selection_sort` | `int ft_selection_sort(t_benchmark *benchmark)` | Ordena mediante extracción repetida del mínimo; corresponde a `--simple`. |
| `ft_chunk_sort` | `int ft_chunk_sort(t_benchmark *benchmark)` | Ordena agrupando valores en chunks de tamaño aproximado √n; corresponde a `--medium`. |
| `ft_radix_sort` | `int ft_radix_sort(t_benchmark *benchmark)` | Ordena índices normalizados examinando sus bits; corresponde a `--complex`. |

### Listas y valores

| Función | Prototipo | Descripción |
|---|---|---|
| `ft_pop_last` | `t_list *ft_pop_last(t_list **list)` | Desvincula y devuelve el último nodo de una lista. |
| `ft_pop_first` | `t_list *ft_pop_first(t_list **list)` | Desvincula y devuelve el primer nodo de una lista. |
| `ft_pop_node` | `t_list *ft_pop_node(t_list **list, t_list *node)` | Desvincula y devuelve el nodo indicado si pertenece a la lista. |
| `ft_lstreduce` | `t_list *ft_lstreduce(t_list *list, t_list *(*f)(t_list *, t_list *))` | Recorre la lista y combina nodos sucesivos mediante la función reductora `f`. |
| `ft_compute_disorder` | `unsigned int ft_compute_disorder(t_list *list)` | Calcula el porcentaje interno de pares fuera de orden, escalado de 0 a 10000. |
| `ft_min` | `t_list *ft_min(t_list *node1, t_list *node2)` | Devuelve el nodo con el menor entero entre los dos recibidos. |
| `ft_max` | `t_list *ft_max(t_list *node1, t_list *node2)` | Devuelve el nodo con el mayor entero entre los dos recibidos. |
| `ft_isinlst` | `t_list *ft_isinlst(t_list *list, void *value)` | Busca un nodo cuyo campo `content` sea el mismo puntero que `value`. |
| `ft_sqrt` | `unsigned int ft_sqrt(unsigned int number)` | Devuelve la raíz cuadrada entera de `number`. |
| `ft_add_node` | `int ft_add_node(t_benchmark *benchmark, char *arg)` | Convierte el argumento en entero y añade nodos de valor e índice al benchmark. |
| `ft_update_indexes` | `void ft_update_indexes(t_benchmark *benchmark)` | Calcula para cada elemento su índice relativo al orden de los valores. |

### Entrada, benchmark y salida

| Función | Prototipo | Descripción |
|---|---|---|
| `ft_init_benchmark` | `void ft_init_benchmark(t_benchmark *benchmark)` | Inicializa los stacks, la estrategia, los contadores y el resto del estado. |
| `ft_update_benchmark` | `int ft_update_benchmark(char *arg, t_benchmark *benchmark)` | Interpreta una opción o un argumento numérico y actualiza el benchmark. |
| `ft_calculate_benchmark` | `void ft_calculate_benchmark(t_benchmark *benchmark)` | Calcula el desorden y selecciona automáticamente una estrategia si no se especificó. |
| `ft_print_benchmark` | `void ft_print_benchmark(t_benchmark *benchmark)` | Imprime el desorden, la estrategia, el total y el desglose de operaciones. |
| `ft_clear_benchmark` | `void ft_clear_benchmark(t_benchmark *benchmark)` | Libera las listas de valores e índices asociadas al benchmark. |
| `ft_strisint` | `int ft_strisint(char *str)` | Comprueba si la cadena coincide con la representación decimal de un entero. |
| `ft_printfe` | `int ft_printfe(char const *format, ...)` | Imprime texto con formato; los especificadores admitidos se implementan en `ft_printf`. |

## Contribuciones

Proyecto realizado en pareja. El historial y las cabeceras muestran aportaciones de ambos integrantes en varios módulos.

| Login | Áreas principales reflejadas en el repositorio |
|---|---|
| `acuevas` | Operaciones y utilidades de listas, cálculo del desorden, estrategias y pruebas de apoyo. |
| `dbenjume` | Estructura inicial, parser y gestión de argumentos, benchmark, selección de estrategia y utilidades. |

## Recursos

- Subject de Push_swap de 42: referencia de las operaciones permitidas y los requisitos del proyecto.
- Documentación de C y de las operaciones de listas enlazadas.
- Baraja de cartas: recurso práctico para visualizar el orden relativo de los elementos y las pasadas de radix.

### Uso de inteligencia artificial

La inteligencia artificial se ha utilizado como apoyo para redactar y revisar este README.
