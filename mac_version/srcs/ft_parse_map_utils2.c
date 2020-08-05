/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 13:20:46 by atemfack          #+#    #+#             */
/*   Updated: 2020/08/04 20:24:52 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ft_adjust_resolution_if_needed(t_map *map)
{
	if (map->r[X] < HEIGHT_MIN)
		map->r[X] = HEIGHT_MIN;
	else if (map->r[X] > HEIGHT_MAX)
		map->r[X] = HEIGHT_MAX;
	if (map->r[Y] < WIDTH_MIN)
		map->r[Y] = WIDTH_MIN;
	else if (map->r[Y] > WIDTH_MAX)
		map->r[Y] = WIDTH_MAX;
}

static void		ft_print_map(t_map map)
{
	uint16_t	i;
	uint16_t	j;

	ft_printf("R X:%d Y:%d\nNO |%s|\nSO |%s|\nWE |%s|\nEA |%s|\nS |%s|\n",
		map.r[X], map.r[Y], map.txt[NORTH], map.txt[SOUTH],
		map.txt[WEST], map.txt[EAST], map.txt[SPRITE]);
	ft_printf("F %#x\nC %#x\n", map.floor_color, map.ceilling_color);
	i = 0;
	while (i < map.rows)
	{
		j = 0;
		while (j < map.cols)
			ft_printf("%c", map.arr[i][j++]);
		ft_printf("\n");
		i++;
	}
	ft_printf(" %d sprite(s)\n", map.nbr_sprites);
	ft_printf("rows = %d, cols = %d\n", map.rows, map.cols);
	ft_printf("Px = %d, Py = %d, direction = %c\n", map.p[X],
	map.p[Y], map.p_alpha);
}

int				ft_check_map_surroundings(t_map *map, int rows, int cols)
{
	int			i;
	int			j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if ((map->arr[i][j] == '.' || map->arr[i][j] == '2') &&
			(j == 0 || j == cols - 1 || i == 0 || i == rows - 1 ||
			map->arr[i - 1][j - 1] == ' ' || map->arr[i - 1][j] == ' ' ||
			map->arr[i - 1][j + 1] == ' ' || map->arr[i][j - 1] == ' ' ||
			map->arr[i][j + 1] == ' ' || map->arr[i + 1][j - 1] == ' ' ||
			map->arr[i + 1][j] == ' ' || map->arr[i + 1][j + 1] == ' '))
				return (FAILED);
			if (map->arr[i][j] == '2')
				map->nbr_sprites++;
			j++;
		}
		i++;
	}
	ft_adjust_resolution_if_needed(map);
	(void)ft_print_map;
	return (SUCCESS);
}
