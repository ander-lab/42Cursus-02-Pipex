/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:34:26 by ajimenez          #+#    #+#             */
/*   Updated: 2021/10/15 16:50:58 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include "../libft/libft.h"

#define READ_END	0
#define WRITE_END	1 	

typedef struct s_pipex{
	char	**paths;
	int		fd_1;
	int		fd_2;
	char	*infile;
	char	*outfile;
	char	*cmd_1;
	char	*cmd_2;
} t_pipex;

#endif
