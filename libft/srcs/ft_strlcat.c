/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgovend <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:52:07 by jgovend           #+#    #+#             */
/*   Updated: 2018/05/31 14:00:26 by jgovend          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	pos;
	size_t	d;
	size_t	s;

	pos = ft_strlen(dst);
	d = pos;
	s = ft_strlen(src);
	while (pos + 1 < dstsize && *src != '\0')
	{
		*(dst + pos++) = *(src++);
	}
	dst[pos] = '\0';
	if (d < dstsize)
		return (s + d);
	else
		return (s + dstsize);
}
