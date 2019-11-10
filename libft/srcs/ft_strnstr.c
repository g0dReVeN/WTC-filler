/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgovend <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:53:31 by jgovend           #+#    #+#             */
/*   Updated: 2018/06/16 14:00:41 by jgovend          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	char	*h2;
	char	*n2;
	size_t	i;

	if (*needle == '\0')
		return ((char *)hay);
	while (*hay && len)
	{
		h2 = (char *)hay;
		n2 = (char *)needle;
		i = len;
		while (*h2 && *n2 && *h2 == *n2 && i--)
		{
			h2++;
			n2++;
			if (*n2 == '\0')
				return ((char *)hay);
		}
		hay++;
		len--;
	}
	return (NULL);
}
