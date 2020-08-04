/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 18:11:00 by atemfack          #+#    #+#             */
/*   Updated: 2020/06/08 20:32:42 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

/* Default value for BUFFER_SIZE */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128 
# endif
size_t		ft_gnl_strlen(char const *s);
char		*ft_gnl_strchr_endl(char const *s);
char		*ft_gnl_strncpy(char *dst, char const *src, int n);
char		*ft_gnl_strjoin(char const *s1, char const *s2);
int			get_next_line(int fd, char **line);

#endif
