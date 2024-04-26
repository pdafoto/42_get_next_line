/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:03:33 by nperez-d          #+#    #+#             */
/*   Updated: 2024/04/26 13:25:48 by nperez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	ctr;

	ctr = 0;
	if (!s)
		return (0);
	while (s[ctr] != '\0')
		ctr++;
	return (ctr);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	i = 0;
	ch = c;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)(s + i));
		i++;
	}
	if (ch == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			s3[i] = s1[i];
	while (s2[j] != '\0')
		s3[i++] = s2[j++];
	s3[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (s3);
}

unsigned int	ft_strlcpy(char *dst, char *src, unsigned int dstsize)
{
	unsigned int	j;

	if (!dstsize)
		return ((unsigned int) ft_strlen(src));
	j = 0;
	while (src[j] != '\0' && j < (dstsize - 1))
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return ((unsigned int) ft_strlen(src));
}
