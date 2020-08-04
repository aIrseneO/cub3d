/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 01:23:19 by atemfack          #+#    #+#             */
/*   Updated: 2020/05/29 14:08:11 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_gnl_strlen(char const *s)
{
	size_t	count;

	count = 0;
	if (s)
		while (*s++)
			count++;
	return (count);
}

char	*ft_gnl_strchr_endl(char const *s)
{
	if (!s)
		return (NULL);
	while ((*s != '\n') && *s)
		s++;
	if (!(*s))
		return (NULL);
	return ((char *)s);
}

char	*ft_gnl_strncpy(char *dst, char const *src, int n)
{
	int		i;

	i = 0;
	while (i < n)
		dst[i++] = *src++;
	return (dst);
}

char	*ft_gnl_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len;
	char	*s;

	len = ft_gnl_strlen(s1) + ft_gnl_strlen(s2);
	if ((s = (char *)malloc(sizeof(*s) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		s[i++] = *s1++;
	if (s2)
		while (*s2)
			s[i++] = *s2++;
	s[i] = '\0';
	return (s);
}
