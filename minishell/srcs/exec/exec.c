/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <jtanner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:36:57 by jtanner           #+#    #+#             */
/*   Updated: 2022/11/02 13:07:03 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mini.h"

char	**getpaths(char	**envp)
{
	int		i;
	char	**paths;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	paths = ft_split(envp[i] + 5, ':', -1000);
	return (paths);
}

char	*findpath(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*temp;
	int		i;

	i = 0;
	if (ft_strnstr(cmd, "/", ft_strlen(cmd)))
		return (cmd);
	paths = getpaths(envp);
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path, F_OK) == 0)
		{	
			return (path);
			free(path);
		}
		free(path);
		i++;
	}
	freemult(paths);
	return (cmd);
}

void	execute(t_commands *in)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid == 0)
	{
		if (in->re[0] > 0)
			checkredir(in);
		execve(in->cmds[0], in->cmds, in->envp);
		if (errno == 2)
			errno = 127;
		error("Error: Command not found");
	}
	else
		while (wait(&status) != pid)
			;
	g_exstat = WEXITSTATUS(status);
	if (g_exstat != 0)
		strerror(g_exstat);
}
