#include "main.h"

/**
 * _printf - Formats and prints arguments according to format specifiers
 * @format: Format string containing regular text and conversion specifiers
 *
 * Return: Number of characters printed, or -1 on NULL format string
 */
int _printf(const char *format, ...)
{
	va_list args;
	int total_chars = 0;
	int index = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[index] != '\0')
	{
		if (format[index] != '%')
		{
			total_chars += print_char(format[index]);
		}
		else
		{
			index++;
			/* Non-trivial logic: Check if format string ends abruptly with '%' */
			if (format[index] == '\0')
			{
				va_end(args);
				return (-1);
			}

			/* Evaluate specifier character */
			if (format[index] == 'c')
				total_chars += print_char(va_arg(args, int));
			else if (format[index] == 's')
				total_chars += print_string(va_arg(args, char *));
			else if (format[index] == '%')
				total_chars += print_char('%');
			else if (format[index] == 'd' || format[index] == 'i')
				total_chars += print_number(va_arg(args, int));
			else
			{
				/* Non-trivial logic: Unknown specifier handling */
				total_chars += print_char('%');
				total_chars += print_char(format[index]);
			}
		}
		index++;
	}

	va_end(args);
	return (total_chars);
}

