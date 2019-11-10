/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgovend <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:10:54 by jgovend           #+#    #+#             */
/*   Updated: 2018/08/17 10:11:59 by jgovend          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/includes/libft.h"
# include <stdlib.h>
# define OFFSET 4

typedef struct	s_coords
{
	int			x1;
	int			x2;
	int			y1;
	int			y2;
	int			yf;
	int			xf;
}				t_coords;

typedef struct	s_map
{
	int			r;
	int			c;
	char		**map;
	t_coords	tc;
}				t_map;

typedef struct	s_filler
{
	int			target[2];
	char		me;
	char		enemy;
	t_map		board;
	t_map		token;
	int			placement[2];
}				t_filler;

void			free_map(t_map *t);
void			trim_token(t_map *t);
void			colour(t_map board);
int				get_placement(t_filler *f);
void			set_target(t_filler *f);
int				trace(t_filler *f, int y, int x);

#endif
