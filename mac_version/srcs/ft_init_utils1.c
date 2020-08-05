/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 09:06:34 by atemfack          #+#    #+#             */
/*   Updated: 2020/08/04 20:01:27 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		ft_get_default_texture(t_cub3d *cub3d, int texture)
{
	int			size[XY];
	char		*default_txt;

	if (texture == NORTH)
		default_txt = NORTH_TEXTURE;
	else if (texture == SOUTH)
		default_txt = SOUTH_TEXTURE;
	else if (texture == WEST)
		default_txt = WEST_TEXTURE;
	else if (texture == EAST)
		default_txt = EAST_TEXTURE;
	else
		default_txt = SPRITE_TEXTURE;
	if (cub3d->txt[texture].ptr)
		mlx_destroy_image(cub3d->mlx_ptr, cub3d->txt[texture].ptr);
	cub3d->txt[texture].ptr = NULL;
	if ((cub3d->txt[texture].ptr = mlx_xpm_file_to_image(cub3d->mlx_ptr,
			default_txt, &size[X], &size[Y])) == NULL ||
			size[X] != TILE || size[Y] != TILE)
		return (FAILED);
	cub3d->txt[texture].data = (int *)mlx_get_data_addr(cub3d->txt
		[texture].ptr, &cub3d->txt[texture].bipp, &cub3d->txt
		[texture].size_line, &cub3d->txt[texture].endian);
	return (SUCCESS);
}

int				ft_init_texture(t_cub3d *cub3d)
{
	int			texture;
	int			size[XY];

	texture = 0;
	while (texture < TEXTURES)
	{
		if ((cub3d->txt[texture].ptr = mlx_xpm_file_to_image(cub3d->mlx_ptr,
				cub3d->map.txt[texture], &size[X], &size[Y])) != NULL)
		{
			if (size[X] == TILE || size[Y] == TILE)
				cub3d->txt[texture].data = (int *)mlx_get_data_addr(cub3d->txt
					[texture].ptr, &cub3d->txt[texture].bipp, &cub3d->txt
					[texture].size_line, &cub3d->txt[texture].endian);
			else if (ft_get_default_texture(cub3d, texture) == -1)
				return (FAILED);
		}
		else if (ft_get_default_texture(cub3d, texture) == -1)
			return (FAILED);
		cub3d->txt[texture].size_line = cub3d->txt[texture].size_line >> 2;
		texture++;
	}
	return (SUCCESS);
}
