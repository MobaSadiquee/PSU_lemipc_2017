/*
** EPITECH PROJECT, 2018
** my_error_func
** File description:
** error function for the lemipc
*/

#include "lemi.h"

void	my_exit(char *str, int value)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
	exit(value);
}

int	my_error(char *str, int value)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
	return (value);
}
