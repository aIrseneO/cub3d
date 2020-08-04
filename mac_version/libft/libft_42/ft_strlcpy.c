/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 19:54:05 by atemfack          #+#    #+#             */
/*   Updated: 2020/04/22 14:53:40 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, char const *src, size_t size)
{
	size_t	i;
	size_t	lens;

	if (!src)
		return (0);
	lens = ft_strlen(src);
	if (!(size--))
		return (lens);
	i = 0;
	while (i < size && *src)
		dst[i++] = *src++;
	dst[i] = '\0';
	return (lens);
}
