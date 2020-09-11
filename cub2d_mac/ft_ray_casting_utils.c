/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_casting_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 22:35:28 by atemfack          #+#    #+#             */
/*   Updated: 2020/07/28 22:31:06 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_reset_sprites(t_cub3d *cub3d)
{
	int			i;

	i = 0;
	while (i < cub3d->nbr_sprite)
	{
		cub3d->map.arr[cub3d->sprite[i].x][cub3d->sprite[i].y] += 8;
		i++;
	}
}

static int		ft_wall_hit(t_ray ray)
{
	if (!ray.hits_vertical)
	{
		if (ray.isfacingup)
			return (NORTH);
		return (SOUTH);
	}
	if (ray.isfacingleft)
		return (WEST);
	return (EAST);
}

void			ft_render_wall(t_cub3d *cub3d, int height)
{
	int			tmp;
	int			texture;
	t_render	render;

	tmp = (cub3d->map.r[X] - height) >> 1;
	render.line_shift = 0;
	texture = ft_wall_hit(cub3d->ray);
	while (render.line_shift < tmp)
		*(cub3d->img.data + render.line_shift++ * cub3d->img.size_line
				+ cub3d->iray) = cub3d->map.ceilling_color;
	render.start[X] = tmp < 0 ? -tmp : 0;
	render.end[X] = tmp < 0 ? render.start[X] + cub3d->map.r[X] : height;
	while (render.start[X] < render.end[X])
		*(cub3d->img.data + render.line_shift++ * cub3d->img.size_line +
			cub3d->iray) = cub3d->txt[texture][(render.start[X]++ << T) / height]
			[cub3d->ray.save[cub3d->ray.hits_vertical]];
	while (render.line_shift < cub3d->map.r[X])
		*(cub3d->img.data + render.line_shift++ * cub3d->img.size_line +
			cub3d->iray) = cub3d->map.floor_color;
}

void    ft_render_rays(t_cub3d *cub3d, float dist, int color)
{
	int		i;
	float	ijsc[4];

	i = 6;
	ijsc[2] = sinf(cub3d->ray.theta);
	ijsc[3] = cosf(cub3d->ray.theta);
	while (i++)
	{
		ijsc[0] = cub3d->player.x - i * ijsc[2];
		ijsc[1] = cub3d->player.y + i * ijsc[3];
		if (sqrtf((ijsc[0] - cub3d->player.x) * (ijsc[0] - cub3d->player.x) +
			(ijsc[1] - cub3d->player.y) * (ijsc[1] - cub3d->player.y)) > dist)
		break ;
		*(cub3d->img.data + (int)(ijsc[0] * cub3d->conv_map_hud[Y])
			* cub3d->img.size_line +
			(int)(ijsc[1] * cub3d->conv_map_hud[X])) = color;
	}
}
