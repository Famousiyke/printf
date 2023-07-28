#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - a Printf function
 * @fm: The format.
 * Return: The Printed chars.
 */
int _printf(const char *fm, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (fm == NULL)
		return (-1);

	va_start(list, fm);

	for (a = 0; fm && fm[a] != '\0'; a++)
	{
		if (fm[a] != '%')
		{
			buffer[buff_ind++] = fm[a];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &fm[a], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(fm, &a);
			width = get_width(fm, &a, list);
			precision = get_precision(fm, &a, list);
			size = get_size(fm, &a);
			++a;
			printed = handle_print(fm, &a, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - a function that Prints
 * the contents of the buffer if it exist
 * @buffer: The Array of characters
 * @buffer_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buffer_ind)
{
	if (*buffer_ind > 0)
		write(1, &buffer[0], *buffer_ind);

	*buffer_ind = 0;
}
