/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:48:28 by atemfack          #+#    #+#             */
/*   Updated: 2020/04/24 22:52:45 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			len;
	char			*map;

	if (!(s) || !(f))
		return (NULL);
	len = ft_strlen(s);
	if ((map = (char *)malloc(sizeof(*map) * (len + 1))) != NULL)
	{
		i = 0;
		while (len--)
		{
			map[i] = f(i, *s++);
			i++;
		}
		map[i] = '\0';
	}
	return (map);
}
