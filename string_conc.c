#include "main.h"

/**
 * string_conc - concatenating two strings
 * @str1: input string
 * @str2: input string
 * Return: null or pointer to the new string
 */

char *string_conc(char *str1, char *str2)
{
	int len1 = 0, len2 = 0, i = 0, j = 0;
	char *ptr;

	len1 = string_len(str1);
	len2 = string_len(str2);
	ptr = malloc(sizeof(char) * (len1 + len2 + 1));

	if (ptr == NULL)
	{
		perror("error");
		return (NULL);
	}

	while (str1[i])
	{
		ptr[i] = str1[i];
		i++;
	}

	while (str2[j])
	{
		ptr[i] = str2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';

	return (ptr);
}
