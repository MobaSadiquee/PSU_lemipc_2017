/*
** EPITECH PROJECT, 2018
** loop_func.c
** File description:
** loop function for the lemipc
*/

#include "lemi.h"

static void	player_loop(t_team *team, int pos, t_ipcs *ipcs, int size)
{
	bool	life = false;

	while (life == false)
	{
		lock(ipcs->sem_id);
		pos = move_champ(team, pos, size);
		life = last_team(team, pos, size);
		unlock(ipcs->sem_id);
		usleep(100000);
	}
}

static void	start_first(t_ipcs *ipcs, int team, int size)
{
	int	pos = 0;
	void	*map = NULL;

	if ((ipcs->shm_id = shmget(ipcs->key, (sizeof(t_team) * size),
		IPC_CREAT | SHM_R | SHM_W)) != -1)
	{
		if ((map = shmat(ipcs->shm_id, NULL, SHM_R | SHM_W))
			!= (void*)-1)
		{
			map = map_gen(map, ipcs->key, &ipcs->sem_id);
			pos = place_champion((t_team *)map, team,
				ipcs->sem_id, size);
			if (fork() == 0)
				display_loop(map, ipcs, size);
			else
				player_loop((t_team *)map, pos, ipcs, size);
		}

	}
}

static void	start_second(t_ipcs *ipcs, int team, int size)
{
	int	pos = 0;
	void	*add = NULL;

	ipcs->sem_id = semget(ipcs->key, 1, SHM_R | SHM_W);
	ipcs->msg_id = msgget(ipcs->key, SHM_R | SHM_W);
	if ((add = shmat(ipcs->shm_id, NULL, SHM_R | SHM_W)) != (void*)-1)
		pos = place_champion((t_team *)add, team, ipcs->sem_id, size);
	player_loop((t_team *)add, pos, ipcs, size);
}

void	which_start(t_ipcs *ipcs, char **av)
{
	int	size = L * W;

	if ((ipcs->shm_id =
		shmget(ipcs->key, (sizeof(t_team) * size), SHM_R | SHM_W)) == -1)
		start_first(ipcs, atoi(av[2]), size);
	else
		start_second(ipcs, atoi(av[2]), size);
}
