/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:40:04 by atemfack          #+#    #+#             */
/*   Updated: 2020/02/27 21:46:44 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t dstsize)
{
	size_t lend;
	size_t len;

	lend = ft_strlen(dst);
	if (dstsize < lend)
		len = dstsize + ft_strlen(src);
	else
		len = lend + ft_strlen(src);
	if (dstsize > lend + 1)
		dstsize = dstsize - lend - 1;
	else
		dstsize = 0;
	while ((*src) && (dstsize--))
		dst[lend++] = *src++;
	dst[lend] = '\0';
	return (len);
}
