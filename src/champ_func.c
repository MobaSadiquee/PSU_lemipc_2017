/*
** EPITECH PROJECT, 2018
** ia_func.c
** File description:
** ia function for the lemipc
*/

#include "lemi.h"

static	bool check_place(t_team *tab, int size)
{
	int	i = 0;

	while (i < size)
	{
		if (tab[i].team == 0)
			return (true);
		i++;
	}
	return (false);
}

int	place_champion(t_team *tab, int team, int sem_id, int size)
{
	int	pos = 0;

	srand((unsigned)time(NULL));
	pos = (rand() % (size - 1));
	lock(sem_id);
	if (check_place(tab, size) == false)
	{
		unlock(sem_id);
		my_exit("[Error] No more space for champion\n", error);
	}
	else
	{
		while (tab[pos].team != 0)
			pos = (rand() % (size - 1));
		tab[pos].team = team;
		unlock(sem_id);
	}
	return (pos);
}
