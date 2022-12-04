/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:04:34 by aoudija           #+#    #+#             */
/*   Updated: 2022/12/04 10:02:24 by aoudija          ###   ########.fr       */
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
			return (free(t[fd]), NULL);
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
	{
		free(str[fd]);
		return (NULL);
	}
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
	static char	*t[1024];
	char		*line;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	t[fd] = ft_read(fd, buffer, t);
	free(buffer);
	line = ft_line(t,fd);
	t[fd] = ft_substr(t[fd], ft_strlen(line), ft_strlen(t[fd]) - ft_strlen(line) + 1);
	return (line);
}

int main()
{
	char	*file_name = ft_strdup("");
	char	text[10] = "line_test";
	char	*s = ft_strdup(",");
	int		i;
	int		j;
	int		fd[OPEN_MAX];
	// i = 1;
	// j = 0;
	// char *z = get_next_line(3);
	// while (j < OPEN_MAX)
	// {
	// 	free(file_name);
	// 	file_name = ft_strjoin(s,ft_itoa(i));
	// 	fopen(file_name,"w+");
	// 	fd[j] = open(file_name, O_RDWR);
	// 	write(fd[j] , text, ft_strlen(text));
	// 	i++;
	// 	j++;
	// }
	// int	x, y;
	// x = y = 0;
	// while (x < OPEN_MAX && y < OPEN_MAX)
	// {
	// 	free(file_name);
	// 	file_name = ft_strjoin(s,ft_itoa(y));
	// 	fopen(file_name,"w+");
	// 	fd[x] = open(file_name, O_RDWR);
	// 	printf("%s\n", get_next_line(fd[x]));
	// 	x++;
	// 	y++;
	// }
	int fd1 = open(",4897", O_RDONLY);
	int fd2 = open(",4890", O_RDONLY);
	printf("%s",get_next_line(fd1));
	printf("%s",get_next_line(fd2));
	printf("%s",get_next_line(fd1));
	printf("%s",get_next_line(fd2));
	
}