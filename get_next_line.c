/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
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
	static char	*buf;
	char	*next;
	char	*swap;
	
	if (BUFFER_SIZE <= 0)
		return (NULL);
	next = get_str(fd);
	if (!next && !buf)
		return (NULL);
	if (next)
		buf = ft_strjoin(buf, next);
	while (ft_strchr(next) && ft_strchr(buf))
	{
		free(next);
		next = get_str(fd);
		buf = ft_strjoin(buf, next);
	}
	free(next);
	swap = ft_strdup(buf);
	free(buf);
	buf = ft_strdup(line_split(swap, 0));
	if (!buf)
		free(buf);
	next = ft_strdup(line_split(swap, 1));
	free(swap);
	return (next);
}

int	main(void)
{
	int	fd;
	char	*test;

	fd = open("text.txt", O_RDONLY);
	test = get_next_line(fd);
	printf("1: %s", test);
	free(test);
	test = get_next_line(fd);
	printf("2: %s", test);
	free(test);
	test = get_next_line(fd);
	printf("3: %s", test);
	free(test);
	test = get_next_line(fd);
	printf("4: %s", test);
	free(test);
	test = get_next_line(fd);
	printf("5: %s", test);
	free(test);
	test = get_next_line(fd);
	printf("6: %s", test);
	free(test);
	test = get_next_line(fd);
	printf("7: %s", test);
	free(test);
	test = get_next_line(fd);
	printf("8: %s", test);
	free(test);
	test = get_next_line(fd);
	printf("9: %s", test);
	free(test);
	test = get_next_line(fd);
	printf("10: %s", test);
	free(test);
	printf("%s", get_next_line(fd));
}
