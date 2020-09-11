/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 23:25:29 by atemfack          #+#    #+#             */
/*   Updated: 2020/07/18 00:57:18 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int      ft_color_cel(t_cub3d *cub3d, int i, int j)
{
	if (cub3d->map.arr[i][j] == '.')
		return (0x333333);
	else if (cub3d->map.arr[i][j] == ' ')
		return (0x000000);
	else if (cub3d->map.arr[i][j] == '1')
		return (0xEEEEEE);
	else
		return (0x555599);
}

static void     ft_put_pixel(t_cub3d *cub3d, int ijkl[4], int color)
{
	int		i;
	int		j;

	i = 0;
	while (i++ < cub3d->hud_tile[0])
	{
		j = -1;
		while (j++ < cub3d->hud_tile[1])
			if (color)
				*(cub3d->img.data + (ijkl[0] + j + ijkl[2]) *
					cub3d->img.size_line + ijkl[1] + i + ijkl[3]) = color;
	}
}

static void	ft_render_player(t_cub3d *cub3d)
{
	int		ijk[3];
	int		mn[2];

	mn[0] = cub3d->player.x * cub3d->conv_map_hud[1];
	mn[1] = cub3d->player.y * cub3d->conv_map_hud[0];
	ijk[0] = -2;
	while (ijk[0] < 3)
	{
		ijk[1] = -2;
		while (ijk[1] < 3)
			*(cub3d->img.data + (mn[0] + ijk[1]++) * cub3d->img.size_line
					+ mn[1] + ijk[0]) = 0xFF22EE;
		ijk[0]++;
	}
	ijk[2] = 1;
	while (ijk[2]++ < 6)
	{
		ijk[0] = mn[0] - ijk[2] * sinf(cub3d->player.alpha);
		ijk[1] = mn[1] + ijk[2] * cosf(cub3d->player.alpha);
		*(cub3d->img.data + ijk[0] * cub3d->img.size_line + ijk[1]) = 0xFFAAFF;
	}
}

void    ft_render_hud(t_cub3d *cub3d)
{
	int		ijkl[4];

	ijkl[0] = 0;
	ijkl[2] = 0;
	while (ijkl[0] < cub3d->map.rows)
	{
		ijkl[1] = 0;
		ijkl[3] = 0;
		while (ijkl[1] < cub3d->map.cols)
		{
			ft_put_pixel(cub3d, ijkl, ft_color_cel(cub3d, ijkl[0], ijkl[1]));
			ijkl[3] += cub3d->hud_tile_1[0];
			ijkl[1]++;
		}
		ijkl[2] += cub3d->hud_tile_1[1];
		ijkl[0]++;
	}
	ft_render_player(cub3d);
}
