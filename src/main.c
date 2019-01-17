/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function for the lemipc
*/

#include <signal.h>
#include "lemi.h"

static int	start_lemipc(char **av)
{
	t_ipcs	*ipcs = NULL;

	ipcs = malloc(sizeof(t_ipcs));
	if (ipcs == NULL)
		return (error);
	ipcs->sem_id = 0;
	ipcs->shm_id = 0;
	ipcs->msg_id = 0;
	if ((init_ipcs(ipcs, av)) == false)
		exit(error);
	which_start(ipcs, av);
	free(ipcs);
	return (0);
}

static void	number_param(char **av)
{
	fprintf(stderr, "Usage: %s PATH NB_TEAM\n", av[0]);
	fprintf(stderr, "type --help to display");
	fprintf(stderr, "more help with informaration about lemipc\n");
}

int	main(int ac, char **av)
{
	int	value = 0;

	srand((unsigned)time(NULL));
	if (ac <= 1 || ac >= 4)
	{
		number_param(av);
		return (error);
	}
	else if (strcmp(av[1], "--help") == 0)
	{
		usage();
		return (error);
	}
	else if (ac == 3 && (my_str_is_num(av[2])) == 1)
	{
		fprintf(stderr, "[Error] Second param is not a number\n");
		return (error);
	}
	value = start_lemipc(av);
	return (value);
}
