#include "main.h"

/**
 * num_to_str - convert number to string
 * @num: input number
 * Return: pointer to string
 */

char *num_to_str(int num)
{
	int i = 0, j = 0;
	char *str, temp;

	str = malloc(sizeof(char) * 4);

	if (str == NULL)
	{
		perror("error");
		return (NULL);
	}

	do {
		str[i] = num % 10 + '0';
		num /= 10;
		i++;
	} while (num > 0);
	str[i] = '\0';

	for (j = 0; j < i; j++)
	{
		temp = str[j];
		str[j] = str[i - 1];
		str[i - 1] = temp;
		i--;
	}

	return (str);
}
