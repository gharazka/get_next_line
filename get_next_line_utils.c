#include "get_next_line.h"

void    *ft_calloc(size_t nmemb, size_t size)
{
	void		*result_ptr;
	size_t	i;

	i = 0;
	if (nmemb == 0 || size == 0)
	{
		result_ptr = malloc(0);
		return (result_ptr);
	}
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	result_ptr = malloc(size * nmemb);
	if (!result_ptr)
		return (NULL);
	while (i < size * nmemb)
	{
		((unsigned char *)result_ptr)[i] = 0;
		i++;
	}
	return (result_ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*full;
	int		i;
	int		j;
	
	if (!s2)
		return (s1);
	full = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	i = 0;
	j = 0;
	while (s1 && s1[i] != 0)
	{
		full[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		full[i + j] = s2[j];
		j++;
	}
	full[i + j] = 0;
	if (s1)
		free(s1);
	return (full);
}

size_t	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	int		size;
	int		i;
	char	*dest;

	if (!s)
		return (NULL);
	i = 0;
	size = ft_strlen(s);
	dest = (char *)ft_calloc(size + 1, 1);
	while (s[i] != 0)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int	ft_strchr(char *str)
{
	int	i;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}
