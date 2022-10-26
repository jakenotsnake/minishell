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
		}
		free(path);
		i++;
	}
	freemult(paths);
	return (0);
}

void execute(t_commands *in)
{
	pid_t  pid;
    int    status;

    if ((pid = fork()) < 0)
       error();
    else if (pid == 0)
	{
		if (in->re[0] > 0)
			checkredir(in);
		if (!(execve(in->cmds[0], in->cmds, in->envp)))
			error();
		exit(1);
	}
	else
        while (wait(&status) != pid)
            ;
}