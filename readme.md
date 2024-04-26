### `get_next_line.h`

Este archivo es el encabezado de la biblioteca `get_next_line`. Define las funciones que están disponibles para ser utilizadas por otros archivos, así como la constante `BUFFER_SIZE` que se utiliza para determinar el tamaño del buffer que se lee del archivo.

### `get_next_line_utils.c`

Este archivo contiene las implementaciones de varias funciones auxiliares que son utilizadas por `get_next_line.c`. Estas funciones son:

1. **`ft_strlen`**: Calcula la longitud de una cadena de caracteres.
2. **`ft_strchr`**: Busca el primer carácter en una cadena que coincida con un carácter dado.
3. **`ft_strjoin`**: Concatena dos cadenas de caracteres.
4. **`ft_strlcpy`**: Copia una cadena de caracteres a otra, asegurándose de que la cadena de destino esté terminada en null.

### `get_next_line.c`

Este archivo implementa la función principal `get_next_line`, que lee una línea de un archivo dado por un descriptor de archivo (`fd`). La función utiliza las funciones auxiliares definidas en `get_next_line_utils.c`.

#### Orden de ejecución:

1. **`get_next_line`**: Esta es la función principal que se llama desde el programa principal.
   - Primero, verifica si el descriptor de archivo es válido y si hay algo que leer. Si no es así, libera cualquier memoria asignada a `saved_lines` y retorna `NULL`.
   - Luego, llama a `read_file` para leer el archivo y almacenar el contenido en `saved_lines`.
   - Después, llama a `next_line` para extraer la siguiente línea de `saved_lines` y la almacena en `line`.
   - A continuación, llama a `keep_remain` para mantener solo la parte de `saved_lines` que sigue a la línea extraída.
   - Finalmente, retorna `line`.

2. **`read_file`**: Esta función lee el archivo hasta encontrar una nueva línea o hasta que no haya más datos para leer.
   - Almacena los datos leídos en un buffer y los concatena con `saved_lines` usando `ft_strjoin`.
   - Repite este proceso hasta encontrar una nueva línea o hasta que no haya más datos para leer.

3. **`next_line`**: Extrae la siguiente línea de `saved_lines`.
   - Busca el primer carácter de nueva línea en `saved_lines` usando `ft_strchr`.
   - Copia la línea encontrada en una nueva cadena de caracteres usando `ft_strlcpy`.

4. **`keep_remain`**: Mantiene solo la parte de `saved_lines` que sigue a la línea extraída.
   - Busca el primer carácter de nueva línea en `saved_lines` usando `ft_strchr`.
   - Copia la parte restante de `saved_lines` en una nueva cadena de caracteres usando `ft_strlcpy`.

### Resumen

El flujo general del programa es el siguiente:

1. Se llama a `get_next_line` con un descriptor de archivo.
2. `get_next_line` verifica la validez del descriptor de archivo y si hay datos para leer.
3. Si es válido, `get_next_line` llama a `read_file` para leer el archivo y almacenar el contenido en `saved_lines`.
4. Luego, `get_next_line` llama a `next_line` para extraer la siguiente línea de `saved_lines`.
5. `get_next_line` llama a `keep_remain` para mantener solo la parte de `saved_lines` que sigue a la línea extraída.
6. Finalmente, `get_next_line` retorna la línea extraída.

Este proceso se repite cada vez que se llama a `get_next_line` para leer la siguiente línea del archivo.

### Bonus

1. **Arreglo Estático para Guardar Líneas**:
   - En el primer fragmento, `saved_lines` es una variable estática de tipo puntero a `char`.
   - En el segundo fragmento, `saved_lines` es un arreglo estático de punteros a `char` con un tamaño de 256. Esto significa que puede manejar hasta 256 descriptores de archivo diferentes, cada uno con su propia cadena de líneas guardadas.

2. **Verificación de Descriptor de Archivo**:
   - En el primer fragmento, la verificación del descriptor de archivo (`fd`) se realiza solo para asegurarse de que no sea negativo y que `BUFFER_SIZE` sea mayor que 0.
   - En el segundo fragmento, además de las mismas verificaciones, también se verifica que `fd` no sea mayor que 255. Esto es relevante porque el arreglo `saved_lines` tiene un tamaño fijo de 256, lo que limita el número de descriptores de archivo que puede manejar.

3. **Acceso a `saved_lines`**:
   - En el primer fragmento, se accede a `saved_lines` directamente como una variable.
   - En el segundo fragmento, se accede a `saved_lines` utilizando el descriptor de archivo (`fd`) como índice. Esto permite manejar múltiples descriptores de archivo de manera independiente.
