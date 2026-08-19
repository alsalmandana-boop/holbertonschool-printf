# C - Custom _printf

## Description
This project is a custom implementation of the standard `printf` function in C. The function `_printf` formats and prints data to the standard output stream (`stdout`) according to a specified format string. It handles variadic arguments using the `<stdarg.h>` library and tracks the total number of characters printed.

## Requirements
* **Allowed Editors:** `vi`, `vim`, `emacs`
* **OS & Compiler:** Ubuntu 20.04 LTS using `gcc`
* **Compilation Flags:** `-Wall -Werror -Wextra -pedantic -std=gnu89`
* **Coding Style:** Code strictly follows the Betty style (checked with `betty-style.pl` and `betty-doc.pl`).
* **Header Guard:** All header files are guarded against multiple inclusions.
* **Global Variables:** Global variables are strictly prohibited.
* **Function Limit:** Maximum 5 functions per file.

## Authorized Functions & Macros
* `write` (`man 2 write`)
* `malloc` (`man 3 malloc`)
* `free` (`man 3 free`)
* `va_start` (`man 3 va_start`)
* `va_end` (`man 3 va_end`)
* `va_copy` (`man 3 va_copy`)
* `va_arg` (`man 3 va_arg`)

## Supported Conversion Specifiers

| Specifier | Description | Example Input | Output |
| :---: | --- | --- | --- |
| `%c` | Prints a single character | `_printf("%c", 'A');` | `A` |
| `%s` | Prints a string of characters | `_printf("%s", "Hello");` | `Hello` |
| `%%` | Prints a literal percent sign | `_printf("%%");` | `%` |
| `%d` | Prints a signed decimal integer | `_printf("%d", 1024);` | `1024` |
| `%i` | Prints a signed integer (base 10) | `_printf("%i", -98);` | `-98` |

## Prototype & Files

### Prototype
```c
int _printf(const char *format, ...);

## File Structure

* main.h: Header file containing function prototypes and definitions.

* _printf.c: Main entry function for parsing the format string.

* _putchar.c: Helper function to write characters to standard output using write.

* README.md: Project documentation.

## Compilation & Usage
To compile the project alongside a main.c file, use:
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c -o printf

## Example Usage (main.c)
#include "main.h"

int main(void)
{
    int len;

    len = _printf("Let's try to printf a simple sentence.\n");
    _printf("Length:[%d, %i]\n", len, len);
    _printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    _printf("Percent:[%%]\n");
    return (0);
}

## Authors

Renad Fouad Albatati
Dana Ibrahim Alsalman
