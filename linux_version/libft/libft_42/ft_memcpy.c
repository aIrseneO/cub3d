/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 20:15:36 by atemfack          #+#    #+#             */
/*   Updated: 2020/02/29 00:19:06 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	char *tmp;

	if (!(dst) && !(src))
		return (NULL);
	tmp = dst;
	while (n--)
		*tmp++ = *(char *)src++;
	return (dst);
}
