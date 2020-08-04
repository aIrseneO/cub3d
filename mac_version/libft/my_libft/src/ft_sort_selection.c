/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_selection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 23:56:19 by atemfack          #+#    #+#             */
/*   Updated: 2020/04/24 21:18:02 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylibft.h"

void	ft_sort_selection(int *tab, int size)
{
	int	i;
	int	j;
	int	imin;

	if (!(tab))
		return ;
	j = 0;
	while (j < size - 1)
	{
		i = j;
		imin = i;
		while (i++ < size - 1)
		{
			if (tab[imin] > tab[i])
				imin = i;
		}
		ft_swap(&tab[imin], &tab[j++]);
	}
}
