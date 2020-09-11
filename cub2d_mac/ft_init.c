/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 22:35:04 by atemfack          #+#    #+#             */
/*   Updated: 2020/07/28 21:48:01 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_hud_para(t_cub3d *cub3d, float scale)
{
	cub3d->hud_tile[0] = scale * cub3d->map.r[Y] / cub3d->map.cols;
	cub3d->hud_tile[1] = scale * cub3d->map.r[X] / cub3d->map.rows;
	cub3d->hud_tile_1[0] = cub3d->hud_tile[0] - 1;
	cub3d->hud_tile_1[1] = cub3d->hud_tile[1] - 1;
	cub3d->conv_map_hud[0] = (float)cub3d->hud_tile[0] / TILE;
	cub3d->conv_map_hud[1] = (float)cub3d->hud_tile[1] / TILE;
}

static int		ft_init_img(t_cub3d *cub3d)
{
	if ((cub3d->img.ptr = mlx_new_image(cub3d->mlx_ptr,
									cub3d->map.r[Y], cub3d->map.r[X])) == NULL)
	{
		mlx_destroy_window(cub3d->mlx_ptr, cub3d->win_ptr);
		return (ft_perror_free_map(-1, &cub3d->map));
	}
	cub3d->img.data = (int *)mlx_get_data_addr(cub3d->img.ptr, &cub3d->img.bipp,
			&cub3d->img.size_line, &cub3d->img.endian);
	cub3d->img.size_line = cub3d->img.size_line >> 2;
	return (1);
}

int		ft_init_t_cub3d(t_cub3d *cub3d)
{
	cub3d->iray = 0;
	while (cub3d->iray < 9)
		cub3d->move[cub3d->iray++] = 0;
	cub3d->dst_ppp = (cub3d->map.r[Y] / 2.f) / tanf(FOV_2);
	cub3d->cst = cub3d->dst_ppp * TILE;
	cub3d->phi = FOV / cub3d->map.r[Y];
	ft_set_hud_para(cub3d, HUD_FACTOR);
	cub3d->player.x = (cub3d->map.p[X] << T) + (TILE >> 1);
	cub3d->player.y = (cub3d->map.p[Y] << T) + (TILE >> 1);
	if (cub3d->map.p_alpha == 'N')
		cub3d->player.alpha = 90.f * CONV_DEG_RAD;
	else if (cub3d->map.p_alpha == 'S')
		cub3d->player.alpha = 270.f * CONV_DEG_RAD;
	else if (cub3d->map.p_alpha == 'W')
		cub3d->player.alpha = 180.f * CONV_DEG_RAD;
	else if (cub3d->map.p_alpha == 'E')
		cub3d->player.alpha = 0.f;

	cub3d->ray.zbuffer = (float *)malloc(sizeof(*cub3d->ray.zbuffer) *
			cub3d->map.r[Y]);
	cub3d->sprite = (t_sprite *)malloc(sizeof(*cub3d->sprite) * 10);

	if (!(cub3d->mlx_ptr = mlx_init()) || !(cub3d->win_ptr =
	mlx_new_window(cub3d->mlx_ptr, cub3d->map.r[Y], cub3d->map.r[X], "cub3d")))
		return (ft_perror_free_map(-1, &cub3d->map));
	if (ft_init_img(cub3d) == -1)
		return (-1);
	if (ft_init_texture(cub3d) == -1 /*|| ft_init_sprite(cub3d) == -1*/)
	{
		mlx_destroy_image(cub3d->mlx_ptr, cub3d->img.ptr);
		mlx_destroy_window(cub3d->mlx_ptr, cub3d->win_ptr);
		return (-1);
	}
	return (1);
}
