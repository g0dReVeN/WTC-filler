/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgovend <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 12:13:40 by jgovend           #+#    #+#             */
/*   Updated: 2018/06/25 09:10:34 by jgovend          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	read_line(const int fd, char *buff, char **line)
{
	int		rd;
	int		lenr;
	int		size;
	int		ret;

	size = BUFF_SIZE;
	ret = 0;
	(ft_strlen(*line) > 0) && (ret++);
	while ((rd = read(fd, buff, BUFF_SIZE)) > 0)
	{
		lenr = 0;
		while (lenr < rd && buff[lenr] != '\n')
			lenr++;
		if ((size - (int)ft_strlen(*line) - lenr - 1) < 0)
			if (!(*line = ft_strresize(*line, size *= 2)))
				return (-1);
		ret = 1;
		*line = ft_strncat(*line, buff, lenr);
		(rd < BUFF_SIZE) && (buff[rd] = '\0');
		(lenr == BUFF_SIZE) && (lenr--);
		if (buff[lenr] == '\n' || rd < BUFF_SIZE)
			return (1);
	}
	return (ret ? 1 : rd);
}

int			get_next_line(const int fd, char **line)
{
	static char	buff[10000][BUFF_SIZE];
	char		*str;
	size_t		i;
	size_t		j;

	if (fd < 0 || fd > 9999 || !line)
		return (-1);
	if ((str = ft_strnew(BUFF_SIZE)) == NULL)
		return (-1);
	*line = str;
	i = -1;
	while (++i < BUFF_SIZE && buff[fd][i] != '\n')
		buff[fd][i] = '\0';
	if (i == BUFF_SIZE)
		return (read_line(fd, buff[fd], line));
	buff[fd][i] = '\0';
	if (++i == BUFF_SIZE || ft_strlen(i + buff[fd]) == 0)
		return (read_line(fd, buff[fd], line));
	j = -1;
	while ((++j + i) < BUFF_SIZE && buff[fd][i + j] != '\n')
		*(*line + j) = buff[fd][i + j];
	if ((j + i) < BUFF_SIZE && buff[fd][i + j] == '\n')
		return (1);
	return (read_line(fd, buff[fd], line));
}
