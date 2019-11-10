/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgovend <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:54:13 by jgovend           #+#    #+#             */
/*   Updated: 2018/06/02 16:39:41 by jgovend          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*str;

	if (s)
	{
		i = 0;
		j = ft_strlen(s) - 1;
		while (ft_isspace(s[i]) && s[i] != '\0')
			i++;
		while (ft_isspace(s[j]) && j > 0)
			j--;
		j = j - i + 1;
		if (j <= 0)
			return (ft_strsub(s, 0, 0));
		str = ft_strsub(s, i, j);
		return (str);
	}
	return (NULL);
}
