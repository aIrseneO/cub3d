/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 10:44:10 by atemfack          #+#    #+#             */
/*   Updated: 2020/07/26 18:43:11 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

/* Game */
# define FORWARD_BACKWARD_SPEED 3
# define ROTATION_SPEED 0.035f
# define SLIDING_SPEED 2
# define HUD_FACTOR 0.25f

/* Keyboard */
# define FORWARD1 13
# define FORWARD2 126
# define BACKWARD1 1
# define BACKWARD2 125
# define SLIDE_LEFT 0
# define SLIDE_RIGHT 2
# define ROTATE_COUNTERCLOCKWISE 123
# define ROTATE_CLOCKWISE 124
# define DISPLAY_HUD 258
# define DISPLAY_3D 257
# define ESC 53

/* Ray casting */
# define PI 3.141593f
# define PI_90 1.570796f
# define PI_270 4.712389f
# define PI_360 6.283185f
# define CONV_DEG_RAD 0.0174533f //(PI / 180)
# define FOV 1.047197551f //60
# define FOV_2 0.5235987756f //30
# define TILE 64
# define T    6
# define TILE_2  32
# define MY_LITTLE_ENDIAN 0
# define MY_BIG_ENDIAN 1
# define UDIV 1
# define VDIV 1
# define VMOVE 64



/* Cub3d */
# define P_EVENT 2
# define P_MASK (1L << 0)
# define R_EVENT 3
# define R_MASK (1L << 1)
# define EXT_EVENT 17
# define EXT_MASK (1L << 17)

# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3
# define SPRITE 4
# define TEXTURES 5
# define X 0
# define Y 1
# define XY 2

#endif
