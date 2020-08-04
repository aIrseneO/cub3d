/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrevs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 13:55:49 by atemfack          #+#    #+#             */
/*   Updated: 2020/04/24 21:18:32 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylibft.h"

char	*ft_strrevs(char *str)
{
	char	c;
	size_t	i;
	size_t	j;

	if (!(str) || (j = ft_strlen(str)) < 2)
		return (str);
	i = 0;
	j--;
	while (i < j)
	{
		c = str[i];
		str[i++] = str[j];
		str[j--] = c;
	}
	return (str);
}
