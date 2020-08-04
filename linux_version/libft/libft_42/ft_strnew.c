/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 21:57:45 by atemfack          #+#    #+#             */
/*   Updated: 2020/02/27 22:04:52 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*tmp;
	char	*tmp2;

	if ((tmp = (char *)malloc(sizeof(*tmp) * (size + 1))) == NULL)
		return (NULL);
	tmp2 = tmp;
	while (size--)
		*tmp++ = 0;
	*tmp = '\0';
	return (tmp2);
}
