#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: Format string
 *
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
    va_list args;
    int i = 0;
    int count = 0;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (format[i] != '\0')
    {
        if (format[i] != '%')
        {
            write(1, &format[i], 1);
            count++;
        }
        else
        {
            i++;

            if (format[i] == 'c')
                count += print_char(va_arg(args, int));
            else if (format[i] == 's')
                count += print_string(va_arg(args, char *));
            else if (format[i] == '%')
                count += print_char('%');
            else if (format[i] == 'd')
                count += print_number(va_arg(args, int));
            else if (format[i] == 'i')
                count += print_number(va_arg(args, int));
        }

        i++;
    }

    va_end(args);

    return (count);
}
