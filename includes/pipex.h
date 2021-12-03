/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:34:26 by ajimenez          #+#    #+#             */
/*   Updated: 2021/12/03 17:58:58 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>

# define READ_END	0
# define WRITE_END	1 	

/*
** CMD FUNCTIONS
*/
void	ft_exec(char *to_exec, char **env);

#endif
