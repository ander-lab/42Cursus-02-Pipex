/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:34:26 by ajimenez          #+#    #+#             */
/*   Updated: 2021/10/22 17:39:19 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include "../libft/libft.h"
#include <fcntl.h>

#define READ_END	0
#define WRITE_END	1 	

/*
** STRUCTURE
*/
typedef struct s_pipex{
	char	**paths;
	char	*infile;
	char	*outfile;
	char	*cmd_1;
	char	*cmd_2;
	int		fd_1;
	int		fd_2;
} t_pipex;

/*
** CMD FUNCTIONS
*/
char	*path_cmd(t_pipex *ps, char **envp, char *cmd);
void	ft_exec_child_1(t_pipex *ps, char **env, int *fd);
void	ft_exec_child_2(t_pipex *ps, char **env, int *fd);
void	free_ps(t_pipex *ps);
void	ft_exec(int i, t_pipex *ps, char *env[]);
/*
** GET ARGS
*/
void	get_args(char **av, t_pipex *ps);
void	ft_open_error(char *s, char *s2);

#endif
