/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:58:56 by ajimenez          #+#    #+#             */
/*   Updated: 2021/10/23 11:04:58 by Alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	check_call(int ac)
{
	if (ac != 5)
	{
		ft_putstr_fd("Args should be: $> ./pipex file1 cmd1 cmd2 file2", 1);
		exit(1);
	}
}

void	get_args(char **av, t_pipex *ps)
{
	ps->infile = ft_strdup(av[1]);
	ps->cmd_1 = ft_strdup(av[2]);
	ps->cmd_2 = ft_strdup(av[3]);
	ps->outfile = ft_strdup(av[4]);
}

void	free_ps(t_pipex *ps)
{
	free(ps->cmd_1);
	free(ps->cmd_2);
	free(ps->infile);
	free(ps->outfile);
}

void	ft_open_error(char *s, char *s2)
{
	ft_putstr_fd(s, 1);
	ft_putstr_fd(s2, 1);
	exit(1);
}
