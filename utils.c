#include "main.h"

/**
 * is_printable -a function that evaluates if a char is printable
 * @e: Char to be evaluated.
 * Return: 1 if e is printable
 * 0 otherwise
 */
int is_printable(char e)
{
	if (e >= 32 && e < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ascci in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @q: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int q)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[q++] = '\\';
	buffer[q++] = 'x';

	buffer[q++] = map_to[ascii_code / 16];
	buffer[q] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Verifies if a char is a digit
 * @e: Char to be evaluated
 * Return: 1 if  is a digit
 * 0 otherwise
 */
int is_digit(char e)
{
	if (e >= '0' && e <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Casts a number to the specified size
 * @nm: Number to be casted.
 * @sze: Number indicating the type to be casted.
 * Return: Casted value of nm
 */
long int convert_size_number(long int nm, int sze)
{
	if (sze == S_LONG)
		return (nm);
	else if (sze == S_SHORT)
		return ((short)nm);

	return ((int)nm);
}

/**
 * convert_size_unsgnd - Casts a number to the specified size
 * @nm: Number to be casted
 * @sze: Number indicating the type to be casted
 * Return: Casted value of nm
 */
long int convert_size_unsgnd(unsigned long int nm, int sze)
{
	if (sze == S_LONG)
		return (nm);
	else if (sze == S_SHORT)
		return ((unsigned short)nm);

	return ((unsigned int)nm);
}
