#include "../../mini.h"

char *jstrcpy(char *s, int st, int f)
{
	char *n;
	int i;

	i = 0;
	n = malloc(sizeof (char) * ((f - st) + 1));
	while (st < f)
	{
		n[i] = s[st];
		i++;
		st++;
	}
	n[i] = '\0';
	return (n);
}

int	jstrlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	countwords(char *line)
{
	int i;
	int	c;

	i  = 0;
	c = 0;
	while (line[i])
	{
		while ((line[i] != ' ' && line[i] != '\'' && line[i] != '\"') && line[i])
			i++;
		c++;
		if (!line[i])
			break; 
		if (line[i] == '\'' || line[i] == '\"')
		{
			i++;	
			while (line[i] != '\'' && line[i] != '\"' && line[i])
				i++;
			c++;
		}
		i++;
	}
	return (c);
}

void	freeall(t_commands *in)
{
	free(in);
}