/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:01:29 by nperez-d          #+#    #+#             */
/*   Updated: 2024/04/26 14:24:06 by nperez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 1;
	fd = open("test.txt", O_RDONLY);
	while (i < 10)
	{
		line = get_next_line(fd);
		printf("Linea [%d]:\n%s\n", j, line);
		free(line);
		i++;
		j++;
	}
	close(fd);
	return (0);
}
