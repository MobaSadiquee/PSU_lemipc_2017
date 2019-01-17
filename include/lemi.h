/*
** EPITECH PROJECT, 2018
** lemi
** File description:
** header for the lemipc project
*/

#ifndef LEMI_H_
# define LEMI_H_

# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/sem.h>
# include <sys/msg.h>
# include <sys/shm.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <time.h>

# define L 10
# define W 15
# define error 84

typedef struct  s_team
{
	int	team;
}		t_team;

typedef struct  s_ipcs
{
	key_t	key;
	int	sem_id;
	int	shm_id;
	int	msg_id;
}		t_ipcs;

int	place_champion(t_team *, int, int, int);
bool	init_ipcs(t_ipcs *, char **);
void	which_start(t_ipcs *, char **);
int	move_champ(t_team *, int, int);
void	display_loop(t_team *, t_ipcs *, int);
bool	last_team(t_team *, int, int);
int	my_str_is_num(char *);
void	destroy_ipcs(t_ipcs *);
void	check_alive(t_team *, int);
int     check_team(t_team *, int);
void	unlock(int);
int	lock(int);
t_team	*map_gen(t_team *,key_t, int *);

void    my_exit(char *, int);
int     my_error(char *, int);
void	usage();

#endif /* !LEMIPC_H_ */
