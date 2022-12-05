/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:32:26 by aoudija           #+#    #+#             */
/*   Updated: 2022/12/05 17:43:53 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_read(int fd, char *buffer, char *t)
{
	int	i;

	i = 1;
	while (i)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			if (t)
				free(t);
			return (NULL);
		}
		buffer[i] = 0;
		t = ft_strjoin(t, buffer);
		if (!t)
			return (NULL);
		if (ft_strchr(buffer, '\n') != 0)
			break ;
	}
	if (t[0] == 0)
	{
		free(t);
		return (NULL);
	}
	return (t);
}

char	*ft_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		line[i] = str[i];
		i++;
	}
	line[i] = str[i];
	line[i + 1] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*t;
	char		*line;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	t = ft_read(fd, buffer, t);
	free(buffer);
	line = ft_line(t);
	t = ft_substr(t, ft_strlen(line), ft_strlen(t) - ft_strlen(line) + 1);
	return (line);
}
