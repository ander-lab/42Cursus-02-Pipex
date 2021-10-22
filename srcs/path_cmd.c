/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:13:34 by ajimenez          #+#    #+#             */
/*   Updated: 2021/10/22 12:37:38 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_open_error(char *s, char *s2, t_pipex *ps)
{
	ft_putstr_fd(s, 1);
	ft_putstr_fd(s2, 1);
	exit(1); 
}

char	*path_cmd(t_pipex *ps, char **envp, char *cmd)
{
	ssize_t	i;
	char	*path;
	char	*tmp;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			ps->paths = ft_split(ft_strchr(envp[i], '/'), ':');
		i++;
	}
	i = 0;
	while (ps->paths[i])
	{
		tmp = ft_strjoin(ps->paths[i], "/");
		path = ft_strjoin(tmp, ft_split(cmd, ' ')[0]);
		free(tmp);
		if (access(path, R_OK) == 0)
			return (path);
		i++;
	}
	if (!path)
	{
		ft_putstr_fd(ft_strjoin(cmd, ": command not found"), 1);
//		free(ps);
	}
	return (0);
}


void	get_args(int ac, char **av, t_pipex *ps, char **env)
{
	ps->infile = ft_strdup(av[1]);
	ps->cmd_1 = ft_strdup(av[2]);
	ps->cmd_2 = ft_strdup(av[3]);
	ps->outfile = ft_strdup(av[4]);
}
void	ft_exec(int i, t_pipex *ps, char *env[])
{
	char	*path;
	char	**cmd;

	if (i == 1)
	{
		path = path_cmd(ps, env, ps->cmd_1);
		cmd = ft_split(ps->cmd_1, ' ');
		execve(path, cmd, env);
	}
	else if (i == 2)
	{
		path = path_cmd(ps, env, ps->cmd_2);
		cmd = ft_split(ps->cmd_2, ' ');
		execve(path, cmd, env);
	}
}

/* ************************************************************************** */
/*  STDOUT_FILENO = 1                                                         */
/*  STDIN_FILENO  = 0                                                         */
/*  WRITE_END     = 1                                                         */
/*  READ_END      = 0                                                         */
/* ************************************************************************** */


void	ft_exec_cmd1(t_pipex *ps, char **env, int *fd)
{
	char	*path;
	char	**cmd;


	close(fd[READ_END]);
	ps->fd_1 = open(ps->infile, O_RDONLY);/*abrir archivo 1*/
	if (ps->fd_1 == -1)
		ft_open_error("zsh: permision denied: ", ps->infile, ps);
	dup2(ps->fd_1, STDIN_FILENO);
	close(ps->fd_1);
	dup2(fd[WRITE_END], STDOUT_FILENO);/**/
	close(fd[WRITE_END]);
	ft_exec(1, ps, env);
}

void	ft_exec_cmd2(t_pipex *ps, char **env, int *fd)
{
	char	*path;
	char	**cmd;

	ps->fd_2 = open(ps->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (ps->fd_2 == -1)
		ft_open_error("zsh: permision denied: ", ps->outfile, ps);
	dup2(fd[READ_END], STDIN_FILENO);
	close(fd[READ_END]);
	dup2(ps->fd_2, STDOUT_FILENO);
	close(ps->fd_2);
	ft_exec(2, ps, env);
}
