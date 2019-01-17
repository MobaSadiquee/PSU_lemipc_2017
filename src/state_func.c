/*
** EPITECH PROJECT, 2018
** state_func.c
** File description:
** state function for the lemipc
*/

#include "lemi.h"

void	destroy_ipcs(t_ipcs *ipcs)
{
	semctl(ipcs->sem_id, 1, IPC_RMID);
	shmctl(ipcs->shm_id, IPC_RMID, NULL);
	msgctl(ipcs->msg_id, IPC_RMID, NULL);
	exit(0);
}

int	lock(int sem_id)
{
	struct sembuf tmp;

	tmp.sem_num = 0;
	tmp.sem_flg = 0;
	tmp.sem_op = -1;
	if (semop(sem_id, &tmp, 1) == -1) {
		unlock(sem_id);
		exit(0);
	}
	return (0);
}

void	unlock(int sem_id)
{
	struct sembuf tmp;

	tmp.sem_num = 0;
	tmp.sem_flg = 0;
	tmp.sem_op = 1;
	semop(sem_id, &tmp, 1);
}
