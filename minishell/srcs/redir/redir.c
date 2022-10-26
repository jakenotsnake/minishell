#include "../../mini.h"

void findredir(t_commands *in)
{
	int	i;

	i = 0;
	in->i = 0;
	in->s_ind = 1;
	while (in->cmds[in->s_ind] != 0)
	{
		if (in->cmds[in->s_ind][0] == '>')
			in->re[i++] = in->s_ind;
		if (in->cmds[in->s_ind][0] == '<')
			in->re[i++] = in->s_ind;
		in->s_ind++;
	}
	in->re[i++] = 0;
}

void checkredir(t_commands *in)
{
	int	i;

	i = 0;
	while (in->re[i] != 0)
	{
		if (in->cmds[in->re[i]][0] == '>' && in->cmds[in->re[i]][1] == '>')
			reoutapp(in, i);
	//	else if (in->cmds[in->re[i]][in->i] == '<' && in->cmds[in->s_ind][in->i + 1] == '<')
	//		delinpt(in, i);
		else if (in->cmds[in->re[i]][0] == '>')
			reout(in, i);
		else if (in->cmds[in->re[i]][0] == '<')
			rein(in, i);
		i++;
	}
}