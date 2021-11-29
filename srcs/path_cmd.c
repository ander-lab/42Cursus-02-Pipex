/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:13:34 by ajimenez          #+#    #+#             */
/*   Updated: 2021/11/29 17:01:41 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <sys/_types/_size_t.h>
#include <unistd.h>

char	*path_cmd(t_pipex *ps, char **envp, char *cmd)
{
	ssize_t	i;
	char	*path;
	char	*tmp;

	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			ps->paths = ft_split(ft_strchr(envp[i], '/'), ':');
	} i = 0;
	while (ps->paths[i])
	{
		tmp = ft_strjoin(ps->paths[i], "/");
		path = ft_strjoin(tmp, ft_split(cmd, ' ')[0]);
		free(tmp);
		if (access(path, R_OK) == 0)
			return (path);
		i++;
	}
	return (0);
}

size_t	count_chars(char c, char *str)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] != 0)
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}
char *cut_cmd(char *cmd)
{

	cmd = ft_strrchr(cmd, '/');
	cmd++;
	return (cmd);
}

char	*get_relative_path(char *cmd)
{
	char	*path;
	size_t	aux;
	size_t	slash;
	size_t	i;

	aux = count_chars('/', cmd);
	slash = 0;
	i = 0;
	while (slash < aux && !ft_strchr(cut_cmd(cmd), cmd[i]))
	{
		if (cmd[i] == '/')
			slash++;
		i++;
	}
	path = ft_calloc(i, sizeof(char));
	ft_memcpy(path, cmd, i);
	return (path);
}

void	ft_exec_2(char *to_exec, char *env[], t_pipex *ps)
{
	char	*path;
	char	**cmd;

	//ft_putstr_fd(to_exec, 2);
	//ft_putstr_fd("\n", 2);
	//ft_putstr_fd(ft_strjoin(get_relative_path(to_exec), ft_split(cut_cmd(to_exec), ' ')[0]), 2);
	//write(2, "\n", 1);
	//ft_putstr_fd("\n-------DEBUGGER 00-------\n", 2);
	if (path_cmd(ps, env, to_exec))
	{
		ft_putstr_fd("\n-------DEBUGGER 02-------\n", 2);
		path = path_cmd(ps, env, to_exec);
		cmd = ft_split(to_exec, ' ');
		execve(path, cmd, env);
		//TODO Mensaje de error y env -i
		//ft_putstr_fd(ft_strjoin(to_exec, " :command not found"), 2);
	}
	else if (access(ft_strjoin(get_relative_path(to_exec), ft_split(cut_cmd(to_exec), ' ')[0]), X_OK) == 0)
	{
		ft_putstr_fd("\n-------DEBUGGER 01-------\n", 2);
		cmd = ft_split(cut_cmd(to_exec), ' ');
		path = ft_strjoin(get_relative_path(to_exec), cmd[0]);
		ft_putstr_fd(path, 2);
		execve(path, cmd, env);
//		ft_putstr_fd("\n", 2);
//		ft_putstr_fd(cmd[0], 2);
//		ft_putstr_fd(cmd[1], 2);
	}
	//else
	//{
	//}
}
