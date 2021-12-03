/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:58:56 by ajimenez          #+#    #+#             */
/*   Updated: 2021/12/03 17:48:12 by ajimenez         ###   ########.fr       */
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

void	ft_open_error(char *s, char *s2)
{
	ft_putstr_fd(s, 2);
	ft_putstr_fd(s2, 2);
	exit(1);
}
