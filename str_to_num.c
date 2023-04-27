#include "main.h"

/**
 * str_to_num - convert str to num
 * @str: string input
 * Return: number
 */

int str_to_num(char *str)
{
	int sign = 1, res = 0, i = 0;

	if (str[i] == '0')
		return (0);
	while (str[i])
	{
		if (str[i] == '-')
			sign *= -1;
		else
		{
			if (str[i] <= '0' || str[i] >= '9')
				return (-1);
			res = (res * 10) + (str[i] - '0');
		}
		i++;
	}

	return (res * sign);
}
