/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgovend <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:46:38 by jgovend           #+#    #+#             */
/*   Updated: 2018/05/30 16:37:29 by jgovend          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	long int	n2;

	n2 = (long int)n;
	len = ft_llintlen(n2);
	if (n2 < 0)
		len++;
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (n2 < 0)
	{
		*str = '-';
		n2 *= -1;
	}
	len--;
	str[len] = n2 % 10 + '0';
	while (n2 /= 10)
		str[--len] = n2 % 10 + '0';
	return (str);
}
