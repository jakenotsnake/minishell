/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <jtanner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:44:08 by jtanner           #+#    #+#             */
/*   Updated: 2022/11/02 13:08:41 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

int	changedir(t_commands *in)
{
	if ((chdir(in->cmds[1]) == -1))
		error("Error: Invalid directory");
	return (1);
}

int	exporter(t_commands *in)
{
	int		i;
	int		x;

	x = 1;
	i = 0;
	while (in->envp[i])
	{
		if (1 == (ft_strnstr(in->envp[i], in->cmds[1],
					(strlenc(in->cmds[1], '=')))))
		{
			x = 2;
			break ;
		}
		i++;
	}
	in->envp[i++] = jstrcpy(in->cmds[1], 0, ft_strlen(in->cmds[1]));
	if (x != 1)
		while (in->envp[i])
			i++;
	in->envp[i] = NULL;
	return (1);
}

int	unset(t_commands *in)
{
	int	i;

	i = 0;
	while (in->envp[i])
	{
		if (ft_strnstr(in->envp[i], in->cmds[1], ft_strlen(in->cmds[1])))
			break ;
		i++;
	}
	if (!(in->envp[i]))
		error("Error: No Matching ENV Variable");
	while (in->envp[i + 1])
	{
		in->envp[i] = jstrcpy(in->envp[i + 1], 0, ft_strlen(in->envp[i + 1]));
		i++;
	}
	in->envp[i] = NULL;
	return (1);
}

int	strlenc(char *str, char d)
{
	int	i;

	i = 0;
	while (str[i] != d && str[i])
		i++;
	i--;
	return (i);
}
