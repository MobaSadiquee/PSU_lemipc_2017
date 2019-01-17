/*
** EPITECH PROJECT, 2018
** init_func.c
** File description:
** init function for the lemipc
*/

#include "lemi.h"

t_team	*map_gen(t_team *map, key_t key, int *sem_id)
{
	int	pos = 0;
	int	size = L * W;

	*sem_id = semget(key, 1, IPC_CREAT | SHM_R | SHM_W);
	if (*sem_id == -1)
		return (NULL);
	semctl(*sem_id, 0, SETVAL, 1);
	while (pos < size)
	{
		map[pos].team = 0;
		pos++;
	}
	return (map);
}

bool	init_ipcs(t_ipcs *ipcs, char **av)
{
	key_t	tok;

	tok = ftok(av[1], 123);
	ipcs->key = tok;
	return (true);
}
