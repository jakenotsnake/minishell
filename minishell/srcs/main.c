/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <jtanner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:38:28 by jtanner           #+#    #+#             */
/*   Updated: 2022/11/02 13:12:07 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

int	main(int ac, char **av, char **envp)
{
	char		*line;
	t_commands	*inpt;
	char		**new_env;

	if (!g_exstat)
		g_exstat = 0;
	line = input();
	if (!line || line == NULL || (line[0] == '\0' && line[0] != '$'))
	{
		free(line);
		main(50, av, envp);
	}
	inpt = parseline(line, envp);
	free(line);
	if (line[0] == '\t')
		return (1);
	search(inpt);
	new_env = inpt->envp;
	freeall(inpt);
	main(50, av, new_env);
	ac = 10;
	return (1);
}
