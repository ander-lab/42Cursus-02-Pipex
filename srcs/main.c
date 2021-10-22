/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:38:41 by ajimenez          #+#    #+#             */
/*   Updated: 2021/10/22 16:55:16 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_exec_child_1(t_pipex *ps, char **env, int *fd)
{
	char	*path;
	char	**cmd;

	close(fd[READ_END]);
	ps->fd_1 = open(ps->infile, O_RDONLY);
	if (ps->fd_1 == -1)
		ft_open_error("zsh: can´t open file ", ps->infile, ps);
	dup2(ps->fd_1, STDIN_FILENO);
	close(ps->fd_1);
	dup2(fd[WRITE_END], STDOUT_FILENO);
	close(fd[WRITE_END]);
	ft_exec(1, ps, env);
}

void	ft_exec_child_2(t_pipex *ps, char **env, int *fd)
{
	char	*path;
	char	**cmd;

	ps->fd_2 = open(ps->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (ps->fd_2 == -1)
		ft_open_error("zsh: can´t open file: ", ps->outfile, ps);
	dup2(fd[READ_END], STDIN_FILENO);
	close(fd[READ_END]);
	dup2(ps->fd_2, STDOUT_FILENO);
	close(ps->fd_2);
	ft_exec(2, ps, env);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	*ps;
	int		pid;
	int		fd[2];
	int		trigger;

	if (ac != 5)
		return (0);
	ps = calloc(sizeof(t_pipex), 1);
	get_args(ac, av, ps, env);
	pipe(fd);
	pid = fork();
	if (pid == 0)
		ft_exec_child_1(ps, env, fd);
	else if (pid > 0)
	{
		close(fd[WRITE_END]);
		pid = fork();
		if (pid == 0)
			ft_exec_child_2(ps, env, fd);
		else
			close(fd[READ_END]);
	}
	wait(&trigger);
	wait(&trigger);
	free_ps(ps);
}
