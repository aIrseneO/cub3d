/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 20:56:49 by atemfack          #+#    #+#             */
/*   Updated: 2020/06/13 13:09:31 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int get_next_line(const int fd, char **line);

//gw -D BUFFER_SIZE=32 main.c get_next_line.c get_next_line_utils.c

int main(int argc, char **argv)
{
	int		i, n, fd;
	char	*line = NULL;

	if (argc != 2)
	{
		printf("Usage: ./[binary_name] [path]\n");
		return (-1);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		printf("Opening failure\n");
		return (1);
	}
	i = 1;
	while ((n = get_next_line(fd, &line)) >= 0)
	{
		if (n == 0 && !(*line))
		{
			free(line);
			break ;
		}
		printf("line %d: %s| n = %d\n", i++, line, n);
		free(line);
	}
	printf("<== n = %d ==>\n", n);
	close(fd);
	return (1);
}
