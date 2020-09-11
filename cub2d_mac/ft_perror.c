/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 22:05:34 by atemfack          #+#    #+#             */
/*   Updated: 2020/07/09 12:46:00 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
   For all this functins if n = -42 no error message will be print out
*/

int	ft_perror_free_map(int n, t_map *map)
{
	int	i;

	i = -1;
	while (i++ < 4)
		if (map->txt[i])
			free(map->txt[i]);
	if (map->content)
		ft_lstclear(&map->content, free);
	if (map->arr)
	{
		i = 0;
		while (i < map->rows)
			free(map->arr[i++]);
		free(map->arr);
	}
	return ((n == -42) ? -1 : ft_perror(n));
}

int	ft_close(int fd)
{
	close(fd);
	return (-1);
}

int	ft_perror_free(int n, char *str, t_map *map)
{
	if (str)
		free(str);
	if (map)
		return (ft_perror_free_map(n, map));
	if (n == -42)
		return (-1);
	return (ft_perror(n));
}

int	ft_perror(int n)
{
	if (n == 0)
		ft_putendl_fd("Error: invalid map, incomplete", 1);
	else if (n == -1)
		perror("Error");
	else if (n == -2)
		ft_putendl_fd("Error: Usage $./a.out [--save] map.cub", 1);
	else if (n == -3)
		ft_putendl_fd("Error: ", 1);
	else if (n == -4)
		ft_putendl_fd("Error: invalid map, check elements", 1);
	else if (n == -5)
		ft_putendl_fd("Error: invalid map, check F & C color line", 1);
	else if (n == -6)
		ft_putendl_fd("Error: invalid map, check textures lines", 1);
	else if (n == -7)
		ft_putendl_fd("Error: invalid map, check Resolution line", 1);
	else if (n == -8)
		ft_putendl_fd("Error: invalid map, check content", 1);
	else if (n == -9)
		ft_putendl_fd("Error: invalid map, check NSWE in content", 1);
	else if (n == -10)
		ft_putendl_fd("Error: invalid map, check surroundings", 1);
	return (-1);
}
