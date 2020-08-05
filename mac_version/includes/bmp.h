/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 18:50:03 by atemfack          #+#    #+#             */
/*   Updated: 2020/08/04 18:33:05 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

/*
** TODO: Move this to libft
*/

# pragma pack(push, 1)

/*
** default values
*/
# define _COMPRESSION			0
# define _XPELSPERMETER			0x130B
# define _YPELSPERMETER			0x130B
# define _COLORUSED				0
# define _COLORIMPORTANT 		0

/*
** information about the type, size, and layout of a file
*/
typedef struct					s_bitmapfileheader
{
	uint8_t						type[2];
	uint32_t					size;
	uint32_t					reserved;
	uint32_t					offbits;
}								t_bitmapfileheader;

/*
** information about the dimensions and color format
*/
typedef struct					s_bitmapinfoheader
{
	uint32_t					size;
	uint32_t					width;
	uint32_t					height;
	uint16_t					planes;
	uint16_t					bitcount;
	uint32_t					compression;
	uint32_t					sizeimage;
	uint32_t					xpelspermeter;
	uint32_t					ypelspermeter;
	uint32_t					clrused;
	uint32_t					clrimportant;
}								t_bitmapinfoheader;

/*
** relative intensities of red, green, and blue
*/
typedef struct					s_rgbtriple
{
	uint8_t						rgbtblue;
	uint8_t						rgbtgreen;
	uint8_t						rgbtred;
}								t_rgbtriple;

typedef struct					s_bitmap
{
	t_bitmapfileheader			bf;
	t_bitmapinfoheader			bi;
}								t_bitmap;

# pragma pack(pop)

#endif
