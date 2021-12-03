/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:38:41 by ajimenez          #+#    #+#             */
/*   Updated: 2021/12/03 18:05:28 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/* ************************************************************************** */
/*  STDOUT_FILENO = 1                                                         */
/*  STDIN_FILENO  = 0                                                         */
/*  WRITE_END     = 1                                                         */
/*  READ_END      = 0                                                         */
/* ************************************************************************** */

static void	ft_open_error(char *s)
{
	ft_putstr_fd("zsh: can't open file: ", 2);
	ft_putstr_fd(s, 2);
	exit(0);
}

static void	ft_exec_child_1(char **env, int *fd, char **av)
{
	int	fd_1;

	close(fd[READ_END]);
	fd_1 = open(av[1], O_RDONLY);
	if (fd_1 == -1)
		ft_open_error(av[1]);
	dup2(fd_1, STDIN_FILENO);
	close(fd_1);
	dup2(fd[WRITE_END], STDOUT_FILENO);
	close(fd[WRITE_END]);
	ft_exec(av[2], env);
}

static void	ft_exec_child_2(char **env, int *fd, char **av)
{
	int	fd_2;

	fd_2 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_2 == -1)
		ft_open_error(av[4]);
	dup2(fd[READ_END], STDIN_FILENO);
	close(fd[READ_END]);
	dup2(fd_2, STDOUT_FILENO);
	close(fd_2);
	ft_exec(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int		pid;
	int		fd[2];
	int		trigger;

	if (ac != 5)
	{
		ft_putstr_fd("Args should be: $> ./pipex file1 cmd1 cmd2 file2", 2);
		return (0);
	}
	pipe(fd);
	pid = fork();
	if (pid == 0)
		ft_exec_child_1(env, fd, av);
	else if (pid > 0)
	{
		close(fd[WRITE_END]);
		pid = fork();
		if (pid == 0)
			ft_exec_child_2(env, fd, av);
		else
			close(fd[READ_END]);
	}
	wait(&trigger);
	wait(&trigger);
	return (0);
}
