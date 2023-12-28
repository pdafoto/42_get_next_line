/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:02:19 by nperez-d          #+#    #+#             */
/*   Updated: 2023/12/28 10:31:46 by nperez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Function to keep everything after newline in a string:
// 1. Initialize iterator to 0.
// 2. Iterate until null or newline is found.
// 3. If null is found free saved_lines.
// 4. If allocate memory for str.
// 5. Increment i by 1 to move past the newline character.
// 6. Use ft_strlcpy to copy save_lines from i to str.
// 7. Free saved_lines.
// 8. Return str.
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

// Function to extract the next line from saved_lines:
// 1. Initialize iterator to 0.
// 2. Return NULL if the first character of saved_lines is null.
// 3. Iterate over saved_lines until a newline or null is found.
// 4. Allocate memory for a string of size i+1.
// 5. Use ft_strlcpy to copy i characters from saved_lines into str.
// 6. If character at position i is newline append it to str and increment i.
// 7. Append terminating null at position i.
// 8. Return str.
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

// Function to read fd until a new line is found:
// 1. Allocate a buffer of BUFFER_SIZE+1.
// 2. Reads fd and store the number of bytes_read.
// 3. Frees buffer and returns NULL if read operation fails.
// 4. Append \0 at the end of read data in buffer.
// 5. Uses ft_strjoin to join read data with existing saved_lines.
// 6. Repeat 2-5 until ft_strchr finds newline or end of fd is reached.
// 7. Free buffer and return the saved_lines string.
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

// Main function:
// 1. Error control (fd negative, buffer size not specified, nothing read).
// 2. Calls read_file and saves its result into saved_lines (temporray line).
// 3. Calls next_line and saves its result into line.
// 4. Call keep_remain and saves result into new saved_lines (temporray line).
// 5. Return line pointer to the start of next line.
char	*get_next_line(int fd)
{
	static char	*saved_lines;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free (saved_lines);
		saved_lines = NULL;
		return (0);
	}
	saved_lines = read_file(fd, saved_lines);
	if (!saved_lines)
		return (NULL);
	line = next_line(saved_lines);
	saved_lines = keep_remain(saved_lines);
	return (line);
}
