/*
** EPITECH PROJECT, 2018
** my_basic_func.
** File description:
** basic function lemipc
*/

#include <stdlib.h>
#include <stdio.h>
#include "lemi.h"

void	my_putchar(char c)
{
	write(1, &c, 1);
}

int	my_strlen(char *str)
{
	int	i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

int	my_putstr(char *str)
{
	int	i = 0;

	while (str[i] != '\0')
	{
		my_putchar(str[i]);
		i++;
	}
	return (0);
}

void     usage(void)
{
	printf("\nUsage: ./lemipc path_to_key team_number\n\n");
	printf("path_to_key is a valid path that will be used by ftok\n");
	printf("team_number is the team number assigned to the current player");
	printf("\n\n");
}

int     my_str_is_num(char *str)
{
	int     i = 0;

	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}
