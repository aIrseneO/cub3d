/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 13:14:30 by atemfack          #+#    #+#             */
/*   Updated: 2020/09/10 20:21:54 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//gwf -L minilibx_opengl -I minilibx_opengl main.c -lmlx -framework OpenGL -framework      AppKit -lz libft.a ft_parse_map.c ft_perror.c ft_parse_map_utils.c cub3d_utils1.c          cub3d_utils2.c cub3d_utils3.c ft_ray_casting.c ft_ray_casting_utils.c ft_init.c            ft_init_texture.c ft_render_sprites.c ft_screenshot.c bmp.c

#include "cub3d.h"

int		main(int ac, char **ag)
{
	t_cub3d		cub3d;

	if (ac != 2 )
		return (ft_perror(-2));
	if (ft_parse_map(ag[1], &cub3d.map) == -1)
		return (-1);
	if (ft_init_t_cub3d(&cub3d) == -1)
		return (-1);
	ft_ray_casting(&cub3d);
	ft_render_hud(&cub3d);
	mlx_put_image_to_window(cub3d.mlx_ptr, cub3d.win_ptr,
 													cub3d.img.ptr, 0, 0);
	mlx_hook(cub3d.win_ptr, P_EVENT, P_MASK, ft_key_press, &cub3d);
	mlx_hook(cub3d.win_ptr, R_EVENT, R_MASK, ft_key_release, &cub3d);
	mlx_hook(cub3d.win_ptr, EXT_EVENT, EXT_MASK, ft_exit_loop, &cub3d);
	mlx_loop_hook(cub3d.mlx_ptr, &ft_loop, &cub3d);
	mlx_loop(cub3d.mlx_ptr);
	return (1);
}
