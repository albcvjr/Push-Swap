*Este proyecto ha sido creado como parte del currículo de 42 por dbenjume.*

# Libft
## Descripción

Libft es un proyecto del currículo de 42 cuyo objetivo es crear una biblioteca propia de funciones en C, recreando algunas funciones de la biblioteca estándar de C y desarrollando otras funciones auxiliares.

Este proyecto permite comprender mejor el funcionamiento de las funciones estándar, la gestión de memoria, las cadenas de caracteres, los punteros y las estructuras de datos.

El resultado es una biblioteca llamada libft.a, que puede reutilizarse en futuros proyectos de 42.

## Instrucciones
### Requisitos
Un compilador de C, make, y las librerias unistd.h y stdlib.h

Clona el repositorio y accede al directorio del proyecto:

git clone git@vogsphere-v2.42madrid.com:vogsphere/intra-uuid-f37c0521-5f30-4e85-8076-9b4b76f35c50-7703945-dbenjume

cd Libft

Compila la biblioteca ejecutando:
make

Esto genera el archivo libft.a, que contiene las funciones compiladas de la biblioteca.

### Otros comandos
También puedes utilizar:

make clean: elimina los archivos objeto (.o).

make fclean: elimina los archivos objeto y la biblioteca generada.

make re: limpia y vuelve a compilar la biblioteca.

### Uso de la biblioteca
Para utilizar Libft en un programa C, incluye la cabecera correspondiente:

#include "libft.h"

Compila tu programa junto con la biblioteca:

cc main.c -L. -lft -I. -o programa

Ejecuta el programa:
./programa

En este ejemplo, main.c es tu archivo de prueba y libft.h es la cabecera de la biblioteca.

## Recursos
### Documentación y referencias
Manual de funciones de Linux (man): documentación de funciones y llamadas del sistema.

PDF oficial de Libft de 42: referencia principal para conocer los requisitos y las funciones obligatorias del proyecto.
### Uso de inteligencia artificial

La inteligencia artificial se ha utilizado como herramienta de apoyo para hacer el README.

### Documentación de funciones

#### Funciones de caracteres

| Función | Prototipo | Descripción |
|---|---|---|
| `ft_isalpha` | `int ft_isalpha(int c)` | Devuelve el valor 1 si `c` es una letra ASCII (`A-Z` o `a-z`); en caso contrario, devuelve 0. |
| `ft_isdigit` | `int ft_isdigit(int c)` | Devuelve el valor 1 si `c` es un dígito decimal (`0-9`); en caso contrario, devuelve 0. |
| `ft_isalnum` | `int ft_isalnum(int c)` | Devuelve el valor 1 si `c` es una letra ASCII o un dígito decimal; en caso contrario, devuelve 0. |
| `ft_isascii` | `int ft_isascii(int c)` | Devuelve el valor 1 si `c` está entre 0 y 127, ambos incluidos; en caso contrario, devuelve 0. |
| `ft_isprint` | `int ft_isprint(int c)` | Devuelve el valor 1 si `c` es un carácter ASCII imprimible (32-126); en caso contrario, devuelve 0. |
| `ft_toupper` | `int ft_toupper(int c)` | Convierte una letra minúscula ASCII en mayúscula. Si no corresponde, devuelve el valor original. |
| `ft_tolower` | `int ft_tolower(int c)` | Convierte una letra mayúscula ASCII en minúscula. Si no corresponde, devuelve el valor original. |

#### Funciones de cadenas

| Función | Prototipo | Descripción |
|---|---|---|
| `ft_strlen` | `size_t ft_strlen(const char *s)` | Calcula la longitud de una cadena sin contar el carácter nulo `\\0`. |
| `ft_strlcpy` | `size_t ft_strlcpy(char *dst, const char *src, size_t size)` | Copia como máximo `size - 1` caracteres, termina en nulo si `size > 0` y devuelve la longitud completa de `src`. |
| `ft_strlcat` | `size_t ft_strlcat(char *dst, const char *src, size_t size)` | Concatena cadenas con límite de tamaño. Devuelve la longitud que intentaría crear según las reglas de `strlcat`. |
| `ft_strchr` | `char *ft_strchr(const char *s, int c)` | Busca la primera aparición de `c`, incluido el carácter nulo final. Devuelve un puntero a la coincidencia o `NULL`. |
| `ft_strrchr` | `char *ft_strrchr(const char *s, int c)` | Busca la última aparición de `c`, incluido el carácter nulo final. Devuelve un puntero a la coincidencia o `NULL`. |
| `ft_strncmp` | `int ft_strncmp(const char *s1, const char *s2, size_t n)` | Compara como máximo `n` bytes. Devuelve un valor negativo, cero o positivo según el resultado de la comparación. |
| `ft_strnstr` | `char *ft_strnstr(const char *big, const char *little, size_t len)` | Busca `little` dentro de los primeros `len` caracteres de `big`. Si `little` está vacía, devuelve `big`. |
| `ft_strdup` | `char *ft_strdup(const char *s)` | Reserva memoria y crea una copia de `s`, incluido el terminador nulo. Devuelve `NULL` si falla la reserva. |
| `ft_substr` | `char *ft_substr(char const *s, unsigned int start, size_t len)` | Crea una subcadena desde `start` con una longitud máxima de `len`. Devuelve una cadena nueva o `NULL` si falla la reserva. |
| `ft_strjoin` | `char *ft_strjoin(char const *s1, char const *s2)` | Reserva memoria y devuelve una cadena que contiene `s1` seguida de `s2`. |
| `ft_strtrim` | `char *ft_strtrim(char const *s1, char const *set)` | Elimina del principio y del final de `s1` los caracteres que aparecen en `set`. |
| `ft_split` | `char **ft_split(char const *s, char c)` | Divide `s` usando `c` como delimitador. Devuelve un array de cadenas terminado en `NULL`. |
| `ft_strmapi` | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char))` | Aplica `f` a cada carácter, pasando su índice, y devuelve una cadena nueva con los resultados. |
| `ft_striteri` | `void ft_striteri(char *s, void (*f)(unsigned int, char *))` | Aplica `f` a cada carácter de la cadena original, pasando su índice y un puntero al carácter modificable. |

#### Funciones de memoria

| Función | Prototipo | Descripción |
|---|---|---|
| `ft_memset` | `void *ft_memset(void *b, int c, size_t len)` | Rellena los primeros `len` bytes de memoria con el byte indicado por `c`. Devuelve `b`. |
| `ft_bzero` | `void ft_bzero(void *s, size_t n)` | Establece a cero los primeros `n` bytes de memoria. |
| `ft_memcpy` | `void *ft_memcpy(void *dst, const void *src, size_t n)` | Copia `n` bytes desde `src` hasta `dst`. Las regiones no deben solaparse. |
| `ft_memmove` | `void *ft_memmove(void *dst, const void *src, size_t len)` | Copia `len` bytes y permite el solapamiento entre origen y destino. |
| `ft_memchr` | `void *ft_memchr(const void *s, int c, size_t n)` | Busca el byte indicado en los primeros `n` bytes. Devuelve un puntero a la coincidencia o `NULL`. |
| `ft_memcmp` | `int ft_memcmp(const void *s1, const void *s2, size_t n)` | Compara los primeros `n` bytes como valores `unsigned char`. Devuelve un valor negativo, cero o positivo. |
| `ft_calloc` | `void *ft_calloc(size_t nmemb, size_t size)` | Reserva memoria para `nmemb` elementos de `size` bytes e inicializa todos los bytes a cero. Debe evitarse el desbordamiento de la multiplicación. |

#### Funciones de conversión

| Función | Prototipo | Descripción |
|---|---|---|
| `ft_atoi` | `int ft_atoi(const char *nptr)` | Convierte una cadena en un entero, ignorando los espacios iniciales y considerando un signo opcional. |
| `ft_itoa` | `char *ft_itoa(int n)` | Convierte un entero en una cadena decimal terminada en `\\0`. Devuelve una cadena nueva o `NULL` si falla la reserva. |

#### Funciones de salida

| Función | Prototipo | Descripción |
|---|---|---|
| `ft_putchar_fd` | `void ft_putchar_fd(char c, int fd)` | Escribe un carácter en el descriptor de archivo indicado. |
| `ft_putstr_fd` | `void ft_putstr_fd(char *s, int fd)` | Escribe una cadena en el descriptor indicado, sin añadir un salto de línea. |
| `ft_putendl_fd` | `void ft_putendl_fd(char *s, int fd)` | Escribe una cadena seguida de un salto de línea. |
| `ft_putnbr_fd` | `void ft_putnbr_fd(int n, int fd)` | Escribe la representación decimal de un entero en el descriptor indicado. |

#### Funciones listas enlazadas

La estructura definida en `libft.h` es:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

| Función | Prototipo | Descripción |
|---|---|---|
| `ft_lstnew` | `t_list *ft_lstnew(void *content)` | Crea un nodo nuevo con el contenido indicado y `next` inicializado a `NULL`. |
| `ft_lstadd_front` | `void ft_lstadd_front(t_list **lst, t_list *new)` | Inserta un nodo al principio de la lista. |
| `ft_lstsize` | `int ft_lstsize(t_list *lst)` | Devuelve el número de nodos de la lista. |
| `ft_lstlast` | `t_list *ft_lstlast(t_list *lst)` | Devuelve el último nodo o `NULL` si la lista está vacía. |
| `ft_lstadd_back` | `void ft_lstadd_back(t_list **lst, t_list *new)` | Inserta un nodo al final de la lista. |
| `ft_lstdelone` | `void ft_lstdelone(t_list *lst, void (*del)(void *))` | Aplica `del` al contenido y libera el nodo. No libera nodos posteriores. |
| `ft_lstclear` | `void ft_lstclear(t_list **lst, void (*del)(void *))` | Libera el contenido y todos los nodos de la lista y establece `*lst` a `NULL`. |
| `ft_lstiter` | `void ft_lstiter(t_list *lst, void (*f)(void *))` | Aplica `f` al contenido de cada nodo. |
| `ft_lstmap` | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))` | Crea una lista nueva aplicando `f` a cada contenido. Si falla la creación, libera la lista nueva parcialmente creada con `del`. |
