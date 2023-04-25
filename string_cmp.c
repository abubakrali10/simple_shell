#include "main.h"

/**
 * string_cmp - compare two strings
 * @s1: input string
 * @s2: input string
 * Return: result of comparing
 */

int string_cmp(char *s1, char *s2)
{
	int i = 0, j = 0;

	while (s1[i] && s2[j])
	{
		if (s1[i] != s2[j])
		{
			return (-1);
		}
		i++;
		j++;
	}

	return (0);
}
