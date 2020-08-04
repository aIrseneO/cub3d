/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 23:59:57 by atemfack          #+#    #+#             */
/*   Updated: 2020/07/31 00:57:02 by atemfack         ###   ########.fr       */
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
	else if (key == ESC)
		ft_exit_loop(cub3d);
	return (1);
}

int		ft_exit_loop(t_cub3d *cub3d)
{
	ft_perror_free_cub3d(-42, cub3d);
	exit(SUCCESS);
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
	if (!action)
		return (0);
	ft_render_3d(cub3d);
	return (1);
}
