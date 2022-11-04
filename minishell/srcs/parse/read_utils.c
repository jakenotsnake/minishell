/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <jtanner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:30:23 by jtanner           #+#    #+#             */
/*   Updated: 2022/11/02 13:33:22 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mini.h"

void	search(t_commands *in)
{
	findredir(in);
	if (other(in))
		return ;
	findexe(in);
	execute(in);
}

void	findexe(t_commands *in)
{
	char	*buff;
	int		i;

	i = 0;
	buff = in->cmds[0];
	in->cmds[0] = findpath(buff, in->envp);
}

int	other(t_commands *in)
{
	int	i;

	i = 0;
	if (ft_strnstr(in->cmds[0], "cd", 2))
		i = changedir(in);
	if (ft_strnstr(in->cmds[0], "unset", 5))
		i = unset(in);
	if (ft_strnstr(in->cmds[0], "export", 6))
		i = exporter(in);
	if (ft_strnstr(in->cmds[0], "exit", 4))
	{
		kill(0, SIGKILL);
		exit(0);
		i = 1;
	}
	return (i);
}

void	cont1(int sig)
{
	if (sig == SIGINT)
		return ;
	if (sig == SIGQUIT)
		return ;
	if (sig == SIGTSTP)
		exit(0);
	(void)sig;
}
