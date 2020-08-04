/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 10:54:32 by atemfack          #+#    #+#             */
/*   Updated: 2020/04/24 22:36:22 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *s, int c, size_t n)
{
	if (!s)
		return (NULL);
	while (n && ((char)c != *((char *)s)))
	{
		s++;
		n--;
	}
	if (!n)
		return (NULL);
	return ((void *)s);
}
