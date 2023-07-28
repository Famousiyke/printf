#include "main.h"

/**
 * get_size - a function that Calculates
 * the size to cast the argument
 * @formt: Formatted string in which to print the arguments
 * @q: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *formt, int *q)
{
	int curr_q = *q + 1;
	int size = 0;

	if (formt[curr_q] == 'l')
		size = S_LONG;
	else if (formt[curr_q] == 'h')
		size = S_SHORT;

	if (size == 0)
		*q = curr_q - 1;
	else
		*q = curr_q;

	return (size);
}
