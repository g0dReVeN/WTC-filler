/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgovend <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 14:10:42 by jgovend           #+#    #+#             */
/*   Updated: 2018/06/02 14:15:36 by jgovend          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		ft_find_word(const char *s, char c, char **stra, int i)
{
	int		len;
	int		space;

	space = 0;
	len = 0;
	while (*s == c)
	{
		s++;
		space++;
	}
	while (s[len] && s[len] != c)
		len++;
	if (len > 0)
	{
		stra[i] = ft_strnew(len);
		ft_strncpy(stra[i], s, len);
	}
	return (space + len);
}

static int		ft_wcount(const char *s, char c, int i)
{
	while (*s == c)
		s++;
	while (*s)
	{
		while (*s && *s != c)
			s++;
		while (*s == c)
			s++;
		i++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int		len;
	char	**stra;
	int		i;
	int		wc;

	if (!s)
		return (NULL);
	wc = ft_wcount(s, c, 0);
	len = 0;
	stra = (char **)ft_memalloc((wc + 1) * sizeof(char *));
	if (!stra)
		return (NULL);
	i = 0;
	len = 0;
	while (*s)
	{
		len = ft_find_word(s, c, stra, i++);
		s += len;
	}
	stra[wc] = 0;
	return (stra);
}
