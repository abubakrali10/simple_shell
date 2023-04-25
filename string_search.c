#include "main.h"

/**
 * string_search - locate substring
 * @str: input string
 * @word: word search
 * Return: pointer
 */

int string_search(char *str, char *word)
{
	int i = 0;

	while (i < string_len(word))
	{
		if (str[i] != word[i])
			return (-1);
		i++;
	}
	return (0);
}
