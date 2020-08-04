/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:09:36 by atemfack          #+#    #+#             */
/*   Updated: 2020/03/08 23:14:42 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	size_t	i;
	char	*map;

	if (!(s))
		return (NULL);
	len = ft_strlen(s);
	if ((map = (char *)malloc(sizeof(*map) * (len + 1))) != NULL)
	{
		i = 0;
		while (i < len)
			map[i++] = f(*s++);
		map[i] = '\0';
	}
	return (map);
}
