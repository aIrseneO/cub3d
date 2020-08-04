/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 21:00:33 by atemfack          #+#    #+#             */
/*   Updated: 2020/03/09 00:56:00 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void const *src, size_t len)
{
	void	*tmp;

	if (!(dst) && !(src))
		return (NULL);
	len++;
	tmp = dst;
	if (src < dst)
	{
		dst += len - 2;
		src += len - 2;
		while (len-- > 1)
			*(char *)dst-- = *(char const *)src--;
	}
	else
		while (len-- > 1)
			*(char *)dst++ = *(char const *)src++;
	return (tmp);
}
