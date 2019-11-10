/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgovend <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:53:59 by jgovend           #+#    #+#             */
/*   Updated: 2018/06/16 14:01:43 by jgovend          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*h2;
	char	*n2;

	h2 = (char *)haystack;
	n2 = (char *)needle;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		h2 = (char *)haystack;
		n2 = (char *)needle;
		while (*n2 != '\0' && *h2 == *n2)
		{
			h2++;
			n2++;
			if (*n2 == '\0')
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
