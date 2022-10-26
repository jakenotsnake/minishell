#include "../mini.h"

int	main(int ac, char **av, char **envp)
{
	char		*line;
	t_commands	*inpt;

	if (ac != 50)
		printf("\e[1;1H\e[2J");
	line = input();
	inpt = parseline(line, envp);
	free(line);
	
	if (line[0] == '\0')
		return (1);
	search(inpt);
	freeall(inpt);
	main(50, av, envp);
}