#include "../mini.h"

void	error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

void	checkline(char *line)
{
	int i;

	i = 1;
	while (line[i])
	{
		if (line[i] == ' ' && line[i - 1] == ' ')
			error();
		if (line[i] == '\'' && line[i - 1] == '\'')
			error();
		if (line[i] == '\"' && line[i - 1] == '\"')
			error();
		i++;
	}
	checkclose(line);
}

void	checkclose(char *line)
{
	int		i;
	char	cmp;

	i = 1;
	while (line[i])
	{
		while(line[i] != '\'' && line[i] != '\"' && line[i])
			i++;
		if (!line[i])
			return ;
		cmp = line[i];
		i++;
		while (line[i] != cmp && line[i])
			i++;
		if (!line[i])
			error();
		i++;
	}
}