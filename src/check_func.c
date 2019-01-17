/*
** EPITECH PROJECT, 2018
** check_func.c
** File description:
** check functions for the lemipc
*/

#include "lemi.h"

void	check_alive(t_team *map, int size)
{
	int	i = 0;
	int	j = 0;

	while (j < size)
	{
		if (map[j].team != 0)
			i++;
		j++;
	}
	printf("Number of champions available = %i\n\n", i);
}

static bool	check_double(int *check, int team)
{
	int	i = 0;
	int	j = 0;

	while (i < 8)
	{
		if (check[i] != team && check[i] != 0)
		{
			while (j < 8)
			{
				if (j != i && check[j] == check[i])
					return (true);
				j++;
			}
		}
		i++;
	}
	return (false);
}

int	check_team(t_team *map, int size)
{
	int	x = 0;
	int	tmp = 0;

	tmp = map[0].team;
	while (x < size)
	{
		if (map[x].team != 0 && tmp == 0)
			tmp = map[x].team;
		else if (map[x].team != 0 && tmp != map[x].team &&
			tmp != 0)
			return (0);
		x++;
	}
	return (1);
}

bool	last_team(t_team *team, int pos, int size)
{
	int	check[8];
	int	i = 0;

	check[0] = ((i = pos + 1) > size) ? 0 : team[i].team;
	check[1] = ((i = pos + W + 1) > size) ? 0 : team[i].team;
	check[2] = ((i = pos + W) > size) ? 0 : team[i].team;
	check[3] = ((i = pos + W - 1) > size) ? 0 : team[i].team;
	check[4] = ((i = pos - 1) < 0) ? 0 : team[i].team;
	check[5] = ((i = pos - W - 1) < 0) ? 0 : team[i].team;
	check[6] = ((i = pos - W) < 0) ? 0 : team[i].team;
	check[7] = ((i = pos - W + 1) < 0) ? 0 : team[i].team;
	if (check_double(check, team[pos].team) == true)
	{
		team[pos].team = 0;
		return (true);
	}
	return (false);
}
