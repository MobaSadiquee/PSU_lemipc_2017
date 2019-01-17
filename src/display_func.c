/*
** EPITECH PROJECT, 2018
** dsplay_func.c
** File description:
** display function for the lemipc
*/

#include <stdio.h>
#include <stdlib.h>
#include "lemi.h"

static void	print_ligne(void)
{
	int   i = 0;

	printf("*");
	while (i < W)
	{
		printf("-");
		i++;
	}
	printf("*\n");
}

static void	print_inside(t_team *team)
{
	int	i = 0;
	int	l = 0;
	int	size = L * W;

	printf("|");
	while (i < size)
	{
		if (team[i].team > 0)
			printf("%d", team[i].team);
		else
			printf(" ");
		i++;
		if (i % W == 0)
		{
			printf("|\n");
			if ((l + 1) < L)
				printf("|");
			l++;
		}
	}
}

static void	display_map(t_team *team)
{
	int	size = L * W;

	system("clear");
	printf("LEMIPC\n\n");
	printf("[Information]\n");
	printf("L = %d W = %d\n", L, W);
	check_alive(team, size);
	print_ligne();
	print_inside(team);
	print_ligne();
}

static void	display_win(t_team *team, int size)
{
	int	i = 0;

	while (i < size && team[i].team == 0)
		i++;
	printf("\n[Winner]\n");
	printf("TEAM %i WON !\n\n", team[i].team);
}

void	display_loop(t_team *team, t_ipcs *ipcs, int size)
{
	if (check_team(team, size) == 1)
		printf("Waiting for a second player ...\n");
	while (check_team(team, size) == 1)
		usleep(1);
	while (check_team(team, size) != 1)
	{
		lock(ipcs->sem_id);
		display_map(team);
		usleep(100000);
		unlock(ipcs->sem_id);
	}
	usleep(100000);
	unlock(ipcs->sem_id);
	display_map(team);
	display_win(team, size);
	destroy_ipcs(ipcs);
}
