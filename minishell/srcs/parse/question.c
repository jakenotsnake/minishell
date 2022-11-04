/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   question.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <jtanner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:51:06 by jtanner           #+#    #+#             */
/*   Updated: 2022/11/02 13:11:11 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mini.h"

char	*replacedol2(char *line, char *new, char *temp, int i)
{
	int	j;
	int	c;

	j = 0;
	c = jstrlen(new);
	while (temp[j])
	{
		new[c] = temp[j];
		c++;
		j++;
	}
	while (line[i])
	{
		new[c] = line[i];
		c++;
		i++;
	}
	new[c] = '\0';
	return (new);
}

char	*replacedol(char *line, int i)
{
	int		c;
	int		j;
	char	*env;
	char	*new;

	c = 0;
	j = 0;
	new = malloc(sizeof(*new) * 1000);
	env = malloc(sizeof(*new) * 100);
	while (c < i)
	{
		new[c] = line[c];
		c++;
	}
	i++;
	while ((line[i] != ' ' && line[i] != '\"' ) && line[i])
	{
		env[j] = line[i];
		j++;
		i++;
	}
	env = getenv(env);
	line = replacedol2(line, new, env, i);
	return (line);
}

char	*checkquest(char *line)
{
	int	i;

	i = 0;
	while (line[i++])
		if (line[i] == '?' && line[i - 1] == '$')
			line = exitstat(line, i - 1);
	return (line);
}

char	*exitstat(char *line, int i)
{
	int		j;
	int		q;
	char	*c;
	char	*new;

	j = -1;
	q = 0;
	new = malloc(sizeof(char) * 1000);
	c = ft_itoa(g_exstat);
	while (line[i])
	{
		while (j++ < i - 1)
			new[j] = line[j];
		while (c[q])
			new[j++] = c[q++];
		i = i + 2;
		while (line[i])
			new[j++] = line[i++];
	}
	new[j] = '\0';
	return (new);
}
