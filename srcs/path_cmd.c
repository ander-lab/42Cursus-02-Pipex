/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:13:34 by ajimenez          #+#    #+#             */
/*   Updated: 2021/10/22 17:00:50 by ajimenez         ###   ########.fr       */
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
	{
		ft_putstr_fd(ft_strjoin(cmd, ": command not found"), 1);
	}
	return (0);
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
