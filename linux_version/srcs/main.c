/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 13:14:30 by atemfack          #+#    #+#             */
/*   Updated: 2020/08/04 20:43:34 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int ac, char **ag)
{
	t_cub3d		cub3d;

	if (ac != 2 && (ac != 3 || (ac == 3 && ft_strcmp(ag[2], "--save"))))
		return (ft_perror(-2));
	if (ft_parse_map(ag[1], &cub3d.map) == FAILED)
		return (FAILED);
	if (ft_init_t_cub3d(&cub3d) == FAILED)
		return (FAILED);
	ft_render_3d(&cub3d);
	if (ac == 3)
		return (ft_screenshot(&cub3d) == FAILED);
	mlx_hook(cub3d.win_ptr, P_EVENT, P_MASK, ft_key_press, &cub3d);
	mlx_hook(cub3d.win_ptr, R_EVENT, R_MASK, ft_key_release, &cub3d);
	mlx_hook(cub3d.win_ptr, EXT_EVENT, EXT_MASK, ft_exit_loop, &cub3d);
	mlx_loop_hook(cub3d.mlx_ptr, &ft_loop, &cub3d);
	mlx_loop(cub3d.mlx_ptr);
	return (SUCCESS);
}
