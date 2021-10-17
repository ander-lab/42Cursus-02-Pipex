/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:22:55 by ajimenez          #+#    #+#             */
/*   Updated: 2021/10/17 16:11:45 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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
		ft_putstr_fd(ft_strjoin(cmd, ": command not found"), 1);
	return (0);
}

void	exec_cmd(t_pipex *ps, char *env[])
{
	char	*path;
	char	**cmd;

	path = path_cmd(ps, env, ps->cmd_1);
	cmd = ft_split(ps->cmd_1, ' ');
	execve(path, cmd, env);
}

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
	int		fd1[2];
	int		fd2[2];

	if (ac != 5)
		return (0);
	ps = calloc(sizeof(t_pipex), 1);
	get_args(ac, av, ps, env);
	exec_cmd(ps, env);
	atexit(leak);
	return (0);
}
