/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 22:35:04 by atemfack          #+#    #+#             */
/*   Updated: 2020/08/04 20:00:12 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ft_set_variables_to_null(t_cub3d *cub3d)
{
	int			i;

	cub3d->ray.zbuffer = NULL;
	cub3d->sprite = NULL;
	cub3d->win_ptr = NULL;
	cub3d->hud.arr = NULL;
	i = 0;
	while (i < TEXTURES)
		cub3d->txt[i++].ptr = NULL;
	i = 0;
	while (i < 6)
		cub3d->move[i++] = 0;
}

static int		ft_init_hud_array(t_cub3d *cub3d)
{
	int			i;

	if ((cub3d->hud.arr = (uint32_t **)malloc(sizeof(*cub3d->hud.arr)
						* cub3d->hud.r[X])) == NULL)
		return (FAILED);
	i = 0;
	while (i < cub3d->hud.r[X])
		cub3d->hud.arr[i++] = NULL;
	i = 0;
	while (i < cub3d->hud.r[X])
		if ((cub3d->hud.arr[i++] = (uint32_t *)malloc(sizeof(**cub3d->hud.arr)
						* cub3d->hud.r[Y])) == NULL)
			return (FAILED);
	return (SUCCESS);
}

static int		ft_init_hud(t_cub3d *cub3d, float scale)
{
	cub3d->hud.tile[X] = (scale * cub3d->map.r[X]) / cub3d->map.rows;
	cub3d->hud.tile[Y] = (scale * cub3d->map.r[Y]) / cub3d->map.cols;
	cub3d->hud.r[X] = cub3d->hud.tile[X] * cub3d->map.rows;
	cub3d->hud.r[Y] = cub3d->hud.tile[Y] * cub3d->map.cols;
	cub3d->hud.conv_map_hud[X] = (float)cub3d->hud.tile[X] / TILE;
	cub3d->hud.conv_map_hud[Y] = (float)cub3d->hud.tile[Y] / TILE;
	cub3d->hud.cam_size = (cub3d->hud.tile[X] > cub3d->hud.tile[Y]) ?
				cub3d->hud.tile[Y] : cub3d->hud.tile[X];
	return (ft_init_hud_array(cub3d));
}

static int		ft_init_img_and_cam(t_cub3d *cub3d)
{
	if ((cub3d->img.ptr = mlx_new_image(cub3d->mlx_ptr,
									cub3d->map.r[Y], cub3d->map.r[X])) == NULL)
		return (FAILED);
	cub3d->img.data = (int *)mlx_get_data_addr(cub3d->img.ptr, &cub3d->img.bipp,
			&cub3d->img.size_line, &cub3d->img.endian);
	cub3d->img.size_line = cub3d->img.size_line >> 2;
	cub3d->cam.x = (cub3d->map.p[X] << T) + (TILE >> 1);
	cub3d->cam.y = (cub3d->map.p[Y] << T) + (TILE >> 1);
	if (cub3d->map.p_alpha == 'N')
		cub3d->cam.alpha = 90.f * CONV_DEG_RAD;
	else if (cub3d->map.p_alpha == 'S')
		cub3d->cam.alpha = 270.f * CONV_DEG_RAD;
	else if (cub3d->map.p_alpha == 'W')
		cub3d->cam.alpha = 180.f * CONV_DEG_RAD;
	else if (cub3d->map.p_alpha == 'E')
		cub3d->cam.alpha = 0.f;
	return (SUCCESS);
}

int				ft_init_t_cub3d(t_cub3d *cub3d)
{
	ft_set_variables_to_null(cub3d);
	cub3d->dst_ppp = (cub3d->map.r[Y] / 2.f) / tanf(FOV_2);
	cub3d->cst = cub3d->dst_ppp * TILE;
	cub3d->phi = FOV / cub3d->map.r[Y];
	if (ft_init_hud(cub3d, HUD_SCALE) == FAILED ||
			(cub3d->ray.zbuffer = (float *)malloc(sizeof(*cub3d->ray.zbuffer) *
				cub3d->map.r[Y])) == NULL ||
			(cub3d->sprite = (t_sprite *)malloc(sizeof(*cub3d->sprite) *
				cub3d->map.nbr_sprites)) == NULL ||
			(cub3d->mlx_ptr = mlx_init()) == NULL ||
			(cub3d->win_ptr = mlx_new_window(cub3d->mlx_ptr, cub3d->map.r[Y],
				cub3d->map.r[X], "cub3d")) == NULL ||
			ft_init_img_and_cam(cub3d) == FAILED ||
			ft_init_texture(cub3d) == FAILED)
		return (ft_perror_free_cub3d(-1, cub3d));
	ft_load_hud(cub3d);
	return (SUCCESS);
}
