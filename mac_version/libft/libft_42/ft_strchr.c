/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 22:11:12 by atemfack          #+#    #+#             */
/*   Updated: 2020/04/24 22:41:16 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *s, int c)
{
	if (!s)
		return (NULL);
	if ((char)c == '\0')
		return ((char *)(s + ft_strlen(s)));
	while (((char)c != *s) && (*s))
		s++;
	if (!(*s))
		return (NULL);
	return ((char *)s);
}
