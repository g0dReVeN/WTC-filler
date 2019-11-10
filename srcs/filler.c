/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgovend <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:12:23 by jgovend           #+#    #+#             */
/*   Updated: 2018/08/17 10:16:55 by jgovend          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	place(int i, int j, int k)
{
	char	*line;

	ft_putnbr(i);
	ft_putchar(' ');
	ft_putnbr(j);
	ft_putchar('\n');
	if (k)
	{
		get_next_line(0, &line);
		ft_strdel(&line);
	}
}

void	read_board(t_map *m, int offset)
{
	int		i;
	char	*line;

	if (offset)
	{
		get_next_line(0, &line);
		ft_strdel(&line);
	}
	i = -1;
	while (++i < m->r)
	{
		ft_strdel(&m->map[i]);
		get_next_line(0, &line);
		m->map[i] = ft_strndup(offset + line, m->c);
		ft_strdel(&line);
	}
	if (!offset)
		trim_token(m);
}

void	read_token(t_map *m)
{
	char	*line;

	get_next_line(0, &line);
	m->r = ft_atoi(ft_strchr(line, ' '));
	m->c = ft_atoi(ft_strchr(ft_strchr(line, ' ') + 1, ' '));
	m->map = (char **)ft_memalloc(sizeof(char*) * m->r);
	ft_strdel(&line);
	read_board(m, 0);
}

void	init(t_filler *f)
{
	char	*line;

	get_next_line(0, &line);
	f->me = (line[10] == '1' ? 'O' : 'X');
	f->enemy = (f->me == 'O' ? 'X' : 'O');
	ft_strdel(&line);
	while ((get_next_line(0, &line) > -1) && ft_strncmp(line, "Plateau", 7))
		ft_strdel(&line);
	f->board.r = ft_atoi(ft_strchr(line, ' '));
	f->board.c = ft_atoi(ft_strchr(ft_strchr(line, ' ') + 1, ' '));
	f->board.map = (char **)ft_memalloc(sizeof(char*) * f->board.r);
	f->placement[0] = 0;
	f->placement[1] = 0;
	f->target[0] = 0;
	f->target[1] = 0;
	ft_strdel(&line);
}

int		main(void)
{
	t_filler	f;

	init(&f);
	while (1)
	{
		read_board(&f.board, OFFSET);
		colour(f.board);
		read_token(&f.token);
		if (get_placement(&f))
			place(f.placement[0], f.placement[1], 1);
		else
			break ;
		free_map(&f.token);
	}
	free_map(&f.board);
	place(0, 0, 0);
	return (0);
}
