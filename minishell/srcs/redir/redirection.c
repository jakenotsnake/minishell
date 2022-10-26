#include "../../mini.h"

void	rein(t_commands *in, int i)
{
	int infile;

	infile = open(in->cmds[in->re[i] + 1], O_RDONLY);
	if (infile < 0)
		error();
	dup2(infile, 0);
	in->cmds[in->re[i]] = 0;
}

void	reout(t_commands *in, int i)
{
	int outfile;

	outfile = open(in->cmds[in->re[i] + 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile < 0)
		error();
	dup2(outfile, 1);
}

void	reoutapp(t_commands *in, int i)
{
	int outfile;
	
	outfile = open(in->cmds[in->re[i] + 1], O_WRONLY | O_CREAT | O_TRUNC, O_APPEND, 0777);
	if (outfile < 0)
		error();
	dup2(outfile, 1);
	in->cmds[in->re[i]] = 0;
	in->cmds[in->re[i] + 1] = 0;
}