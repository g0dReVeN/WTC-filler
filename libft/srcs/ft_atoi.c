/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgovend <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:34:16 by jgovend           #+#    #+#             */
/*   Updated: 2018/06/01 14:35:14 by jgovend          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *str)
{
	int						sign;
	int						scount;
	unsigned long long int	num;

	sign = 1;
	scount = 0;
	num = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (++scount > 1)
			return (0);
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		num = num * 10 + *(str++) - '0';
	if (ft_llintlen(num) >= 19)
		return (sign == -1 ? 0 : -1);
	if (num > 9223372036854775807)
		return (sign == -1 ? 0 : -1);
	else
		return (num * sign);
}
