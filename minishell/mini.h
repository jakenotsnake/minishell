/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <jtanner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:47:22 by jtanner           #+#    #+#             */
/*   Updated: 2022/11/02 13:32:12 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <signal.h>
# include <string.h>
# define INT_MAX	2147483647
# define INT_MIN	-2147483648
# define _OPEN_SYS_ITOA_EXT

int								g_exstat;

typedef struct s_commands		t_commands;

typedef struct s_commands
{
	int			*fdout;
	int			*fdin;
	int			args;
	char		**cmds;
	char		**envp;
	int			i;
	int			s_ind;
	int			*re;
}				t_commands;

int			main(int ac, char **av, char **envp);
char		*input(void);
char		*jstrcpy(char *s, int st, int f);
int			jstrlen(char *s);
char		**split(char *s, char c);
char		*parsequote(char *line, t_commands *in);
t_commands	*parseline(char *line, char **envp);
int			countwords(char *line);
void		freeall(t_commands *in);
void		malcomm(t_commands *in, char **envp);
void		error(char *str);
void		checkline(char *line);
void		checkclose(char *line);
char		**getpaths(char	**envp);
char		*findpath(char *cmd, char **envp);
void		execute(t_commands *in);
void		search(t_commands *in);
void		findexe(t_commands *in);
int			ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		**ft_split(char const *s, char c, int n);
void		freemult(char **args);
void		findredir(t_commands *in);
void		checkredir(t_commands *in);
void		rein(t_commands *in, int i);
void		reout(t_commands *in, int i);
void		reoutapp(t_commands *in, int i);
int			changedir(t_commands *in);
int			exporter(t_commands *in);
int			other(t_commands *in);
int			unset(t_commands *in);
int			strlenc(char *str, char d);
void		cont(int sig);
char		*checkdollar(char *line);
char		*replacedol(char *line, int i);
char		*checkquest(char *line);
char		*exitstat(char *line, int i);
char		*ft_itoa(int n);
void		delinpt(t_commands	*in, int i);
void		cont1(int sig);
#endif