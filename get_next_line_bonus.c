/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:04:34 by aoudija           #+#    #+#             */
/*   Updated: 2022/12/05 17:43:21 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <string.h>
#include <limits.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	c = (char) c;
	while (i <= ft_strlen(s))
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char	*ft_read(int fd, char *buffer, char **t)
{
	int	i;

	i = 1;
	while (i)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			if (t[fd])
				free(t[fd]);
			return (NULL);
		}
		buffer[i] = 0;
		t[fd] = ft_strjoin(t[fd], buffer);
		if (!t[fd])
			return (NULL);
		if (ft_strchr(buffer, '\n') != 0)
			break ;
	}
	if (t[fd][0] == 0)
	{
		free(t[fd]);
		return (NULL);
	}
	return (t[fd]);
}

char	*ft_line(char **str, int fd)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[fd])
		return (NULL);
	while (str[fd][i] != '\n' && str[fd][i])
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (str[fd][i] != '\n' && str[fd][i])
	{
		line[i] = str[fd][i];
		i++;
	}
	line[i] = str[fd][i];
	line[i + 1] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*t[OPEN_MAX];
	char		*line;
	int			len;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	t[fd] = ft_read(fd, buffer, t);
	free(buffer);
	line = ft_line(t, fd);
	len = ft_strlen(t[fd]) - ft_strlen(line) + 1;
	t[fd] = ft_substr(t[fd], ft_strlen(line), len);
	return (line);
}
