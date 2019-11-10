/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgovend <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:51:22 by jgovend           #+#    #+#             */
/*   Updated: 2018/05/28 11:57:40 by jgovend          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char *dst;

	dst = (char *)(malloc)(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dst)
		return (NULL);
	return (ft_strcpy(dst, s1));
}
