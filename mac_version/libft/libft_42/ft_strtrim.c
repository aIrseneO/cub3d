/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 20:15:52 by atemfack          #+#    #+#             */
/*   Updated: 2020/04/22 15:14:33 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char		*new;
	size_t		len;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	if (!(len = ft_strlen(s1)))
	{
		if ((new = (char *)malloc(sizeof(*new))) == NULL)
			return (NULL);
		*new = '\0';
		return (new);
	}
	while (ft_strchr(set, s1[len - 1]))
		len--;
	if ((new = (char *)malloc(sizeof(*new) * (++len))) == NULL)
		return (NULL);
	i = 0;
	while (len-- > 1)
		new[i++] = *s1++;
	new[i] = '\0';
	return (new);
}
