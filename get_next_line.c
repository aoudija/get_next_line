/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:32:26 by aoudija           #+#    #+#             */
/*   Updated: 2022/11/25 11:15:58 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_utils.c"

char	*get_next_line(int fd)
{
	char		*s;
	static char	*t;
	char		*b;
	int			i;

	i = 1;
	s = malloc(BUFFER_SIZE + 1);
	while (i)
	{
		i = read(fd, s, BUFFER_SIZE);
		s[i] = 0;
		t = ft_strjoin(t, s);
		if (strchr(s, '\n') != 0)
			break ;
	}
	while (t[i] && t[i] != '\n')
		i++;
	b = malloc(i + 1);
	i = 0;
	while (t[i] != '\n' && t[i])
	{
		b[i] = t[i];
		i++;
	}
	b[i] = '\n';
	t = ft_substr(t, i + 1, ft_strlen(t) - i);
	return (b);
}

int	main(void)
{
	int		fd;
	char	*s;
	int		i;

	i = 0;
	fd = open("text.txt", O_RDWR);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
