/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:03:33 by nperez-d          #+#    #+#             */
/*   Updated: 2023/12/28 11:06:42 by nperez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Counts the characters of a string.
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

// Searches for the first occurrence of a character in a string and
// returns a pointer to its location, or NULL if the character is not found.
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

// Concatenate two strings s1 and s2, creating a new dynamically allocated
// string s3 that contains the combined characters of s1 and s2.
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

// Copy dstsize - 1 characters from the source string src to the destination
// string dst ensuring that the destination string is null-terminated.
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
