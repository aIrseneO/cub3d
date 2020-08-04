/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 19:06:55 by atemfack          #+#    #+#             */
/*   Updated: 2020/08/01 21:49:21 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static uint32_t		ft_color_tile(t_cub3d *cub3d, int x, int y)
{
	if (cub3d->map.arr[x][y] == '.')
		return (HUD_VOID);
	else if (cub3d->map.arr[x][y] == ' ')
		return (0x000000);
	else if (cub3d->map.arr[x][y] == '1')
		return (HUD_WALLS);
	else
		return (HUD_SPRITES);
}

static void		ft_put_pixel(t_cub3d *cub3d, int hud[XY], uint32_t color)
{
	int			i;
	int			j;

	i = 0;
	while (i < cub3d->hud.tile[X])
	{
		j = 0;
		while (j < cub3d->hud.tile[Y])
			cub3d->hud.arr[i + hud[X]][j++ + hud[Y]] = color;
		i++;
	}
}

void		ft_load_hud(t_cub3d *cub3d)
{
	int		start_map[XY];
	int		start_hud[XY];

	start_map[X] = 0;
	start_hud[X] = 0;
	while (start_map[X] < cub3d->map.rows)
	{
		start_map[Y] = 0;
		start_hud[Y] = 0;
		while (start_map[Y] < cub3d->map.cols)
		{
			ft_put_pixel(cub3d, start_hud, ft_color_tile(cub3d,
						start_map[X], start_map[Y]));
			start_map[Y]++;
			start_hud[Y] += cub3d->hud.tile[Y];
		}
		start_map[X]++;
		start_hud[X] += cub3d->hud.tile[X];
	}
}
