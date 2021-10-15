/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:22:55 by ajimenez          #+#    #+#             */
/*   Updated: 2021/10/15 17:43:55 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	path_cmd(t_pipex *ps, char **envp)
{
	ssize_t	i;


	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			ps->paths = ft_split(ft_strchr(envp[i], '/'), ':');
		i++;
	}
	ft_putmatrix(ps->paths, 10);
}

void	get_args(int ac, char **av, t_pipex *ps, char **env)
{
	ps->infile = ft_strdup(av[1]);
	ps->cmd_1 = ft_strdup(av[2]);
	ps->cmd_2 = ft_strdup(av[3]);
	ps->outfile = ft_strdup(av[4]);

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
	pid = fork();
	if (pid > 0)
		close(ps->fd_1[WRITE_END]);
	path_cmd(ps, env);

	return (0);
}
