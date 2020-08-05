/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_3d_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 22:35:28 by atemfack          #+#    #+#             */
/*   Updated: 2020/08/04 20:47:18 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
			cub3d->iray) = *(cub3d->txt[texture].data + cub3d->txt[texture].
			size_line * ((render.start[X]++ << T) / height) +
			cub3d->ray.a[cub3d->ray.hits_vertical]);
	while (render.line_shift < cub3d->map.r[X])
		*(cub3d->img.data + render.line_shift++ * cub3d->img.size_line +
			cub3d->iray) = cub3d->map.floor_color;
}
