/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:04:34 by aoudija           #+#    #+#             */
/*   Updated: 2022/12/04 08:21:00 by aoudija          ###   ########.fr       */
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

char *add_char(char *s)
{
	char *p = calloc(strlen(s) + 1, 1);
	int  i = -1;
	while (s[++i])
		p[i] = s[i];
	p[i++] = 0;
	free(s);
	return p;
}

int main()
{
	char *p = ft_strdup("1");

	char *s = ft_strdup("1");
	int j = 0;
	int  k = 1;
	int fd[OPEN_MAX + 1];
	while (j < OPEN_MAX)
	{
		fopen(s, "w+");
		fd[j] = open(s, O_RDWR);
		write(fd[j], p, strlen(p));
		s = add_char(ft_itoa(k));
		p = add_char(p);
		if (k == 1)
			p = add_char(p);			
		// if (k == 10)
		// 	k = 0;
		k++;
		j++;
	}
	
	// free(s);
	j = 0;
	k = 1;
	s = ft_strdup("1");
	while(j < 9000)
	{
		fd[j] = open(s, O_RDWR);
		char *d = get_next_line(fd[j]);
		while (d)
		{
		printf("%s\n", d);
		free(d);
		d = get_next_line(fd[j]);
		}
		printf("--------------------\n");
		j++;
		s = add_char(ft_itoa(k));
		// if (k == 10)
		// 	k = 0;
		k++;
		usleep(10000);
	}
	// int fd = open("text.txt",O_RDWR);
	// // int fd2 = open("t2.txt",O_RDWR);
	// char *s;
	// char *t;
	// // s = get_next_line_bonus(fd2); 
	// t = get_next_line_bonus(fd); 
	// int i = 0;
	// while (i < 1000)
	// {
	// 	open("t")
	// }
	// while (s && t)
	// {
	// 	printf("%s",s);
	// 	printf("%s",t);
	// 	s = get_next_line_bonus(fd2);
	// 	t = get_next_line_bonus(fd);
	// }
}