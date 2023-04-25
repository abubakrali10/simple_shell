#include "main.h"

/**
 * string_words - get number of words in string accord dilm
 * @str: input string
 * @dilm: seprator input
 * Return: number of words
 */

int string_words(char *str, char dilm)
{
	int size = 0, i = 0;

	while (str[i])
	{
		if (str[i] != dilm && (str[i + 1] == dilm || str[i + 1] == '\0'))
			size++;
		i++;
	}

	return (size);
}

/**
 * split_string - split string and allocate in its place in array
 * @str: input string
 * @arr: pointer to array
 * @dilm: separator of string
 * Return: pointer to array
 */

char **split_string(char *str, char **arr, char dilm)
{
	int y = 0, x = 0, i = 0;

	while (str[i])
	{
		if (str[i] != dilm)
		{
			arr[y][x] = str[i];
			x++;
		}
		if (str[i] != dilm && (str[i + 1] == dilm || str[i + 1] == '\0'))
		{
			arr[y][x] = '\0';
			y++;
			x = 0;
		}
		i++;
	}
	arr[y] = NULL;

	return (arr);
}

/**
 * string_to_array - make pointer to array of strings from string
 * though split it by dilm
 * @str: input string
 * @dilm: seprators
 * Return: pointer to array
 */

char **string_to_array(char *str, char dilm)
{
	char **arr;
	int size, word = 0, count = 0, y = 0, i = 0;

	if (str == NULL || !*str)
		return (NULL);
	size = string_words(str, dilm);
	if (size == 0)
		return (NULL);
	arr = malloc(sizeof(char *) * (size + 1));
	if (arr == NULL)
	{
		perror("error");
		return (NULL);
	}
	while (str[i])
	{
		if (str[i] != dilm)
		{
			word = 1;
			count++;
		}
		if (str[i] != dilm && (str[i + 1] == dilm || str[i + 1] == '\0'))
			word = 0;
		if (word == 0 && count > 0)
		{
			arr[y] = malloc(sizeof(char) * (count + 1));
			if (arr[y] == NULL)
			{
				perror("error");
				free_array(arr);
				return (NULL);
			}
			count = 0;
			y++;
		}
		i++;
	}

	return (split_string(str, arr, dilm));
}
