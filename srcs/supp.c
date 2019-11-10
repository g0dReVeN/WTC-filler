/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgovend <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:17:10 by jgovend           #+#    #+#             */
/*   Updated: 2018/08/17 10:59:57 by jgovend          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	free_map(t_map *m)
{
	int	i;

	i = 0;
	while (i < m->r)
		ft_strdel(&m->map[i++]);
	ft_strdel(m->map);
}

void	trim_token(t_map *token)
{
	int i;
	int j;

	token->tc.x1 = token->c;
	token->tc.y1 = token->r;
	token->tc.x2 = 0;
	token->tc.y2 = 0;
	i = -1;
	while (++i < token->r)
	{
		j = -1;
		while (++j < token->c)
		{
			if (token->map[i][j] == '*')
			{
				(i < token->tc.y1) && (token->tc.y1 = i);
				(i > token->tc.y2) && (token->tc.y2 = i);
				(j < token->tc.x1) && (token->tc.x1 = j);
				(j > token->tc.x2) && (token->tc.x2 = j);
			}
		}
	}
	token->tc.yf = token->tc.y2 - token->tc.y1 + 1;
	token->tc.xf = token->tc.x2 - token->tc.x1 + 1;
}

void	set_target(t_filler *f)
{
	int	i;

	i = -1;
	while (++i < f->board.r)
	{
		if (f->board.map[i][0] == f->me)
			f->target[0] = 1;
		if (f->board.map[i][f->board.c - 1] == f->me)
			f->target[1] = 1;
	}
}

int		trace(t_filler *f, int y, int x)
{
	int	i;
	int	j;
	int	k;

	if ((f->token.tc.yf + y) > f->board.r || (f->token.tc.xf + x) > f->board.c)
		return (0);
	k = 0;
	i = -1;
	while (++i < f->token.tc.yf)
	{
		j = -1;
		while (++j < f->token.tc.xf)
		{
			if (f->token.map[f->token.tc.y1 + i][f->token.tc.x1 + j] == '*')
			{
				(f->board.map[i + y][j + x] == f->me) && k++;
				if (f->board.map[i + y][j + x] == f->enemy || k > 1)
					return (0);
			}
		}
	}
	return (k == 1 ? 1 : 0);
}

void	colour(t_map board)
{
	int	i;
	int	j;

	ft_putstr_fd("\e[1;1H\e[2J", 2);
	i = -1;
	while (++i < board.r)
	{
		j = -1;
		while (++j < board.c)
		{
			ft_putstr_fd("\x1b[0m", 2);
			if (board.map[i][j] == 'O' || board.map[i][j] == 'o')
				ft_putstr_fd("\x1b[31m", 2);
			else if (board.map[i][j] == 'X' || board.map[i][j] == 'x')
				ft_putstr_fd("\x1b[34m", 2);
			write(2, &(board.map[i][j]), 1);
		}
		write(2, "\n", 1);
	}
	ft_putstr_fd("\x1b[32m", 2);
}
