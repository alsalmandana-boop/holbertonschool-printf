#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: Format string
 *
 * Return: Number of characters printed, or -1 on failure
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i;
	int count;
	int printed;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	i = 0;
	count = 0;

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			printed = print_char(format[i]);
		}
		else
		{
			i++;

			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}

			if (format[i] == 'c')
				printed = print_char((char)va_arg(args, int));
			else if (format[i] == 's')
				printed = print_string(va_arg(args, char *));
			else if (format[i] == '%')
				printed = print_char('%');
			else if (format[i] == 'd' || format[i] == 'i')
				printed = print_number(va_arg(args, int));
			else
			{
				printed = print_char('%');
				if (printed == -1)
				{
					va_end(args);
					return (-1);
				}

				count += printed;
				printed = print_char(format[i]);
			}
		}

		if (printed == -1)
		{
			va_end(args);
			return (-1);
		}

		count += printed;
		i++;
	}

	va_end(args);
	return (count);
}
