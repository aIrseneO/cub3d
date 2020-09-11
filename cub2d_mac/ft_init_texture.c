/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 09:06:34 by atemfack          #+#    #+#             */
/*   Updated: 2020/07/14 21:45:50 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		ft_get_data_from_txt(t_cub3d *cub3d, t_img *txt, int texture)
{
	int		i;
	int		j;
	char	*addr;

	addr = mlx_get_data_addr(txt->ptr, &txt->bipp,
												&txt->size_line, &txt->endian);
	txt->bypp = txt->bipp >> 3;
	i = 0;
	while (i < TILE)
	{
		j = 0;
		while (j < TILE)
		{
			cub3d->txt[texture][i][j++] = *(int *)addr;
			addr += txt->bypp;
		}
		i++;
	}
	(void)cub3d; (void)texture;
	return (1);
}

int		ft_init_texture(t_cub3d *cub3d)
{
	int		texture;
	int		size[2];
	t_img	txt;

	texture = 0;
	while (texture < TEXTURES)
	{
		if ((txt.ptr = mlx_xpm_file_to_image(cub3d->mlx_ptr,
			cub3d->map.txt[texture], &size[X], &size[Y])) == NULL ||
			size[X] != TILE || size[Y] != TILE ||
			ft_get_data_from_txt(cub3d, &txt, texture) == -1)
		{
			while (texture > 0)
				mlx_destroy_image(cub3d->mlx_ptr, txt.ptr);
			mlx_destroy_window(cub3d->mlx_ptr, cub3d->win_ptr);
			return (ft_perror_free_map(-1, &cub3d->map));
		}
		texture++;
	}
	return (1);
}
