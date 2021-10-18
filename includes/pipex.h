/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajimenez <ajimenez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:34:26 by ajimenez          #+#    #+#             */
/*   Updated: 2021/10/18 15:44:35 by ajimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include "../libft/libft.h"
#include <fcntl.h>

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

/*
**
*/
char	*path_cmd(t_pipex *ps, char **envp, char *cmd);
void	ft_exec_cmd1(t_pipex *ps, char **env, int *fd);
void	get_args(int ac, char **av, t_pipex *ps, char **env);
void	ft_exec_cmd1(t_pipex *ps, char **env, int *fd);
void	ft_exec_cmd2(t_pipex *ps, char **env, int *fd);

#endif
