/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 10:44:10 by atemfack          #+#    #+#             */
/*   Updated: 2020/08/04 19:47:06 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

/*
** Game constant, can be changed
*/
# define FORWARD_BACKWARD_SPEED		0.5f
# define ROTATION_SPEED				0.005f
# define SLIDING_SPEED				0.5f
# define HUD_SCALE					0.2f

/*
** Colors
*/
# define CAM						0xFF22EE
# define CAM_ARROW					0xFFAAFF
# define HUD_WALLS					0xEEEEEE
# define HUD_SPRITES				0x555599
# define HUD_VOID					0x333333

/*
** Default textures links
*/
# define NORTH_TEXTURE				"textures/default_1.xpm"
# define SOUTH_TEXTURE				"textures/default_2.xpm"
# define WEST_TEXTURE				"textures/default_3.xpm"
# define EAST_TEXTURE				"textures/default_4.xpm"
# define SPRITE_TEXTURE				"textures/default_5.xpm"

/*
** Minimum and Maximum screen resolutions
*/
# define HEIGHT_MIN					128
# define HEIGHT_MAX					1080
# define WIDTH_MIN					128
# define WIDTH_MAX					1920

/*
** Keyboard
*/
# define FORWARD1					119
# define FORWARD2					65362
# define BACKWARD1					115
# define BACKWARD2					65364
# define SLIDE_LEFT					97
# define SLIDE_RIGHT				100
# define ROTATE_COUNTERCLOCKWISE	65361
# define ROTATE_CLOCKWISE			65363
# define DISPLAY_HUD				258
# define DISPLAY_3D					257
# define ESC						65307

/*
** Engine constants, shoudn't be changed as of now
** FOV is 60 and FOV_2 is 30, FOV divided by 2
*/
# define PI							3.141593f
# define PI_90						1.570796f
# define PI_270						4.712389f
# define PI_360						6.283185f
# define CONV_DEG_RAD				0.0174533f
# define FOV						1.047197551f
# define FOV_2						0.5235987756f
# define TILE						64
# define T							6
# define TILE_2						32

/*
** Cub3d
*/
# define P_EVENT					2
# define P_MASK						0
# define R_EVENT					3
# define R_MASK						1
# define EXT_EVENT					17
# define EXT_MASK					17

/*
** Others
*/
# define NORTH						0
# define SOUTH						1
# define WEST						2
# define EAST						3
# define SPRITE						4
# define TEXTURES					5
# define X							0
# define Y							1
# define XY							2
# define SUCCESS					1
# define FAILED						-1

#endif
