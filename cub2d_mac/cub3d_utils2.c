/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 20:11:52 by atemfack          #+#    #+#             */
/*   Updated: 2020/07/26 11:03:59 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_is_obstacle(t_cub3d *cub3d, int x, int y)
{
	if (x < 0 || x >= cub3d->map.rows || y < 0 || y >= cub3d->map.cols)
		return (1);
	return (cub3d->map.arr[x][y] != '.');
}

int	ft_move_forward_backward(t_cub3d *cub3d, int speed)
{
	float	x;
	float	y;

	x = cub3d->player.x + speed * sinf(cub3d->player.alpha);
	y = cub3d->player.y - speed * cosf(cub3d->player.alpha);
	if (!ft_is_obstacle(cub3d, (int)x >> T, (int)y >> T))
	{
		cub3d->player.x = x;
		cub3d->player.y = y;
		return (1);
	}
	return (0);
}

int	ft_slide_left_right(t_cub3d *cub3d, int speed)
{
	float	x;
	float	y;

	x = cub3d->player.x + speed * cosf(cub3d->player.alpha);
	y = cub3d->player.y + speed * sinf(cub3d->player.alpha);
	if (!ft_is_obstacle(cub3d, (int)x >> T, (int)y >> T))
	{
		cub3d->player.x = x;
		cub3d->player.y = y;
		return (1);
	}
	return (0);
}

int	ft_rotate_counterclockwise(t_cub3d *cub3d)
{
	cub3d->player.alpha = cub3d->player.alpha + ROTATION_SPEED;
	if (cub3d->player.alpha > PI_360)
		cub3d->player.alpha -= PI_360;
	return (1);
}

int	ft_rotate_clockwise(t_cub3d *cub3d)
{
	cub3d->player.alpha = cub3d->player.alpha - ROTATION_SPEED;
	if (cub3d->player.alpha < 0.f)
		cub3d->player.alpha += PI_360;
	return (1);
}

int ft_update_display(t_cub3d *cub3d)
{
	if (cub3d->move[7])
	{
		ft_set_hud_para(cub3d, HUD_FACTOR);
		ft_ray_casting(cub3d);
		ft_render_hud(cub3d);
		mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->win_ptr,
				cub3d->img.ptr, 0, 0);
		cub3d->move[6] = 0;
		cub3d->move[7] = 0;
		return (0);
	}
	ft_set_hud_para(cub3d, 1.f);
	ft_render_hud(cub3d);
	ft_ray_casting(cub3d);
	mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->win_ptr,
				cub3d->img.ptr, 0, 0);
	return (0);
}
