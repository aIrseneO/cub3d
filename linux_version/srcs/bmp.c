/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 11:05:11 by atemfack          #+#    #+#             */
/*   Updated: 2020/08/04 20:30:38 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** TODO: Move this to libft
*/

/*
** This function takes 4 arguments: the name of the image to be created, the
** structure "bitmap" containing the informations on the image (see bmp.h), the
** pointer "pixels" to the first pixel color to be loaded on the image and the
** function "ft_load_pixels" that will be used to load pixels colors on the
** image. The function "ft_load_pixels" itself takes 4 arguments: the pointer to
** the structure "bitmap", the pointer "pixel" and the file descriptor number
** "fd" where to write pixels colors. In order for the image to be created,
** at least the width "bitmap.bi.width", the height "bitmap.bi.height" and the
** number of bites per pixel "bitmap.bi.bitcount" have to be fill up in the
** structure. It's to the user to write the pixels loading function.
*/

static int	ft_load(t_bitmap *bitmap, void *pixel, int fd,
				int (*ft_load_pixels)(t_bitmap *bitmap, void *pixel, int fd))
{
	if ((write(fd, bitmap, sizeof(t_bitmap)) == -1) ||
				ft_load_pixels(bitmap, pixel, fd) == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (1);
}

int			ft_bmp(char *filename, t_bitmap *bitmap, void *pixel,
				int (*ft_load_pixels)(t_bitmap *bitmap, void *pixel, int fd))
{
	int		fd;

	if ((fd = open(filename, O_RDWR | O_CREAT
					| O_TRUNC | O_APPEND, 0644)) == -1)
		return (-1);
	bitmap->bf.offbits = sizeof(t_bitmap);
	bitmap->bi.sizeimage = bitmap->bi.width * bitmap->bi.height *
								(bitmap->bi.bitcount >> 3);
	bitmap->bf.size = bitmap->bf.offbits + bitmap->bi.sizeimage;
	bitmap->bf.type[0] = 'B';
	bitmap->bf.type[1] = 'M';
	bitmap->bf.reserved = 0;
	bitmap->bi.size = sizeof(t_bitmapinfoheader);
	bitmap->bi.planes = 1;
	bitmap->bi.compression = _COMPRESSION;
	bitmap->bi.xpelspermeter = _XPELSPERMETER;
	bitmap->bi.ypelspermeter = _YPELSPERMETER;
	bitmap->bi.clrused = _COLORUSED;
	bitmap->bi.clrimportant = _COLORIMPORTANT;
	return (ft_load(bitmap, pixel, fd, ft_load_pixels));
}
