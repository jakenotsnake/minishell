/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorman.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <jtanner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:41:43 by jtanner           #+#    #+#             */
/*   Updated: 2022/11/02 12:51:16 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

void	error(char *str)
{
	fprintf(stderr, "%s\n", str);
	exit(errno);
}

void	checkline(char *line)
{
	int	i;

	i = 1;
	while (line[i])
	{
		if (line[i] == ' ' && line[i - 1] == ' ')
			error("Error: Invalid argument");
		if (line[i] == '\'' && line[i - 1] == '\'')
			error("Error: Invalid argument");
		if (line[i] == '\"' && line[i - 1] == '\"')
			error("Error: Invalid argument");
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
		while (line[i] != '\'' && line[i] != '\"' && line[i])
			i++;
		if (!line[i])
			return ;
		cmp = line[i];
		i++;
		while (line[i] != cmp && line[i])
			i++;
		if (!line[i])
			error("Error: No end quote");
		i++;
	}
}

char	*checkdollar(char *line)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	line = checkquest(line);
	while (line[i])
	{
		while ((line[i] != '\'' && line[i] != '\0') || line[i] == '$')
		{
			if (x % 2 == 0)
				if (line[i] == '$' && line[i])
					line = replacedol(line, i);
			i++;
		}
		x++;
		if (line[i])
			i++;
	}
	return (line);
}
