*Este proyecto ha sido creado como parte del currículo de 42 por dbenjume.*

# ft\_printf

## Descripción

ft\_printf es un proyecto del currículo de 42 cuyo objetivo es recrear el comportamiento de la función `printf` de la biblioteca estándar de C.

El proyecto consiste en desarrollar una función propia, llamada `ft_printf`, capaz de mostrar por pantalla diferentes tipos de datos mediante una cadena de formato y una cantidad variable de argumentos.

Esta implementación permite trabajar con funciones variádicas en C mediante `stdarg.h`, comprender el tratamiento de diferentes tipos de datos, realizar conversiones numéricas y gestionar la escritura de caracteres y cadenas.

El resultado es una biblioteca llamada `libftprintf.a`, que contiene la implementación de `ft_printf` y las funciones necesarias de Libft para su funcionamiento.

La función devuelve el número de caracteres escritos por pantalla, incluyendo los caracteres normales de la cadena de formato y los correspondientes a cada conversión.

## Instrucciones

### Requisitos

Un compilador de C, como `cc` o `gcc`, `make` y las bibliotecas estándar `stdarg.h` y `unistd.h`.

El proyecto también necesita Libft, que se encuentra en el directorio `libft`.

Clona el repositorio y accede al directorio del proyecto:

```bash
git clone <URL_DEL_REPOSITORIO> ft_printf
cd ft_printf
```

### Compilación

Para compilar la biblioteca, ejecuta:

```bash
make
```

Esto genera el archivo `libftprintf.a`, que contiene los archivos objeto de ft\_printf y las funciones de Libft necesarias para su funcionamiento.

El Makefile compila los archivos fuente de `src/` y construye la biblioteca de la siguiente manera:

1. Comprueba y compila primero Libft mediante `make -C ./libft`.
2. Copia `libft.a` como base de `libftprintf.a`.
3. Añade los archivos objeto de ft\_printf mediante `ar rcs`.

### Otros comandos

También puedes utilizar:

- `make clean`: elimina los archivos objeto (`.o`) del proyecto y ejecuta la limpieza de Libft.
- `make fclean`: elimina los archivos objeto y la biblioteca `libftprintf.a`, además de limpiar Libft.
- `make re`: realiza una limpieza completa y vuelve a compilar la biblioteca.

### Uso de la biblioteca

Para utilizar ft\_printf en otro programa C, incluye la cabecera correspondiente:

```c
#include "ft_printf.h"
```

La función tiene el siguiente prototipo:

```c
int ft_printf(const char *format, ...);
```

Compila tu programa junto con la biblioteca:

```bash
cc -Wall -Wextra -Werror -I./src -I./libft main.c -L. -lftprintf -o programa
```

En este ejemplo:

- `main.c` es el archivo que contiene tu función `main`.
- `-I./src` permite encontrar la cabecera `ft_printf.h`.
- `-I./libft` permite encontrar la cabecera de Libft incluida por `ft_printf.h`.
- `-L.` indica dónde se encuentra la biblioteca compilada.
- `-lftprintf` enlaza el archivo `libftprintf.a`.
- `-o programa` establece el nombre del ejecutable.

No es necesario enlazar `libft.a` por separado, ya que sus funciones se incorporan a `libftprintf.a` durante la ejecución del Makefile.

### Ejemplo de uso

```c
#include "ft_printf.h"

int main(void)
{
    int count;

    count = ft_printf("Hola %s, tienes %d puntos.\n", "42", 100);
    ft_printf("Caracteres escritos: %d\n", count);
    return (0);
}
```

Compila el programa:

```bash
cc -Wall -Wextra -Werror -I./src -I./libft main.c -L. -lftprintf -o programa
```

Ejecuta el programa:

```bash
./programa
```

Salida:

```text
Hola 42, tienes 100 puntos.
Caracteres escritos: 28
```

## Recursos

### Documentación y referencias

- Manual de funciones de Linux (`man`): documentación de las funciones y llamadas al sistema utilizadas en C.
- [`printf(3)`](<https://man7.org/linux/man-pages/man3/printf.3.html>): documentación de la función original de la biblioteca estándar.
- [`stdarg.h`](<https://en.cppreference.com/w/c/variadic.html>): documentación sobre el tratamiento de funciones con un número variable de argumentos.
- [`write(2)`](<https://man7.org/linux/man-pages/man2/write.2.html>): documentación sobre la escritura de datos mediante descriptores de archivo.
- [`va_start`](<https://en.cppreference.com/w/c/variadic/va_start.html>), [`va_arg`](<https://en.cppreference.com/w/c/variadic/va_arg.html>) y [`va_end`](<https://en.cppreference.com/w/c/variadic/va_end.html>): documentación de las macros utilizadas para gestionar los argumentos variádicos.
- Enunciado oficial de ft\_printf de 42: referencia principal para conocer los requisitos específicos del proyecto.

### Uso de inteligencia artificial

La inteligencia artificial se ha utilizado como herramienta de apoyo para hacer el README.

## Documentación de funciones

### Función principal

| Función | Prototipo | Descripción |
| --- | --- | --- |
| `ft_printf` | `int ft_printf(const char *format, ...)` | Reproduce el comportamiento básico de `printf`. Analiza la cadena de formato, identifica las conversiones, obtiene los argumentos correspondientes y escribe el resultado por la salida estándar. Devuelve el número de caracteres escritos. |

### Funciones de conversión

| Función | Prototipo | Descripción |
| --- | --- | --- |
| `ft_flag_c` | `int ft_flag_c(char arg)` | Escribe un carácter individual y devuelve 1. |
| `ft_flag_s` | `int ft_flag_s(char *arg)` | Escribe una cadena de caracteres y devuelve su longitud. Si recibe `NULL`, escribe `(null)`. |
| `ft_flag_p` | `int ft_flag_p(size_t arg)` | Escribe una dirección de memoria en hexadecimal minúsculo, precedida por `0x`. Si el argumento es nulo, escribe `(nil)`. |
| `ft_flag_d` | `int ft_flag_d(int arg)` | Escribe un número entero con signo en base decimal y devuelve el número de caracteres escritos. |
| `ft_flag_i` | `int ft_flag_i(int arg)` | Escribe un número entero con signo en base decimal y devuelve el número de caracteres escritos. |
| `ft_flag_u` | `int ft_flag_u(unsigned int arg)` | Escribe un número entero sin signo en base decimal. |
| `ft_flag_x` | `int ft_flag_x(unsigned int arg)` | Escribe un número entero sin signo en hexadecimal utilizando letras minúsculas. |
| `ft_flag_xc` | `int ft_flag_xc(unsigned int arg)` | Escribe un número entero sin signo en hexadecimal utilizando letras mayúsculas. |
| `ft_flag_bad` | `int ft_flag_bad(char arg)` | Escribe el carácter `%` seguido del especificador no reconocido y devuelve 0. |

## Flags y especificadores de formato

Los especificadores permiten indicar a `ft_printf` cómo debe interpretar y mostrar cada argumento.

Para utilizarlos, se escribe el símbolo `%` seguido del especificador correspondiente dentro de la cadena de formato.

| Flag | Tipo de dato | Descripción | Ejemplo |
| --- | --- | --- | --- |
| `%c` | `char` | Muestra un único carácter. | `ft_printf("%c", 'A');` |
| `%s` | `char *` | Muestra una cadena de caracteres. | `ft_printf("%s", "Hola");` |
| `%p` | Dirección de memoria | Muestra una dirección en hexadecimal minúsculo precedida por `0x`. | `ft_printf("%p", ptr);` |
| `%d` | `int` | Muestra un número entero con signo en base decimal. | `ft_printf("%d", -42);` |
| `%i` | `int` | Muestra un número entero con signo en base decimal. | `ft_printf("%i", 42);` |
| `%u` | `unsigned int` | Muestra un número entero sin signo en base decimal. | `ft_printf("%u", 42u);` |
| `%x` | `unsigned int` | Muestra un número entero en hexadecimal utilizando letras minúsculas. | `ft_printf("%x", 255);` |
| `%X` | `unsigned int` | Muestra un número entero en hexadecimal utilizando letras mayúsculas. | `ft_printf("%X", 255);` |
| `%%` | Ninguno | Muestra el carácter `%` sin consumir ningún argumento. | `ft_printf("100%%");` |

### Especificadores no reconocidos

Cuando se encuentra un especificador que no está implementado, la función escribe el símbolo `%` seguido del carácter desconocido.

Por ejemplo:

```c
ft_printf("%z");
```

Salida:

```text
%z
```

En esta implementación, el tratamiento de especificadores desconocidos no forma parte de las conversiones estándar de `printf`.

## Algoritmo y decisiones técnicas

### Explicación detallada

El algoritmo de ft\_printf se basa en el recorrido de la cadena de formato y en la identificación de los especificadores de conversión.

La función principal recibe una cadena de formato y un número variable de argumentos. Para acceder a estos argumentos utiliza las macros proporcionadas por `stdarg.h`.

El procesamiento se realiza de la siguiente manera:

1. **Inicialización de argumentos:** se utiliza `va_start` para preparar la lista de argumentos variádicos.
2. **Búsqueda de especificadores:** se utiliza `ft_strchr` para localizar el siguiente carácter `%` dentro de la cadena de formato.
3. **Escritura del texto normal:** los caracteres que aparecen antes del especificador se escriben directamente mediante `write`.
4. **Identificación de la conversión:** se consulta el carácter situado después de `%` y se selecciona la función correspondiente.
5. **Obtención del argumento:** mediante `va_arg` se obtiene el argumento con el tipo adecuado.
6. **Conversión y escritura:** se llama a la función encargada de representar el argumento y se suma el número de caracteres escritos.
7. **Continuación del procesamiento:** se actualiza la posición de lectura y se busca el siguiente especificador.
8. **Finalización:** cuando no quedan más especificadores, se escribe el resto de la cadena y se utiliza `va_end` para finalizar el tratamiento de los argumentos.

### Organización de las funciones

La implementación está dividida en diferentes archivos para separar la lógica principal de las conversiones.

- `ft_printf.c`: contiene la función principal, encargada de recorrer la cadena de formato, obtener los argumentos y seleccionar la conversión correspondiente.
- `ft_flag_c.c`: gestiona la conversión de caracteres.
- `ft_flag_s.c`: gestiona la conversión de cadenas.
- `ft_flag_p.c`: gestiona la representación de direcciones de memoria.
- `ft_flag_d.c` y `ft_flag_i.c`: gestionan los enteros con signo.
- `ft_flag_u.c`: gestiona los enteros sin signo.
- `ft_flag_x.c` y `ft_flag_xc.c`: gestionan las conversiones hexadecimales.
- `ft_flag_bad.c`: gestiona los especificadores no reconocidos.
- `ft_putuint_map_fd.c`: permite escribir números sin signo utilizando una base definida mediante una cadena de caracteres.
- `ft_putsizet_map_fd.c`: permite escribir valores de tipo `size_t` utilizando una base definida mediante una cadena de caracteres.

### Algoritmo de conversión numérica

Para convertir números a diferentes bases se utiliza un algoritmo recursivo basado en la división y el resto.

Dado un número `n` y una base `b`, se realizan las siguientes operaciones:

- Se divide el número entre la base para obtener los dígitos de mayor orden.
- Se repite el proceso recursivamente hasta que el cociente sea cero.
- Se utiliza el resto de la división para obtener el dígito correspondiente.
- Se consulta una cadena de caracteres que determina cómo representar cada dígito.

Por ejemplo, para representar el número decimal 255 en hexadecimal:

```text
255 / 16 = 15, resto 15
15 / 16  = 0,  resto 15
```

Utilizando el mapa hexadecimal `0123456789abcdef`, ambos restos corresponden a la letra `f`, obteniendo:

```text
ff
```

Este procedimiento permite reutilizar el mismo algoritmo para distintas bases, cambiando únicamente la cadena de caracteres utilizada como mapa.

### Estructuras de datos utilizadas

La implementación no necesita definir estructuras de datos propias.

Se utilizan principalmente:

- **Cadena de formato (****`const char *format`****):** contiene el texto que se debe mostrar y los especificadores que determinan las conversiones.
- **Lista de argumentos (****`va_list args`****):** permite recorrer los argumentos variables recibidos por `ft_printf`.
- **Puntero de búsqueda (****`const char *needle`****):** señala la posición del siguiente especificador `%` encontrado en la cadena.
- **Índice de posición (****`size_t start`****):** almacena la posición desde la que debe continuar el procesamiento.
- **Contador (****`int size`****):** acumula el número total de caracteres escritos.
- **Mapas de conversión (****`char *map`****):** contienen los caracteres utilizados para representar los dígitos de cada base numérica.

### Justificación del algoritmo y las estructuras de datos

Se ha elegido un procesamiento basado en la búsqueda de los especificadores mediante `ft_strchr`, ya que permite localizar directamente el siguiente punto de conversión sin tener que comprobar individualmente cada carácter de la cadena.

El uso de `va_list` permite implementar una función con un número variable de argumentos, que es la característica principal de `printf`.

La separación de las conversiones en funciones independientes facilita la organización del código, evita concentrar toda la lógica en una única función y permite añadir o modificar conversiones sin alterar excesivamente el funcionamiento principal.

Para las conversiones numéricas se ha elegido un algoritmo recursivo basado en divisiones sucesivas porque permite obtener los dígitos en el orden correcto sin necesitar invertir una cadena posteriormente.

El uso de mapas de conversión permite reutilizar el mismo procedimiento para diferentes bases numéricas, como decimal y hexadecimal, tanto en minúsculas como en mayúsculas.

Esta organización ofrece las siguientes ventajas:

- **Modularidad:** cada conversión tiene su propia función.
- **Reutilización:** el algoritmo de conversión numérica funciona con diferentes bases.
- **Simplicidad:** la función principal se centra en interpretar la cadena de formato y distribuir el trabajo.
- **Flexibilidad:** permite ampliar la implementación añadiendo nuevos especificadores.
- **Eficiencia:** las conversiones numéricas tienen un coste lineal respecto al número de dígitos representados.

