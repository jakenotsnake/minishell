#include "../../mini.h"

t_commands	*parseline(char *line, char **envp)
{
	t_commands	*in;
	int			c;
	
	checkline(line);
	in = malloc(sizeof(t_commands));
	malcomm(in, envp);
	in->cmds = malloc(sizeof(char *) * (countwords(line) + 1));
	c = 0;
	while (line[in->i])
	{
		while ((line[in->i] != ' ' && line[in->i] != '\'' && line[in->i] != '\"') && line[in->i])
			in->i++;
		if (line[in->i] != '\'' && line[in->i] != '\"')
			in->cmds[c++] = jstrcpy(line, in->s_ind, in->i);
		if (!line[in->i])
			break; 
		if (line[in->i] == '\'' || line[in->i] == '\"')
			in->cmds[c++] = parsequote(line, in);
		in->i++;
		in->s_ind = in->i;
	}
	in->cmds[c] = 0;
	in->args = c - 1;
	return (in);
}

char	*parsequote(char *line, t_commands *in)
{
	char comp;
	char *ret;

	comp = line[in->i];
	in->s_ind++;
	in->i++;
	while (line[in->i] != comp && line[in->i] != '\0')
		in->i++;
	ret = jstrcpy(line, in->s_ind, in->i);
	in->i++;
	return (ret);
}

void	malcomm(t_commands *in, char **envp)
{
	in->i = (int)malloc(sizeof(int));
	in->s_ind = (int)malloc(sizeof(int));
	in->i = 0;
	in->s_ind = 0;
	in->args = (int)malloc(sizeof(int));
	in->envp = envp;
	in->re = malloc(sizeof(int) *10);
}