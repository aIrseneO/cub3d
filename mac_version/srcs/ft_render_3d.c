/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 22:27:21 by atemfack          #+#    #+#             */
/*   Updated: 2020/08/04 20:30:05 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ft_render_hud_cam(t_cub3d *cub3d)
{
	int			start[XY];
	int			cam[XY];

	if (!cub3d->hud.cam_size)
		return ;
	cam[X] = cub3d->cam.x * cub3d->hud.conv_map_hud[X];
	cam[Y] = cub3d->cam.y * cub3d->hud.conv_map_hud[Y];
	if (cub3d->hud.cam_size > 2)
	{
		start[X] = -1;
		while (start[X] < 2)
		{
			start[Y] = -1;
			while (start[Y] < 2)
				*(cub3d->img.data + cub3d->img.size_line * (start[X] + cam[X]) +
						start[Y]++ + cam[Y]) = CAM;
			start[X]++;
		}
	}
	else
		*(cub3d->img.data + cub3d->img.size_line * cam[X] + cam[Y]) = CAM;
}

static void		ft_render_hud(t_cub3d *cub3d)
{
	int			i;
	int			j;
	uint32_t	color;

	i = 0;
	while (i < cub3d->hud.r[X])
	{
		j = 0;
		while (j < cub3d->hud.r[Y])
		{
			if ((color = cub3d->hud.arr[i][j]))
				*(cub3d->img.data + cub3d->img.size_line * i + j) = color;
			j++;
		}
		i++;
	}
	ft_render_hud_cam(cub3d);
}

void			ft_render_3d(t_cub3d *cub3d)
{
	ft_render_cam_view_using_ray_casting_method(cub3d);
	if (cub3d->nbr_sprite_seen)
		ft_render_sprites(cub3d);
	ft_render_hud(cub3d);
	mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->win_ptr,
					cub3d->img.ptr, 0, 0);
}
