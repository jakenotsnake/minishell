#include "../../mini.h"

char *input(void)
{
	char *line;

	line = (char *)NULL;
	line = readline("Jakes Wolrd~: ");
	return (line);
}

void search(t_commands *in)
{
	findredir(in);
	findexe(in);
	execute(in);
}

void findexe(t_commands *in)
{
	char	*buff;
	int		i;

	i = 0;
	buff = in->cmds[0];
	in->cmds[0] = findpath(buff, in->envp);
}

