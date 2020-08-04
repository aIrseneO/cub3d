/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_3D_utils1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 22:35:04 by atemfack          #+#    #+#             */
/*   Updated: 2020/08/01 19:36:14 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		ft_obstacles(t_cub3d *cub3d, int x, int y)
{
	float	sprite_cam[XY];

	if (x < 0 || x >= cub3d->map.rows || y < 0 || y >= cub3d->map.cols)
			return (1);
	if (cub3d->map.arr[x][y] < '2')
		return (cub3d->map.arr[x][y] == '1');
	cub3d->sprite[cub3d->nbr_sprite_seen].x = x;
	cub3d->sprite[cub3d->nbr_sprite_seen].y = y;
	sprite_cam[X] = (x << T) + TILE_2 - cub3d->cam.x;
	sprite_cam[Y] = (y << T) + TILE_2 - cub3d->cam.y;
	cub3d->sprite[cub3d->nbr_sprite_seen].dst = sprite_cam[X] * sprite_cam[X] +
											sprite_cam[Y] *sprite_cam[Y];
	cub3d->nbr_sprite_seen++;
	cub3d->map.arr[x][y] -= 8;
	return (0);
}

static float	ft_cast_ray_find_horizontal_intersection(t_cub3d *cub3d)
{
	float	a[XY];
	float	step[XY];

	if (cub3d->ray.theta == PI || cub3d->ray.theta == 0.f)
		return (3.402823e+38f);
	step[X] = cub3d->ray.isfacingup ? -TILE : TILE;
	a[X] = cub3d->ray.isfacingup ? (((int)cub3d->cam.x >> T) << T) :
								(((int)cub3d->cam.x >> T) << T) + TILE;
	a[Y] = cub3d->cam.y + (cub3d->cam.x - a[X]) / cub3d->ray.tan_theta;
	step[Y] = -step[X] / cub3d->ray.tan_theta;
	while (!ft_obstacles(cub3d, (int)(a[X] + (cub3d->ray.isfacingup ? -1: 0))
							>> T, (int)a[Y] >> T))
	{
		a[X] += step[X];
		a[Y] += step[Y];
	}
	cub3d->ray.save[0] = (int)a[Y] % TILE;
	return ((a[X] - cub3d->cam.x) * (a[X] - cub3d->cam.x) +
					(a[Y] - cub3d->cam.y) * (a[Y] - cub3d->cam.y));
}

static float	ft_cast_ray_find_vertical_intersection(t_cub3d *cub3d)
{
	float	a[XY];
	float	step[XY];

	if (cub3d->ray.theta == PI_90 || cub3d->ray.theta == PI_270)
		return (3.402823e+38f);
	step[Y] = cub3d->ray.isfacingleft ? -TILE : TILE;
	a[Y] = cub3d->ray.isfacingleft ? (((int)cub3d->cam.y >> T) << T) :
								(((int)cub3d->cam.y >> T) << T) + TILE;
	a[X] = cub3d->cam.x + (cub3d->cam.y - a[Y]) * cub3d->ray.tan_theta;
	step[X] = -step[Y] * cub3d->ray.tan_theta;
	while (!ft_obstacles(cub3d, (int)a[X] >> T, (int)(a[Y] +
				(cub3d->ray.isfacingleft ? -1: 0)) >> T))
	{
		a[Y] += step[Y];
		a[X] += step[X];
	}
	cub3d->ray.save[Y] = (int)a[X] % TILE;
	return ((a[X] - cub3d->cam.x) * (a[X] - cub3d->cam.x) +
					(a[Y] - cub3d->cam.y) * (a[Y] - cub3d->cam.y));
}

static void	ft_init_ray(t_cub3d *cub3d)
{
	if (cub3d->ray.theta < 0.f)
		cub3d->ray.theta += PI_360;
	else if (cub3d->ray.theta > PI_360)
		cub3d->ray.theta -= PI_360;
	cub3d->ray.cos_beta = cosf(cub3d->cam.alpha - cub3d->ray.theta);
	cub3d->ray.tan_theta = tanf(cub3d->ray.theta);
	cub3d->ray.isfacingup = (cub3d->ray.theta < PI) ? 1 : 0;
	cub3d->ray.isfacingleft = (cub3d->ray.theta > PI_90 && cub3d->ray.theta
		< PI_270) ? 1 : 0;
	cub3d->ray.hits_vertical = 0;
}

void	ft_render_cam_view_using_ray_casting_method(t_cub3d *cub3d)
{
	float	dist[XY];

	cub3d->iray = cub3d->map.r[Y] - 1;
	cub3d->ray.theta = cub3d->cam.alpha - FOV_2;
	cub3d->nbr_sprite_seen = 0;
	while (cub3d->iray > -1)
	{
		ft_init_ray(cub3d);
		dist[X] = ft_cast_ray_find_horizontal_intersection(cub3d);
		dist[Y] = ft_cast_ray_find_vertical_intersection(cub3d);
		cub3d->ray.hits_vertical = dist[X] > dist[Y];
		cub3d->ray.zbuffer[cub3d->iray] = dist[cub3d->ray.hits_vertical];
		ft_render_wall(cub3d, cub3d->cst /
			(sqrtf(dist[cub3d->ray.hits_vertical]) * cub3d->ray.cos_beta));
		cub3d->ray.theta += cub3d->phi;
		cub3d->iray--;
	}
}
