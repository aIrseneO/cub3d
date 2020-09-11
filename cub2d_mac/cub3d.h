/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 20:53:23 by atemfack          #+#    #+#             */
/*   Updated: 2020/09/10 20:19:19 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"
# include "config.h"
# include <stdint.h>

/* Structure for parsing */
typedef struct		
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
}				t_map;

/* Structure for image mlx */
typedef struct
{
	int			bipp;
	int			bypp;
	int			size_line;
	void		*ptr;
	int			endian;
	int			*data;
}				t_img;

/* Structure for player */
typedef struct	s_player
{
	float		x;
	float		y;
	float		alpha;
}				t_player;

/* Structure for Ray casting 
	beta:		ray's angle that is being cast relative to the viewing angle
	theta:		ray's angle
 */
typedef struct	s_ray
{
	int			save[2];

	int			isfacingup;
	int			isfacingleft;
	int			hits_vertical;
	float		theta;
	float		tan_theta;
	float		cos_beta;
	float		*zbuffer;
}				t_ray;

typedef struct s_render
{
	int			start[XY];
	int			end[XY];
	int			texture_start;
	int			line_shift;
	uint32_t	color;
}				t_render;

typedef struct s_sprite
{
	int			x;
	int			y;
	float		dst;
}				t_sprite;
/* Structure for cub3d
	dst_ppp:	distance player to projected plan
	phi:		angle between rays
	cst:
*/
typedef struct	s_cub3d
{
	int			iray;
	int			move[9];
	
	float		phi;
	float		dst_ppp;
	float		cst;

	int			hud_tile[XY];
	int			hud_tile_1[XY];
	float		conv_map_hud[XY];
	int			hud_size[XY];
		
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_ray		ray;
	t_player	player;
	t_img		img;
	t_sprite	*sprite;
	int			nbr_sprite;
	uint32_t	txt[TEXTURES][TILE][TILE];
}				t_cub3d;

/* Cub3d */
int				ft_init_t_cub3d(t_cub3d *cub3d);
int				ft_key_press(int key, t_cub3d *cub3d);
int				ft_key_release(int key, t_cub3d *cub3d);
int				ft_exit_loop(t_cub3d *cub3d);
int				ft_loop(t_cub3d *cub3d);
int				ft_move_forward_backward(t_cub3d *cub3d, int speed);
int				ft_slide_left_right(t_cub3d *cub3d, int speed);
int				ft_rotate_counterclockwise(t_cub3d *cub3d);
int				ft_rotate_clockwise(t_cub3d *cub3d);
int				ft_update_display(t_cub3d *cub3d);
void			ft_set_hud_para(t_cub3d *cub3d, float scale);
void			ft_render_hud(t_cub3d *cub3d);
int				ft_init_texture(t_cub3d *cub3d);
void			ft_render_sprites(t_cub3d *cub3d);
void			ft_reset_sprites(t_cub3d *cub3d);

/* Parse map */
int				ft_parse_map(char *ag, t_map *map);
int				ft_parse_line_for_resolution(t_map *map, char *line);
int				ft_parse_line_for_path(char **path, char *line);
int				ft_parse_line_for_ceilling_floor_color(int *color, char *line);
int				ft_check_map_elements_and_set_map_cols_and_rows(t_map *map);
int				ft_check_map_surroundings(char  **arr, int rows, int cols);

/* Ray casting */
void			ft_ray_casting(t_cub3d *cub3d);
void			ft_render_wall(t_cub3d *cub3d, int dist);
void			ft_render_rays(t_cub3d *cub3d, float dist, int color);

/* Print error */
int				ft_perror_free_map(int n, t_map *map);
int				ft_close(int fd);
int				ft_perror_free(int n, char *line, t_map *map);
int				ft_perror(int n);

#endif
