/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 01:22:44 by atemfack          #+#    #+#             */
/*   Updated: 2020/05/29 21:35:53 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_gnl_free(int n, char *ptr, char **as)
{
	if (ptr)
		free(ptr);
	if (!as)
		return (n);
	ptr = *as;
	free(ptr);
	*as = NULL;
	return (n);
}

static int	ft_gnl_extract_line(int fd, char *buffer, char **line,
						char *reste)
{
	int		n;
	char	*s;


	if ((*line = ft_gnl_strjoin(reste, NULL)) == NULL)
		return (-1);
	if (ft_gnl_strchr_endl(*line))
		return (1);
	buffer[0] = '\0'; 
	while (ft_gnl_strchr_endl(buffer) == NULL)
	{
		if ((n = read(fd, buffer, BUFFER_SIZE)) == -1)
			return (ft_gnl_free(-1, NULL, line));
		buffer[n] = '\0';
		if (!n)
			break ;
		if ((s = ft_gnl_strjoin(*line, buffer)) == NULL)
			return (ft_gnl_free(-1, NULL, line));
		free(*line);
		*line = s;
	}
	return (n);
}

static int	ft_gnl_clean_line(char **line, char **reste)
{
	int		n;
	char	*s;
	char	*tmp;

	if ((s = ft_gnl_strchr_endl(*line)) == NULL)
		return (1);
	if (*(s + 1))
	{
		if ((*reste = ft_gnl_strjoin(s + 1, NULL)) == NULL)
			return (-1);
	}
	n = s - *line;
	if ((s = (char *)malloc(sizeof(*s) * (n + 1))) == NULL)
		return (ft_gnl_free(-1, NULL, reste));
	s[n] = '\0';
	tmp = *line;
	*line = ft_gnl_strncpy(s, *line, n);
	free(tmp);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	int			n;
	char		*buffer;
	static char	*reste[FD_SIZE];

	if (fd < 0 || fd > FD_SIZE || BUFFER_SIZE < 1 || !(line))
		return (-1);
	if (BUFFER_SIZE <= 0)
		return (-1);
	if (!(reste[fd]))
	{
		if ((reste[fd] = (char *)malloc(sizeof(char))) == NULL)
			return (-1);
		*reste[fd] = '\0';
	}
	if (!(buffer = (char *)malloc(sizeof(*buffer) * (BUFFER_SIZE + 1))))
		return (ft_gnl_free(-1, NULL, &reste[fd]));
	buffer[BUFFER_SIZE] = '\0';
	if (ft_gnl_free((n = ft_gnl_extract_line(fd, buffer, line, reste[fd])),
			buffer, &reste[fd]) < 1)
		return (n);
	if ((n = ft_gnl_clean_line(line, &reste[fd])) == -1)
		return (ft_gnl_free(n, NULL, line));
	return (n);
}
