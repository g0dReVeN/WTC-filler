/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strresize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgovend <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 13:52:24 by jgovend           #+#    #+#             */
/*   Updated: 2018/06/16 13:58:59 by jgovend          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strresize(char *oldstr, size_t newsize)
{
	char	*newstr;

	if (ft_strlen(oldstr) >= newsize)
		return (NULL);
	newstr = ft_strnew(newsize);
	if (!newstr)
		return (NULL);
	newstr = ft_strncpy(newstr, oldstr, ft_strlen(oldstr));
	free(oldstr);
	return (newstr);
}
