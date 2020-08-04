/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 18:50:03 by atemfack          #+#    #+#             */
/*   Updated: 2020/07/31 23:53:39 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

/* TODO: Move this to libft */

# pragma pack(push, 1)

/* aliases for primitive data types */
typedef uint8_t					BYTE;
typedef uint32_t				DWORD;
typedef uint16_t				WORD;

/* default values */
# define _COMPRESSION			0
# define _XPELSPERMETER			0x130B //2835 , 72 DPI
# define _YPELSPERMETER			0x130B //2835 , 72 DPI
# define _COLORUSED				0
# define _COLORIMPORTANT 		0

/* information about the type, size, and layout of a file */
typedef struct					s_bitmapfileheader
{
    BYTE						type[2];
    DWORD						size;
    DWORD						reserved;
    DWORD						offbits;
}								t_bitmapfileheader;

/* information about the dimensions and color format */
typedef struct					s_bitmapinfoheader
{
    DWORD						size;
    DWORD						width;
    DWORD						height;
    WORD						planes;
    WORD						bitcount;
    DWORD						compression;
    DWORD						sizeimage;
    DWORD						xpelspermeter;
    DWORD						ypelspermeter;
    DWORD						clrused;
    DWORD						clrimportant;
}								t_bitmapinfoheader;

/* relative intensities of red, green, and blue */
typedef struct					s_rgbtriple
{
	BYTE						rgbtBlue;
	BYTE						rgbtGreen;
	BYTE						rgbtRed;
}								t_rgbtriple;

typedef struct					s_bitmap
{
	t_bitmapfileheader			bf;
	t_bitmapinfoheader			bi;
}								t_bitmap;

# pragma pack(pop)

#endif
