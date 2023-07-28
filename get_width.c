#include "main.h"

/**
 * get_width - a function that Calculates
 * the width for printing
 * @formt: Formatted string in which to print the arguments.
 * @q: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *formt, int *q, va_list list)
{
	int curr_q;
	int width = 0;

	for (curr_q = *q + 1; formt[curr_q] != '\0'; curr_q++)
	{
		if (is_digit(formt[curr_q]))
		{
			width *= 10;
			width += formt[curr_q] - '0';
		}
		else if (formt[curr_q] == '*')
		{
			curr_q++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*q = curr_q - 1;

	return (width);
}
