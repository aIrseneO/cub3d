/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 23:59:57 by atemfack          #+#    #+#             */
/*   Updated: 2020/07/17 19:45:41 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_key_press(int key, t_cub3d *cub3d)
{
	if (key == FORWARD1 || key == FORWARD2)
		cub3d->move[0] = 1;
	else if (key == BACKWARD1 || key == BACKWARD2)
		cub3d->move[1] = 1;
	else if (key == SLIDE_LEFT)
		cub3d->move[2] = 1;
	else if (key == SLIDE_RIGHT)
		cub3d->move[3] = 1;
	else if (key == ROTATE_COUNTERCLOCKWISE)
		cub3d->move[4] = 1;
	else if (key == ROTATE_CLOCKWISE)
		cub3d->move[5] = 1;
	else if (key == DISPLAY_HUD)
		cub3d->move[6] = 1;
	return (1);
}

int		ft_key_release(int key, t_cub3d *cub3d)
{
	if (key == FORWARD1 || key == FORWARD2)
		cub3d->move[0] = 0;
	else if (key == BACKWARD1 || key == BACKWARD2)
		cub3d->move[1] = 0;
	else if (key == SLIDE_LEFT)
		cub3d->move[2] = 0;
	else if (key == SLIDE_RIGHT)
		cub3d->move[3] = 0;
	else if (key == ROTATE_COUNTERCLOCKWISE)
		cub3d->move[4] = 0;
	else if (key == ROTATE_CLOCKWISE)
		cub3d->move[5] = 0;
	else if (key == DISPLAY_3D)
		cub3d->move[7] = 1;
	else if (key == ESC)
	{
		mlx_destroy_image(cub3d->mlx_ptr, cub3d->img.ptr);
		mlx_destroy_window(cub3d->mlx_ptr, cub3d->win_ptr);
		ft_perror_free_map(-42, &cub3d->map);
		exit(1);
	}
	return (1);
}

int		ft_exit_loop(t_cub3d *cub3d)
{
	mlx_destroy_image(cub3d->mlx_ptr, cub3d->img.ptr);
	mlx_destroy_window(cub3d->mlx_ptr, cub3d->win_ptr);
	ft_perror_free_map(-42, &cub3d->map);
	exit(1);
}

int		ft_loop(t_cub3d *cub3d)
{
	int		action;

	action = 0;
	if (cub3d->move[0])
		action = ft_move_forward_backward(cub3d, -FORWARD_BACKWARD_SPEED);
	else if (cub3d->move[1])
		action = ft_move_forward_backward(cub3d, FORWARD_BACKWARD_SPEED);
	if (cub3d->move[2])
		action = ft_slide_left_right(cub3d, -SLIDING_SPEED);
	if (cub3d->move[3])
		action = ft_slide_left_right(cub3d, SLIDING_SPEED);
	if (cub3d->move[4])
		action = ft_rotate_counterclockwise(cub3d);
	else if (cub3d->move[5])
		action = ft_rotate_clockwise(cub3d);
	if (cub3d->move[6] && action)
		return (ft_update_display(cub3d));
	if (!(action--))
		return (0);
	ft_ray_casting(cub3d);
	ft_render_hud(cub3d);
	mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->win_ptr,
			cub3d->img.ptr, 0, 0);
	return (1);
}
