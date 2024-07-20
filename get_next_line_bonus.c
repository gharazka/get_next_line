/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gharazka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:55:35 by gharazka          #+#    #+#             */
/*   Updated: 2023/11/19 20:00:08 by gharazka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_str(int fd)
{
	char	*str;
	str = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
	if (!str)
		return (NULL);
	if (read(fd, str, BUFFER_SIZE) <= 0)
	{
		free(str);
		return (NULL);
	}
	str[BUFFER_SIZE] = 0;
	return (str);
}


char	*line_split(char *s1, int side)
{
	int	i;

	i = 0;
	while (s1[i] != '\n' && s1[i] != 0)
		i++;
	if (side == 0 && (s1[i] == 0 || s1[i + 1] == 0))
		return (NULL);
	if (side == 1 && (s1[i] == 0 || s1[i + 1] == 0))
		return (s1);
	if (side == 0 && s1[i] == '\n')
		return (&s1[i + 1]);
	if (side == 1)
		s1[i + 1] = 0;
	return (s1);
}

char	*get_next_line(int fd)
{
	static char	*buf[2048];
	char	*next;
	char	*swap;
	
	if (BUFFER_SIZE <= 0)
		return (NULL);
	next = get_str(fd);
	if (!next && !buf[fd])
		return (NULL);
	if (next)
		buf[fd] = ft_strjoin(buf[fd], next);
	while (ft_strchr(next) && ft_strchr(buf[fd]))
	{
		free(next);
		next = get_str(fd);
		buf[fd] = ft_strjoin(buf[fd], next);
	}
	free(next);
	swap = ft_strdup(buf[fd]);
	free(buf[fd]);
	buf[fd] = ft_strdup(line_split(swap, 0));
	if (!buf[fd])
		free(buf[fd]);
	next = ft_strdup(line_split(swap, 1));
	free(swap);
	return (next);
}


