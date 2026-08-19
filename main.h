#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function that prints formatted output to stdout
 * @format: Format string containing characters and specifiers
 *
 * Return: Total number of characters printed
 */
int _printf(const char *format, ...);

/**
 * print_char - Writes a single character to standard output
 * @c: Character to be printed
 *
 * Return: Number of characters printed (1)
 */
int print_char(char c);

/**
 * print_string - Writes a string of characters to standard output
 * @str: Pointer to the string to print
 *
 * Return: Total number of characters printed
 */
int print_string(char *str);

/**
 * print_number - Prints a signed integer
 * @n: Integer number to print
 *
 * Return: Total number of digits/characters printed
 */
int print_number(int n);

/**
 * print_positive_number - Recursively prints positive numbers digit by digit
 * @number: Long integer number to print
 *
 * Return: Total number of digits printed
 */
int print_positive_number(long number);

#endif /* MAIN_H */
