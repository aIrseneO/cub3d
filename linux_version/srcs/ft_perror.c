/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 22:05:34 by atemfack          #+#    #+#             */
/*   Updated: 2020/08/04 20:25:53 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** For all this functins if n = -42 no error message will be print out
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
	return ((n == -42) ? FAILED : ft_perror(n));
}

int	ft_close(int fd)
{
	close(fd);
	return (FAILED);
}

int	ft_perror_free(int n, char *str, t_map *map)
{
	if (str)
		free(str);
	if (map)
		return (ft_perror_free_map(n, map));
	if (n == -42)
		return (FAILED);
	return (ft_perror(n));
}

int	ft_perror_free_cub3d(int n, t_cub3d *cub3d)
{
	int		i;

	if (cub3d->ray.zbuffer)
		free(cub3d->ray.zbuffer);
	if (cub3d->sprite)
		free(cub3d->sprite);
	if (cub3d->img.ptr)
		mlx_destroy_image(cub3d->mlx_ptr, cub3d->img.ptr);
	if (cub3d->win_ptr)
		mlx_destroy_window(cub3d->mlx_ptr, cub3d->win_ptr);
	i = 0;
	while (i < TEXTURES)
	{
		if (cub3d->txt[i].ptr)
			mlx_destroy_image(cub3d->mlx_ptr, cub3d->txt[i].ptr);
		i++;
	}
	if (cub3d->hud.arr)
	{
		i = 0;
		while (i < cub3d->hud.r[X])
			free(cub3d->hud.arr[i++]);
		free(cub3d->hud.arr);
	}
	return (ft_perror_free_map(n, &cub3d->map));
}

int	ft_perror(int n)
{
	if (n == 0)
		ft_putendl_fd("Error\ninvalid map, incomplete", 1);
	else if (n == -1)
		perror("Error\n");
	else if (n == -2)
		ft_putendl_fd("Error\nUsage $./a.out [--save] map.cub", 1);
	else if (n == -3)
		ft_putendl_fd("Error\n", 1);
	else if (n == -4)
		ft_putendl_fd("Error\nInvalid map, check elements", 1);
	else if (n == -5)
		ft_putendl_fd("Error\nInvalid map, check F and/or C color line(s)", 1);
	else if (n == -6)
		ft_putendl_fd("Error\nInvalid map, check textures lines", 1);
	else if (n == -7)
		ft_putendl_fd("Error\nInvalid map, check Resolution line", 1);
	else if (n == -8)
		ft_putendl_fd("Error\nInvalid map, check content", 1);
	else if (n == -9)
		ft_putendl_fd("Error\nInvalid map, check NSWE in content", 1);
	else if (n == -10)
		ft_putendl_fd("Error\nInvalid map, check surroundings", 1);
	return (FAILED);
}
