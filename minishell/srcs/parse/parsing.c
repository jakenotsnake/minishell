/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <jtanner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:31:48 by jtanner           #+#    #+#             */
/*   Updated: 2022/11/02 13:15:36 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mini.h"

void	parse(t_commands *in, char *line)
{
	int	c;

	c = 0;
	while (line[in->i])
	{
		while ((line[in->i] != ' ' && line[in->i] != '\''
				&& line[in->i] != '\"') && line[in->i])
			in->i++;
		if (line[in->i] != '\'' && line[in->i] != '\"')
			in->cmds[c++] = jstrcpy(line, in->s_ind, in->i);
		if (!line[in->i])
			break ;
		if (line[in->i] == '\'' || line[in->i] == '\"')
			in->cmds[c++] = parsequote(line, in);
		in->i++;
		in->s_ind = in->i;
	}
	in->cmds[c] = 0;
	in->args = c - 1;
}

t_commands	*parseline(char *line, char **envp)
{
	t_commands	*in;

	checkline(line);
	line = checkdollar(line);
	in = malloc(sizeof(t_commands));
	malcomm(in, envp);
	in->cmds = malloc(sizeof(char *) * (countwords(line) + 1));
	parse(in, line);
	return (in);
}

char	*parsequote(char *line, t_commands *in)
{
	char	comp;
	char	*ret;

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
	in->re = malloc(sizeof(int) * 10);
}
