/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 23:03:05 by atemfack          #+#    #+#             */
/*   Updated: 2020/07/15 07:51:49 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_parse_line_for_resolution(t_map *map, char *line)
{
	map->r[Y] = ft_atoi(line);
	line = ft_isfx_ptrmove(line, ft_isspace, ft_isdigit);
	map->r[X] = ft_atoi(line);
	line = ft_isfx_ptrmove(line, ft_isspace, ft_isdigit);
	line = ft_isfx_ptrmove(line, ft_isspace, NULL);
	if (*line || !map->r[0] || !map->r[1])
		return (ft_perror(-7));
	return (1);
}

int		ft_parse_line_for_path(char **path, char *line)
{
	char	*tmp;

	line = ft_isfx_ptrmove(line, ft_isspace, NULL);
	tmp = line;
	while (*line && !ft_isspace(*line))
		line++;
	if ((*path = ft_substr(tmp, 0, line - tmp)) == NULL)
		return (ft_perror(-1));
	if (*(line = ft_isfx_ptrmove(line, ft_isspace, NULL)))
	{
		free(*path);
		*path = NULL;
		return (ft_perror(-6));
	}
	return (1);
}

int		ft_parse_line_for_ceilling_floor_color(int *color, char *line)
{
	int	rgb[3];

	line = ft_isfx_ptrmove(line, ft_isspace, NULL);
	if ((rgb[0] = ft_atoi(line)) < 0 || rgb[0] > 255 || 
			(rgb[0] == 0 && *line != '0'))
		return (ft_perror(-5));
	line = ft_isfx_ptrmove(line, ft_isdigit, ft_isspace);
	if (*line++ != ',')
		return (ft_perror(-5));
	line = ft_isfx_ptrmove(line, ft_isspace, NULL);
	if ((rgb[1] = ft_atoi(line)) < 0 || rgb[1] > 255 || 
			(rgb[1] == 0 && *line != '0'))
		return (ft_perror(-5));
	line = ft_isfx_ptrmove(line, ft_isdigit, ft_isspace);
	if (*line++ != ',')
		return (ft_perror(-5));
	line = ft_isfx_ptrmove(line, ft_isspace, NULL);
	if ((rgb[2] = ft_atoi(line)) < 0 || rgb[2] > 255 || 
			(rgb[2] == 0 && *line != '0'))
		return (ft_perror(-5));
	line = ft_isfx_ptrmove(line, ft_isdigit, ft_isspace);
	if (*line)
		return (ft_perror(-5));
	*color = ft_rgbcolor(rgb[0], rgb[1], rgb[2]);
	return (1);
}

int             ft_check_map_elements_and_set_map_cols_and_rows(t_map *map)
{
	int		n;
	t_list	*list;

	if (map->r[0] == -1 || map->r[1] == -1 || map->txt[NORTH] == NULL ||
					map->txt[SOUTH] == NULL || map->txt[EAST] == NULL ||
					map->txt[WEST] == NULL || map->txt[SPRITE] == NULL ||
					map->floor_color == -1 || map->ceilling_color == -1)
		return (ft_perror_free_map(0, map));
	map->rows = 0;
	map->cols = 0;
	list = map->content;
	while (list)
	{
		n = ft_strlen(list->content);
		map->rows++;
		map->cols = (n > map->cols) ? n : map->cols;
		list = list->next;
	}
	return (1);
}

int		ft_check_map_surroundings(char 	**arr, int rows, int cols)
{
	int		i;
	int		j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if ((arr[i][j] == '.' || arr[i][j] == '2') &&
			(j == 0 || j == cols - 1 || i == 0 || i == rows - 1 ||
			 arr[i - 1][j - 1] == ' ' || arr[i - 1][j] == ' ' ||
			 arr[i - 1][j + 1] == ' ' || arr[i][j - 1] == ' ' ||
			 arr[i][j + 1] == ' ' || arr[i + 1][j - 1] == ' ' ||
			 arr[i + 1][j] == ' ' || arr[i + 1][j + 1] == ' '))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}
