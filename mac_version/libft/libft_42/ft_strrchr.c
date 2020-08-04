/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 12:17:36 by atemfack          #+#    #+#             */
/*   Updated: 2020/04/24 22:41:51 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	size_t len;

	if (!s)
		return (NULL);
	if (!(*s))
	{
		if (c == 0)
			return ((char *)s);
		else
			return (NULL);
	}
	len = ft_strlen(s) - 1;
	if ((char)c == '\0')
		return ((char *)(s + len + 1));
	while (len && (s[len] != (char)c))
		len--;
	if (!len && (s[len] != (char)c))
		return (NULL);
	return ((char *)(s + len));
}
