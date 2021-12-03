/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:13:34 by ajimenez          #+#    #+#             */
/*   Updated: 2021/12/03 17:46:26 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <sys/_types/_size_t.h>
#include <unistd.h>

static char	**get_path(char **env)
{
	size_t	i;
	char 	**path;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			path = ft_split(ft_strchr(env[i], '/'), ':');
		i++;
	} 
	return (path);
}

static char	*path_cmd(char **env, char *cmd)
{
	ssize_t	i;
	char	*path;
	char	*tmp;
	char	**env_path;

	i = 0;
	path = NULL;
	env_path = get_path(env);
	while (env_path)
	{
		tmp = ft_strjoin(env_path[i], "/");
		path = ft_strjoin(tmp, ft_split(cmd, ' ')[0]);
		free(tmp);
		if (access(path, R_OK) == 0)
			return (path);
		i++;
	}
	ft_putstr_fd(ft_strjoin(cmd, " :command not found"), 2);
	return (0);
}

void	ft_exec(char *to_exec, char **env)
{
	char	*path;
	char	**cmd;

	cmd =  ft_split(to_exec, ' ');
	if (ft_strchr(cmd[0], '/'))
	{
		path = cmd[0];
		if (access(path, X_OK) == -1)
		{
			ft_putstr_fd(ft_strjoin(to_exec, ":command not found\n"), 2);
			return ;
		}
	}
	else
		path = path_cmd(env, to_exec);
	execve(path, cmd, env);
}
