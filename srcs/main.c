/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:38:41 by ajimenez          #+#    #+#             */
/*   Updated: 2021/10/22 13:04:20 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void leak()
{
	system("leaks -q a.out");
}

int	main(int ac, char **av, char **env)
{
	t_pipex	*ps;
	int		pid;
	int		fd[2];
	int		trigger;

	atexit(leak);
	if (ac != 5)
		return (0);
	ps = calloc(sizeof(t_pipex), 1);
	if(pipe(fd) == -1)
		return(0);
	get_args(ac, av, ps, env);
	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		ft_exec_cmd1(ps, env, fd);
	}
	else if (pid > 0)
	{
		close(fd[WRITE_END]);
		pid = fork();
		if (pid == 0)
			ft_exec_cmd2(ps, env, fd);
		else
			close(fd[READ_END]);
	}
	wait(&trigger);
	wait(&trigger);
	free_ps(ps);
}
