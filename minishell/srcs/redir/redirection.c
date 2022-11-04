/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <jtanner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:20:27 by jtanner           #+#    #+#             */
/*   Updated: 2022/11/02 12:23:12 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mini.h"

void	rmarr(t_commands *in, int i)
{
	int	j;

	j = in->re[i];
	while (in->cmds[j + 2])
	{
		in->cmds[j] = in->cmds[j + 2];
		j++;
	}
	in->cmds[j] = 0;
}

void	rein(t_commands *in, int i)
{
	int	infile;

	infile = open(in->cmds[in->re[i] + 1], O_RDONLY);
	if (infile < 0)
		error("Error: File or command does not exit");
	dup2(infile, 0);
	rmarr(in, i);
}

void	reout(t_commands *in, int i)
{
	int	outfile;

	outfile = open(in->cmds[in->re[i] + 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile < 0)
		error("Error: File or command does not exit");
	dup2(outfile, 1);
	rmarr(in, i);
}

void	reoutapp(t_commands *in, int i)
{
	int	outfile;

	outfile = open(in->cmds[in->re[i] + 1], O_WRONLY
			| O_CREAT | O_APPEND, 0777);
	if (outfile < 0)
		error("Error: File or command does not exit");
	dup2(outfile, 1);
	rmarr(in, i);
}

void	delinpt(t_commands	*in, int i)
{
	char	c;
	int		j;
	int		q;

	j = 0;
	c = in->cmds[in->re[i] + 1][0];
	rmarr(in, i);
	while (in->cmds[j])
	{
		q = 0;
		while (in->cmds[j][q] != c && in->cmds[j][q])
			q++;
		if (in->cmds[j][q] == c)
		{
			while (in->cmds[j][q] != '\0')
				in->cmds[j][q++] = '\0';
			break ;
		}
		else
			j++;
	}
	while (in->cmds[j++])
		in->cmds[j] = NULL;
	j = 0;
}
