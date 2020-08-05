/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenshot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 17:07:25 by atemfack          #+#    #+#             */
/*   Updated: 2020/08/04 20:42:58 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_load_pixels(t_bitmap *bitmap, void *pixel, int fd)
{
	int			xstart;
	uint16_t	len;
	uint32_t	*data;

	len = sizeof(*data) * bitmap->bi.width;
	data = (uint32_t *)pixel;
	xstart = bitmap->bi.height - 1;
	while (xstart >= 0)
		if (write(fd, data + xstart-- * bitmap->bi.width, len) == -1)
			return (-1);
	return (1);
}

int				ft_screenshot(t_cub3d *cub3d)
{
	t_bitmap	bitmap;

	bitmap.bi.width = cub3d->map.r[Y];
	bitmap.bi.height = cub3d->map.r[X];
	bitmap.bi.bitcount = cub3d->img.bipp;
	if (ft_bmp("screenshot.bmp", &bitmap, cub3d->img.data,
				&ft_load_pixels) == -1)
	{
		ft_putstr_fd("Error\nUnable to save the first rendered image", 1);
		perror(" ");
		return (ft_perror_free_cub3d(-42, cub3d));
	}
	return (SUCCESS);
}
