/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 22:35:04 by atemfack          #+#    #+#             */
/*   Updated: 2020/07/27 08:49:32 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		ft_obstacles(t_cub3d *cub3d, int x, int y)
{
	float	sprite_player[XY];

	if (x < 0 || x >= cub3d->map.rows || y < 0 || y >= cub3d->map.cols)
			return (1);
	if (cub3d->map.arr[x][y] < '2')
		return (cub3d->map.arr[x][y] == '1');
	cub3d->sprite[cub3d->nbr_sprite].x = x;
	cub3d->sprite[cub3d->nbr_sprite].y = y;
	sprite_player[X] = (x << T) + TILE_2 - cub3d->player.x;
	sprite_player[Y] = (y << T) + TILE_2 - cub3d->player.y;
	cub3d->sprite[cub3d->nbr_sprite].dst = sprite_player[X] * sprite_player[X] +
											sprite_player[Y] *sprite_player[Y];
	cub3d->nbr_sprite++;
	cub3d->map.arr[x][y] -= 8;
	return (0);
}

static float	ft_cast_find_horizontal_intersection(t_cub3d *cub3d)
{
	float	a[XY];
	float	step[XY];

	if (cub3d->ray.theta == PI || cub3d->ray.theta == 0.f)
		return (3.402823e+38f);
	step[X] = cub3d->ray.isfacingup ? -TILE : TILE;
	a[X] = cub3d->ray.isfacingup ? (((int)cub3d->player.x >> T) << T) :
								(((int)cub3d->player.x >> T) << T) + TILE;
	a[Y] = cub3d->player.y + (cub3d->player.x - a[X]) / cub3d->ray.tan_theta;
	step[Y] = -step[X] / cub3d->ray.tan_theta;
	while (!ft_obstacles(cub3d, (int)(a[X] + (cub3d->ray.isfacingup ? -1: 0))
							>> T, (int)a[Y] >> T))
	{
		a[X] += step[X];
		a[Y] += step[Y];
	}
	cub3d->ray.save[0] = (int)a[Y] % TILE;
	return ((a[X] - cub3d->player.x) * (a[X] - cub3d->player.x) +
					(a[Y] - cub3d->player.y) * (a[Y] - cub3d->player.y));
}

static float	ft_cast_find_vertical_intersection(t_cub3d *cub3d)
{
	float	a[XY];
	float	step[XY];

	if (cub3d->ray.theta == PI_90 || cub3d->ray.theta == PI_270)
		return (3.402823e+38f);
	step[Y] = cub3d->ray.isfacingleft ? -TILE : TILE;
	a[Y] = cub3d->ray.isfacingleft ? (((int)cub3d->player.y >> T) << T) :
								(((int)cub3d->player.y >> T) << T) + TILE;
	a[X] = cub3d->player.x + (cub3d->player.y - a[Y]) * cub3d->ray.tan_theta;
	step[X] = -step[Y] * cub3d->ray.tan_theta;
	while (!ft_obstacles(cub3d, (int)a[X] >> T, (int)(a[Y] +
				(cub3d->ray.isfacingleft ? -1: 0)) >> T))
	{
		a[Y] += step[Y];
		a[X] += step[X];
	}
	cub3d->ray.save[Y] = (int)a[X] % TILE;
	return ((a[X] - cub3d->player.x) * (a[X] - cub3d->player.x) +
					(a[Y] - cub3d->player.y) * (a[Y] - cub3d->player.y));
}

static void	ft_init_ray(t_cub3d *cub3d)
{
	cub3d->ray.cos_beta = cosf(cub3d->player.alpha - cub3d->ray.theta);
	if (cub3d->ray.theta < 0.)
		cub3d->ray.theta += PI_360;
	else if (cub3d->ray.theta > PI_360)
		cub3d->ray.theta -= PI_360;
	cub3d->ray.tan_theta = tanf(cub3d->ray.theta);
	cub3d->ray.isfacingup = (cub3d->ray.theta < PI) ? 1 : 0;
	cub3d->ray.isfacingleft = (cub3d->ray.theta > PI_90 && cub3d->ray.theta
		< PI_270) ? 1 : 0;
	cub3d->ray.hits_vertical = 0;
}

void	ft_ray_casting(t_cub3d *cub3d)
{
	float	dist[XY];

	cub3d->iray = cub3d->map.r[Y] - 1;
	cub3d->ray.theta = cub3d->player.alpha - FOV_2;
	cub3d->nbr_sprite = 0;
	while (cub3d->iray > -1)
	{
		ft_init_ray(cub3d);
		dist[X] = ft_cast_find_horizontal_intersection(cub3d);
		dist[Y] = ft_cast_find_vertical_intersection(cub3d);
		cub3d->ray.hits_vertical = dist[X] > dist[Y];
		cub3d->ray.zbuffer[cub3d->iray] = dist[cub3d->ray.hits_vertical];
		if (!cub3d->move[6])
			ft_render_wall(cub3d, cub3d->cst /
			(sqrtf(dist[cub3d->ray.hits_vertical]) * cub3d->ray.cos_beta));
		else
			(cub3d->ray.hits_vertical) ? ft_render_rays(cub3d, sqrtf(dist[Y]),
				0xBB2211) : ft_render_rays(cub3d, sqrtf(dist[X]), 0x1122BB);
		cub3d->ray.theta += cub3d->phi;
		cub3d->iray--;
	}
	if (cub3d->move[6])
		ft_reset_sprites(cub3d);
	else if (!cub3d->move[6] && cub3d->nbr_sprite)
		ft_render_sprites(cub3d);
}
