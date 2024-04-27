/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:39:59 by nperez-d          #+#    #+#             */
/*   Updated: 2024/04/27 14:52:27 by nperez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd_1;
	int		fd_2;
	int		fd_3;
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 1;
	fd_1 = open("test.txt", O_RDONLY);
	fd_2 = open("test2.txt", O_RDONLY);
	fd_3 = open("test3.txt", O_RDONLY);
	while (i < 20)
	{
		line = get_next_line(fd_1);
		printf("fd_1 - Linea [%d]:\n%s\n", j, line);
		free(line);
		line = get_next_line(fd_2);
		printf("fd_2 - Linea [%d]:\n%s\n", j, line);
		free(line);
		line = get_next_line(fd_3);
		printf("fd_3 - Linea [%d]:\n%s\n", j, line);
		free(line);
		i++;
		j++;
	}
	close(fd_1);
	close(fd_2);
	close(fd_3);
	return (0);
}
