#include "main.h"

/**
 * string_len - get length of string
 * @str: string input
 * Return: length
 */

int string_len(char *str)
{
	int len = 0;

	while (str[len])
	{
		len++;
	}

	return (len);
}
