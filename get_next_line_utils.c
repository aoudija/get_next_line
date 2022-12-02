/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:27:10 by aoudija           #+#    #+#             */
/*   Updated: 2022/12/02 12:38:05 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (dst == NULL || size == 0)
		return (ft_strlen (src));
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	d;

	d = ft_strlen(dst);
	i = 0;
	if (n <= d)
		return (n + ft_strlen(src));
	while (*dst)
		dst++;
	while (src[i] && i < n - d - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (d + ft_strlen(src));
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	s2 = (char *)malloc(ft_strlen(s1) + 1);
	if (s2 == NULL)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	char	*sj;
	int		d;
	int		s;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (s1);
	d = ft_strlen(s1);
	s = ft_strlen(s2);
	len = d + s;
	sj = malloc(len + 1);
	if (sj == NULL)
		return (NULL);
	ft_strlcpy(sj, s1, d + 1);
	ft_strlcat(sj, s2, len + 1);
	free(s1);
	return (sj);
}

char	*ft_optimize(char *s, unsigned int start, char *sub, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			sub[j] = s[i];
			j++;
		}
		i++;
	}
	sub[j] = 0;
	free(s);
	return (sub);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	if (len < (ft_strlen(s) - start))
		sub = malloc(len + 1);
	else
		sub = malloc(ft_strlen(s) - start + 1);
	if (!sub)
		return (NULL);
	return (ft_optimize(s, start, sub, len));
}
