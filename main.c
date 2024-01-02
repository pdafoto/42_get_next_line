/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:01:29 by nperez-d          #+#    #+#             */
/*   Updated: 2024/01/02 20:26:00 by nperez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test2.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}

// #include <stdio.h>
// #include "get_next_line.h"

// int	main(void)
// {
// 	char	*line;
// 	int		fd;

// fd = fileno(stdin);
// line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 	}

// 	return (0);
// }
