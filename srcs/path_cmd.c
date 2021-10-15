
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
}

