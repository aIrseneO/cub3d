/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 01:43:49 by atemfack          #+#    #+#             */
/*   Updated: 2020/04/24 22:55:51 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strcount(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s == c)
		s++;
	if (!(*s))
		return (0);
	while (*s)
	{
		if (*s == c)
		{
			while (*s == c)
				s++;
			if (*s)
				count++;
		}
		else
			s++;
	}
	return (count + 1);
}

static int		ft_strlens(char const *s, char c, int *index)
{
	int	count;
	int	i;

	s = s + *index;
	count = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while ((s[i] != c) && (s[i]))
	{
		count++;
		i++;
	}
	*index += i;
	return (count + 1);
}

static void		fill(char const *s, char c, char **arr)
{
	int	i;

	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			i = 0;
			while (*s != c && *s)
				(*arr)[i++] = *s++;
			(*arr)[i] = '\0';
			arr++;
		}
	}
	*arr = 0;
}

char			**ft_split(char const *s, char c)
{
	char	**arr;
	int		nbrs;
	int		i;
	int		index;

	if (!(s))
		return (NULL);
	nbrs = ft_strcount(s, c);
	if ((arr = (char **)malloc(sizeof(*arr) * (nbrs + 1))) == NULL)
		return (NULL);
	if (!(nbrs))
	{
		*arr = 0;
		return (arr);
	}
	i = 0;
	index = 0;
	while (i < nbrs)
	{
		if ((arr[i++] = (char *)malloc(sizeof(**arr) *
						ft_strlens(s, c, &index))) == NULL)
			return (NULL);
	}
	fill(s, c, arr);
	return (arr);
}
