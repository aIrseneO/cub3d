/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 22:02:02 by atemfack          #+#    #+#             */
/*   Updated: 2020/04/24 22:44:38 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *haystack, char const *needle, size_t len)
{
	char	*c;
	size_t	n;
	size_t	m;

	if (!haystack || !needle)
		return (NULL);
	if (!(n = ft_strlen(needle)))
		return ((char *)haystack);
	m = 0;
	while (*haystack)
	{
		if ((c = ft_memchr(haystack, *needle, ft_strlen(haystack))) == NULL)
			return (NULL);
		if ((ft_memcmp(needle, c, n) == 0))
		{
			m += c - haystack + n;
			if (m <= len)
				return (c);
			else
				return (NULL);
		}
		m += c - haystack + 1;
		haystack = c + 1;
	}
	return (NULL);
}
