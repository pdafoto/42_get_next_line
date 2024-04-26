/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:13:56 by nperez-d          #+#    #+#             */
/*   Updated: 2024/04/26 13:24:30 by nperez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*keep_remain(char *saved_lines)
{
	int		i;
	char	*str;

	i = 0;
	while (saved_lines[i] != '\0' && saved_lines[i] != '\n')
		i++;
	if (saved_lines[i] == '\0')
	{
		free(saved_lines);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(saved_lines) - i + 1));
	if (!str)
		return (NULL);
	i++;
	ft_strlcpy(str, &saved_lines[i], ft_strlen(saved_lines) -i +1);
	free(saved_lines);
	return (str);
}

static char	*next_line(char *saved_lines)
{
	char	*str;
	int		i;

	i = 0;
	if (saved_lines[i] == '\0')
		return (NULL);
	while (saved_lines[i] != '\0' && saved_lines[i] != '\n')
		i++;
	str = (char *)malloc((i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, saved_lines, i + 1);
	if (saved_lines[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

static char	*read_file(int fd, char *saved_lines)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(saved_lines, '\n') && bytes_read != '\0')
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		saved_lines = ft_strjoin(saved_lines, buffer);
	}
	free(buffer);
	return (saved_lines);
}

char	*get_next_line(int fd)
{
	static char	*saved_lines[256];
	char		*line;

	if (fd < 0 || fd > 255)
		return (NULL);
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free (saved_lines[fd]);
		saved_lines[fd] = NULL;
		return (NULL);
	}
	saved_lines[fd] = read_file(fd, saved_lines[fd]);
	if (!saved_lines[fd])
		return (NULL);
	line = next_line(saved_lines[fd]);
	saved_lines[fd] = keep_remain(saved_lines[fd]);
	return (line);
}
