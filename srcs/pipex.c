/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:22:55 by ajimenez          #+#    #+#             */
/*   Updated: 2021/10/18 10:36:38 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	get_args(int ac, char **av, t_pipex *ps, char **env)
{
	ps->infile = ft_strdup(av[1]);
	ps->cmd_1 = ft_strdup(av[2]);
	ps->cmd_2 = ft_strdup(av[3]);
	ps->outfile = ft_strdup(av[4]);
}

void leak()
{
	system("leaks -q a.out");
}

int	main(int ac, char **av, char *env[])
{
	t_pipex	*ps;
	int		pid;
	int		s;
	int		fd1[2];
	int		fd2;

	if (ac != 5)
		return (0);
	ps = calloc(sizeof(t_pipex), 1);
	get_args(ac, av, ps, env);
	exec_cmd(ps, env);
	return (0);
}
