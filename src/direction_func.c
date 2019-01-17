/*
** EPITECH PROJECT, 2018
** direction_func.c
** File description:
** function for the direction
*/

#include "lemi.h"

static int	condition_mouvement(int to, int nb, int size)
{
	if (nb == 0)
		to = to - W;
		if (to < 0)
			to = to + W;
	else if (nb == 1)
		to = to + 1;
		if (to % W == 0 || to > size)
			to = to - 1;
	else if (nb == 2)
		to = to + W;
		if (to > size)
			to = to - W;
	else
		to = to - 1;
		if (to < 0 || to % W == 0)
			to = to + 1;
	return (to);
}

int	move_champ(t_team *tab, int from, int size)
{
	int	team_save;
	int	to;
	int	nb;

	team_save = tab[from].team;
	to = from;
	while (tab[to].team != 0)
	{
		nb = (rand() % 4);
		to = condition_mouvement(to , nb, size);
		usleep(10000);
	}
	tab[from].team = 0;
	tab[to].team = team_save;
	return (to);
}
