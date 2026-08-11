#include "main.h"

/**
 * print_char - Prints one character
 * @c: Character to print
 *
 * Return: 1
 */

int print_char(char c)
{
    write(1, &c, 1);
    return (1);
}

/**
 * print_string - Prints a string
 * @str: String to print
 *
 * Return: Number of characters printed
 */

int print_string(char *str)
{
    int count;

    count = 0;

    if (str == NULL)
        str = "(null)";

    while (str[count] != '\0')
    {
        write(1, &str[count], 1);
        count++;
    }

    return (count);
}

/**
 * print_number - Prints an integer
 * @n: Number to print
 *
 * Return: Number of characters printed
 */

int print_number(int n)
{
    long number;
    int count;

    number = n;
    count = 0;

    if (number < 0)
    {
        write(1, "-", 1);
        count++;
        number = -number;
    }

    count += print_positive_number(number);

    return (count);
}

/**
 * print_positive_number - Prints a positive number
 * @number: Number to print
 *
 * Return: Number of characters printed
 */

int print_positive_number(long number)
{
    int count;
    char digit;

    count = 0;

    if (number / 10)
        count += print_positive_number(number / 10);

    digit = (number % 10) + '0';
    write(1, &digit, 1);
    count++;

    return (count);
}
