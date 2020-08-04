/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 20:11:52 by atemfack          #+#    #+#             */
/*   Updated: 2020/08/02 16:28:04 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_is_obstacle(t_cub3d *cub3d, int x, int y)
{
	if (x < 0 || x >= cub3d->map.rows || y < 0 || y >= cub3d->map.cols)
		return (1);
	return (cub3d->map.arr[x][y] != '.');
}

int	ft_move_forward_backward(t_cub3d *cub3d, float speed)
{
	float	x;
	float	y;

	x = cub3d->cam.x + speed * sinf(cub3d->cam.alpha);
	y = cub3d->cam.y - speed * cosf(cub3d->cam.alpha);
	if (!ft_is_obstacle(cub3d, (int)x >> T, (int)y >> T))
	{
		cub3d->cam.x = x;
		cub3d->cam.y = y;
		return (1);
	}
	return (0);
}

int	ft_slide_left_right(t_cub3d *cub3d, float speed)
{
	float	x;
	float	y;

	x = cub3d->cam.x + speed * cosf(cub3d->cam.alpha);
	y = cub3d->cam.y + speed * sinf(cub3d->cam.alpha);
	if (!ft_is_obstacle(cub3d, (int)x >> T, (int)y >> T))
	{
		cub3d->cam.x = x;
		cub3d->cam.y = y;
		return (1);
	}
	return (0);
}

int	ft_rotate_counterclockwise(t_cub3d *cub3d)
{
	cub3d->cam.alpha = cub3d->cam.alpha + ROTATION_SPEED;
	if (cub3d->cam.alpha > PI_360)
		cub3d->cam.alpha -= PI_360;
	return (1);
}

int	ft_rotate_clockwise(t_cub3d *cub3d)
{
	cub3d->cam.alpha = cub3d->cam.alpha - ROTATION_SPEED;
	if (cub3d->cam.alpha < 0.f)
		cub3d->cam.alpha += PI_360;
	return (1);
}
