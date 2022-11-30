/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:32:26 by aoudija           #+#    #+#             */
/*   Updated: 2022/11/30 15:34:09 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*s;
	static char	*t;
	char		*b;
	int			i;

	i = 1;
	if (BUFFER_SIZE > 2147483647)
		return (NULL);
	else if (BUFFER_SIZE == 2147483647)
		s = malloc(BUFFER_SIZE);
	else
		s = malloc(BUFFER_SIZE + 1);
	if (!s)
		return (NULL);
	while (i)
	{
		s = malloc(BUFFER_SIZE + 1);
		i = read(fd, s, BUFFER_SIZE);
		if (i == -1)
		{
			free(s);
			return (NULL);
		}
		s[i] = 0;
		free(t);
		t = ft_strjoin(t, s);
		if (!t)
			return (NULL);
		if (ft_strchr(s, '\n') != 0)
		{
			free(s);
			break ;
		}
		free(s);
	}
	i = 0;
	while (t[i] && t[i] != '\n')
		i++;
	b = malloc(i + 1);
	if (!b)
	{
		free(t);
		return (NULL);
	}
	i = 0;
	while (t[i] != '\n' && t[i])
	{
		b[i] = t[i];
		i++;
	}
	b[i] = '\n';
	b[i + 1] = 0;
	free(t);
	t = ft_substr(t, i + 1, ft_strlen(t) - i);
	if (!t)
	{
		free(b);
		return (NULL);
	}
	return (b);
}

int main()
{
	int fd = open("text.txt",O_RDWR);
	// char *s;
	// s = get_next_line(fd);
	// printf("%s", s);
	// free(s);
	printf("%s",get_next_line(fd));
	while (1);
}