/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:38:41 by ajimenez          #+#    #+#             */
/*   Updated: 2021/10/20 17:12:07 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	*ps;
	int		pid;
	int		fd[2];

	if (ac != 5)
		return (0);
	ps = calloc(sizeof(t_pipex), 1);
	get_args(ac, av, ps, env);
	pipe(fd);/*errores por si aca if(pipe(fd)==-1 return 0)*/
	pid = fork();
	if (pid == 0)
	{
		close(fd[READ_END]);
		dup2()
		ft_exec_cmd1(ps, env, fd);
	}
	else if (pid > 0)
	{
		close(fd[1]);
		ft_exec_cmd2(ps, env, fd);

	}
}
