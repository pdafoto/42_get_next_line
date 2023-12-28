/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:03:33 by nperez-d          #+#    #+#             */
/*   Updated: 2023/12/28 09:36:01 by nperez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Counts the characters of a string.
size_t	ft_strlen(const char *s)
{
	int	ctr;

	ctr = 0;
	while (*s)
	{
		ctr++;
		s++;
	}
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
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			return ((char *)s + i);
		i++;
	}
	if (ch == '\0')
		return ((char *)s + i);
	return (NULL);
}

// Concatenate two strings s1 and s2, creating a new dynamically allocated
// string s3 that contains the combined characters of s1 and s2.
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		s1_len;
	int		s2_len;
	int		i;
	int		j;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s3 = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	return (s3);
}

// Copy dstsize - 1 characters from the source string src to the destination
// string dst ensuring that the destination string is null-terminated.
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (src[i])
		i++;
	if (dstsize < 1)
		return (i);
	j = 0;
	while (src[j] && j < (dstsize - 1))
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}
