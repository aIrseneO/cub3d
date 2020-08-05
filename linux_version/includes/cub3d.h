/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 20:53:23 by atemfack          #+#    #+#             */
/*   Updated: 2020/08/04 20:48:04 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdint.h>
# include "libft.h"
# include "config.h"
# include "mlx.h"
# include "bmp.h"

/*
** Structure for parsing
*/
typedef struct	s_map
{
	int			r[XY];
	char		*txt[TEXTURES];
	int			floor_color;
	int			ceilling_color;
	t_list		*content;
	int			rows;
	int			cols;
	char		**arr;
	int			p[XY];
	int			p_alpha;
	uint16_t	nbr_sprites;
}				t_map;

/*
** Structure for image mlx
*/
typedef struct	s_img
{
	int			bipp;
	int			size_line;
	void		*ptr;
	int			endian;
	int			*data;
}				t_img;

/*
** Structure for camera position
*/
typedef struct	s_cam
{
	float		x;
	float		y;
	float		alpha;
}				t_cam;

/*
** Structure for Ray casting
** beta:	ray's angle that is being cast relative to the viewing angle
** theta:	ray's angle
*/
typedef struct	s_ray
{
	int			a[XY];
	int			isfacingup;
	int			isfacingleft;
	int			hits_vertical;
	float		theta;
	float		tan_theta;
	float		cos_beta;
	float		*zbuffer;
}				t_ray;

typedef struct	s_sprite
{
	int			x;
	int			y;
	float		dst;
}				t_sprite;

typedef struct	s_hud
{
	int			tile[XY];
	int			r[XY];
	int			cam_size;
	float		conv_map_hud[XY];
	uint32_t	**arr;
}				t_hud;

/*
** Structure for cub3d
** dst_ppp:	distance cam to projected plan
** phi:		angle between rays
** cst:		to calculate wall's height
*/
typedef struct	s_cub3d
{
	int			iray;
	int			nbr_sprite_seen;
	int			move[6];
	float		dst_ppp;
	float		cst;
	float		phi;
	t_hud		hud;
	t_cam		cam;
	t_ray		ray;
	t_sprite	*sprite;
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_img		img;
	t_img		txt[TEXTURES];
}				t_cub3d;

/*
** Structure needed for some rendering
*/
typedef struct	s_render
{
	int			start[XY];
	int			end[XY];
	int			texture_start;
	int			line_shift;
	uint32_t	color;
}				t_render;

/*
** Main functions to move the camera
*/
int				ft_key_press(int key, t_cub3d *cub3d);
int				ft_key_release(int key, t_cub3d *cub3d);
int				ft_exit_loop(t_cub3d *cub3d);
int				ft_loop(t_cub3d *cub3d);
int				ft_move_forward_backward(t_cub3d *cub3d, float speed);
int				ft_slide_left_right(t_cub3d *cub3d, float speed);
int				ft_rotate_counterclockwise(t_cub3d *cub3d);
int				ft_rotate_clockwise(t_cub3d *cub3d);

/*
** Functionc to save the first image in bmp file
*/
int				ft_screenshot(t_cub3d *cub3d);

/*
** Functions to parse the map
*/
int				ft_parse_map(char *ag, t_map *map);
int				ft_parse_line_for_resolution(t_map *map, char *line);
int				ft_parse_line_for_path(char **path, char *line);
int				ft_parse_ceilling_floor_color(int *color, char *line);
int				ft_check_map_elements_and_set_map_cols_and_rows(t_map *map);
int				ft_check_map_surroundings(t_map *map, int rows, int cols);

/*
** Functions to initiate and allocate variables
*/
int				ft_init_t_cub3d(t_cub3d *cub3d);
int				ft_init_texture(t_cub3d *cub3d);
void			ft_load_hud(t_cub3d *cub3d);

/*
** Functions for rendering
*/
void			ft_render_3d(t_cub3d *cub3d);
void			ft_render_cam_view_using_ray_casting_method(t_cub3d *cub3d);
void			ft_render_sprites(t_cub3d *cub3d);
void			ft_render_wall(t_cub3d *cub3d, int dist);

int				ft_bmp(char *filename, t_bitmap *bitmap, void *pixel,
				int (*ft_load_pixels)(t_bitmap *bitmap, void *pixel, int fd));

/*
** Functions to print errors and free allocated memories
*/
int				ft_perror_free_map(int n, t_map *map);
int				ft_close(int fd);
int				ft_perror_free(int n, char *line, t_map *map);
int				ft_perror(int n);
int				ft_perror_free_cub3d(int n, t_cub3d *cub3d);

#endif
