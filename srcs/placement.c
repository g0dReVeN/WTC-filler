/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgovend <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:17:49 by jgovend           #+#    #+#             */
/*   Updated: 2018/08/17 10:19:31 by jgovend          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	bot_fill(t_filler *f)
{
	int	i;
	int	j;

	i = f->board.r;
	while (--i > -1)
	{
		j = f->board.c;
		while (--j > -1)
		{
			f->placement[0] = (i - f->token.tc.y1);
			f->placement[1] = (j - f->token.tc.x1);
			if (trace(f, i, j))
				return (1);
		}
	}
	return (0);
}

int	top_fill(t_filler *f)
{
	int	i;
	int	j;

	i = -1;
	while (++i < f->board.r)
	{
		j = -1;
		while (++j < f->board.c)
		{
			f->placement[0] = (i - f->token.tc.y1);
			f->placement[1] = (j - f->token.tc.x1);
			if (trace(f, i, j))
				return (1);
		}
	}
	return (0);
}

int	left_fill(t_filler *f)
{
	int	i;
	int	j;
	int	d;

	d = f->board.c - 1;
	i = -1;
	while (++i < f->board.r)
	{
		j = -1;
		while (++j < f->board.c)
		{
			if (trace(f, i, j))
				if (j < d)
				{
					d = j;
					f->placement[0] = (i - f->token.tc.y1);
					f->placement[1] = (j - f->token.tc.x1);
				}
		}
	}
	return ((d == f->board.c - 1) ? 0 : 1);
}

int	right_fill(t_filler *f)
{
	int	i;
	int	j;
	int	d;

	d = 0;
	i = -1;
	while (++i < f->board.r)
	{
		j = f->board.c;
		while (--j > -1)
		{
			if (trace(f, i, j))
				if (j > d)
				{
					d = j;
					f->placement[0] = (i - f->token.tc.y1);
					f->placement[1] = (j - f->token.tc.x1);
				}
		}
	}
	return ((d == 0) ? 0 : 1);
}

int	get_placement(t_filler *f)
{
	int	ret;

	ret = 0;
	set_target(f);
	if (f->target[0] == 0)
		(left_fill(f)) && (ret = 1);
	else if (f->target[1] == 0)
		(right_fill(f)) && (ret = 1);
	else if ((f->board.r * f->board.c) > 1000 && f->me == 'O')
		(top_fill(f)) && (ret = 1);
	else if (f->me == 'O' || (f->board.r * f->board.c) > 1000)
		(bot_fill(f)) && (ret = 1);
	(!ret && top_fill(f)) && (ret = 1);
	return (ret);
}
