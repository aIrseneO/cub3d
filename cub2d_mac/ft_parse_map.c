/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 22:12:49 by atemfack          #+#    #+#             */
/*   Updated: 2020/07/15 07:56:19 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_initialize(int fd, t_map *map)
{
	int		n;
	char	*line;
	t_list	*tmp;

	map->r[X] = -1;
	map->r[Y] = -1;
	n = 0;
	while (n < 5)
		map->txt[n++] = NULL;
	map->floor_color = -1;
	map->ceilling_color = -1;
	map->content = NULL;
	map->arr = NULL;
	while ((n = get_next_line(fd, &line)) >= 0)
	{
		if (n == 0 && !(*line) && ft_perror_free(-42, line, NULL) == -1)
			break ;
		if ((tmp = ft_lstnew(line)) == NULL)
			return (ft_perror_free(-1, line, map));
		ft_lstadd_back(&map->content, tmp);
	}
	return ((n == -1) ? ft_perror_free_map(-1, map) : 1);
}

static int	ft_parse_map_for_elements(t_map *map, char *line)
{
	if (*line == 'R')
		return (ft_parse_line_for_resolution(map, ++line));
	if (*line == 'N' && *(line + 1) == 'O')
		return (ft_parse_line_for_path(&map->txt[NORTH], line + 2));
	if (*line == 'S' && *(line + 1) == 'O')
		return (ft_parse_line_for_path(&map->txt[SOUTH], line + 2));
	if (*line == 'W' && *(line + 1) == 'E')
		return (ft_parse_line_for_path(&map->txt[WEST], line + 2));
	if (*line == 'E' && *(line + 1) == 'A')
		return (ft_parse_line_for_path(&map->txt[EAST], line + 2));
	if (*line == 'S' && ft_isspace(*(line + 1)))
		return (ft_parse_line_for_path(&map->txt[SPRITE], ++line));
	if (*line == 'F' && ft_isspace(*(line + 1)))
		return (ft_parse_line_for_ceilling_floor_color
					(&map->floor_color, ++line));
	if (*line == 'C' && ft_isspace(*(line + 1)))
		return (ft_parse_line_for_ceilling_floor_color
					(&map->ceilling_color, ++line));
	return (ft_perror(-4));
}

static int		ft_parse_line_for_map_array(int *player_count, int i,
							char *line, t_map *map)
{
	int		j;

	j = 0;
	while (line[j])
	{
		if (line[j] == '0')
			map->arr[i][j] = '.';
		else if (line[j] == '1' || line[j] == ' ' || line[j] == '2')
			map->arr[i][j] = line[j];
		else if (ft_strchr("NSEW", line[j]))
		{
			map->arr[i][j] = '.';
			*player_count += 1;
			map->p[X] = i;
			map->p[Y] = j;
			map->p_alpha = line[j];
		}
		else
			return (ft_perror_free_map(-8, map));
		j++;
	}
	while (j < (*map).cols)
		map->arr[i][j++] = ' ';
	return (1);
}

static int		ft_parse_map_content_to_create_array(t_map *map)
{
	int			i;
	int			count;
	char		*line;
	t_list		*list;
	
	if (!(map->arr = (char **)malloc(sizeof(*map->arr) * map->rows)))
		return (ft_perror_free_map(-1, map));
	i = 0;
	while (i < map->rows)
		if ((map->arr[i++] = (char *)malloc(sizeof(**map->arr) *
						map->cols)) == NULL)
			break ;
	if (i != map->rows && (map->rows = i) >= 0)
		return (ft_perror_free_map(-1, map));
	list = map->content;
	i = 0;
	count = 0;
	while (list && (line = list->content))
	{
		if (ft_parse_line_for_map_array(&count, i++,  line, map) == -1)
			return (-1);
		list = list->next;
	}
	ft_lstclear(&map->content, free);
	return ((count == 1) ? 1 : ft_perror(-9));
}

int		ft_parse_map(char *ag1, t_map *map)
{
	int			fd;
	char		*s;

	if ((fd = open(ag1, O_RDONLY)) == -1)
		return (ft_perror(-1));
	if (ft_initialize(fd, map) == -1)
		return (ft_close(fd));
	while (map->content)
	{
		s = ft_isfx_ptrmove(map->content->content, ft_isspace, NULL);
		if (*s && !ft_strchr("RNSWEFC", *s))
			break ;
		if (*s && (ft_parse_map_for_elements(map, s)) == -1)
			return (ft_perror_free_map(-42, map));
		map->content = ft_lstdelhead(&(map->content), free);
	}
	if (!(s && *s == '1'))
		return (ft_perror_free_map(0, map));
	if (ft_check_map_elements_and_set_map_cols_and_rows(map) == -1)
		return (-1);
	if (ft_parse_map_content_to_create_array(map) == -1)
		return (-1);
	return ((ft_check_map_surroundings(map->arr, map->rows,
		(*map).cols) == -1) ? ft_perror_free_map(-10, map) : 1);
}
