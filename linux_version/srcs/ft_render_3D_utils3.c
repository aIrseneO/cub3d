/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_3D_utils3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:31:12 by atemfack          #+#    #+#             */
/*   Updated: 2020/07/30 22:42:00 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Sort the sprite by their distance to the camera using bubble sort
TODO: Optimize with a faster sorting algorithm */
static void		ft_sort_sprites(t_cub3d *cub3d, int size)
{
	int			i;
	int			check;
	t_sprite	tmp;

	check = 1;
	size--;
	while (check)
	{
		i = 0;
		check = 0;
		while (i < size)
		{
			if (cub3d->sprite[i].dst < cub3d->sprite[i + 1].dst)
			{
				tmp = cub3d->sprite[i];
				cub3d->sprite[i] = cub3d->sprite[i + 1];
				cub3d->sprite[i + 1] = tmp;
				check++;
			}
			i++;
		}
		size--;
	}
}

static void		ft_render_col(t_cub3d *cub3d, t_render render, float dst,
																	int height)
{
	if (dst < cub3d->ray.zbuffer[render.start[Y]])
	{
		while (render.start[X] < render.end[X])
		{
			if ((render.color = *(cub3d->txt[SPRITE].data + cub3d->txt[SPRITE].
					size_line * ((render.start[X]++ << T) / height) +
					(render.texture_start << T) / height)))
				*(cub3d->img.data + render.line_shift * cub3d->img.size_line +
					render.start[Y]) = render.color;
			render.line_shift++;
		}
	}
}

static void		ft_render_sprite(t_cub3d *cub3d, float ysprite, int height,
																	float dst)
{
	t_render	render;
	int			tmp;

	render.texture_start = 0;
	if ((render.start[Y] = (int)ysprite - (height >> 1)) < 0)
	{
		render.texture_start = -render.start[Y];
		render.start[Y] = 0;
	}
	if ((render.end[Y] = (int)ysprite + (height >> 1)) > cub3d->map.r[1])
		render.end[Y] = cub3d->map.r[1];
	tmp = (cub3d->map.r[X] - height) >> 1;
	render.end[X] = tmp < 0 ? -tmp + cub3d->map.r[X] : height;
	while (render.start[Y] < render.end[Y])
	{
		render.start[X] = tmp < 0 ? -tmp : 0;
		render.line_shift = tmp < 0 ? 0 : tmp;
		ft_render_col(cub3d, render, dst, height);
		render.start[Y]++;
		render.texture_start++;
	}
}

void		ft_render_sprites(t_cub3d *cub3d)
{
	int		i;
	int		height;
	float	gamma;
	float	ysprite;

	ft_sort_sprites(cub3d, cub3d->nbr_sprite_seen);
	i = 0;
	while (i < cub3d->nbr_sprite_seen)
	{
		if ((gamma = atan2f(-((cub3d->sprite[i].x << T) + (TILE_2) -
				cub3d->cam.x), ((cub3d->sprite[i].y << T) + (TILE_2) -
				cub3d->cam.y))) < 0)
			gamma += PI_360;
		ysprite = cub3d->cam.alpha + FOV_2 - gamma;
		if (gamma > PI_270 && cub3d->cam.alpha < PI_90)
			ysprite = cub3d->cam.alpha + FOV_2 - gamma + PI_360;
		if (cub3d->cam.alpha > PI_270 && gamma < PI_90)
			ysprite = cub3d->cam.alpha + FOV_2 - gamma - PI_360;
		ysprite = ysprite * cub3d->map.r[Y] / FOV;
		height = cub3d->cst / (sqrtf(cub3d->sprite[i].dst));
		ft_render_sprite(cub3d, ysprite, height, cub3d->sprite[i].dst);
		cub3d->map.arr[cub3d->sprite[i].x][cub3d->sprite[i].y] += 8;
		i++;
	}
}
