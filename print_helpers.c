#include "main.h"

/**
 * print_char - Writes a single character to standard output
 * @character: The character value to display
 *
 * Return: Always returns 1 upon success
 */
int print_char(char character)
{
	return (write(1, &character, 1));
}

/**
 * print_string - Writes a string to standard output character by character
 * @string_input: Pointer to the target null-terminated string
 *
 * Return: Total number of characters printed
 */
int print_string(char *string_input)
{
	int printed_count = 0;

	/* Non-trivial logic: Handle NULL pointer edge case gracefully */
	if (string_input == NULL)
		string_input = "(null)";

	while (*string_input != '\0')
	{
		printed_count += print_char(*string_input);
		string_input++;
	}

	return (printed_count);
}

/**
 * print_positive_number - Helper function to print positive long integers recursively
 * @number: The positive number to format and output
 *
 * Return: Total count of printed digits
 */
int print_positive_number(long number)
{
	int digit_count = 0;

	/* Non-trivial logic: Divide recursively to process high-order digits first */
	if (number / 10)
		digit_count += print_positive_number(number / 10);

	/* Print the current single digit by converting numeric value to ASCII */
	digit_count += print_char((number % 10) + '0');

	return (digit_count);
}

/**
 * print_number - Handles signed decimal integer formatting and sign detection
 * @integer_value: Integer number received from variadic arguments
 *
 * Return: Count of characters printed including negative sign
 */
int print_number(int integer_value)
{
	int total_printed = 0;
	long positive_conversion = integer_value;

	/* Non-trivial logic: Convert negative numbers using long to avoid INT_MIN overflow */
	if (positive_conversion < 0)
	{
		total_printed += print_char('-');
		positive_conversion = -positive_conversion;
	}

	total_printed += print_positive_number(positive_conversion);

	return (total_printed);
}

