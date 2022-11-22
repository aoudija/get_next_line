/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:32:26 by aoudija           #+#    #+#             */
/*   Updated: 2022/11/22 23:39:40 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_utils.c"

char	*get_next_line(int fd)
{
	char	*s;
	char	*t;
	char	*b;
	int		i;
	int		j;

	i = 0;
	j = 0;
	s = malloc(1);
	while (read(fd, s, 1))
		t = ft_strjoin(t, s);
	while (i < BUFFER_SIZE - 1 && t[i] != '\n')
		i++;
	b = ft_substr(t, 0, i);
	return (b);
}

int	main(void)
{
	int		fd;
	char	*s;
	int		i;

	i = 0;
	fd = open("text.txt", O_RDWR);
	printf("fd = %d\n", fd);
	printf("%s\n", get_next_line(fd));
}
