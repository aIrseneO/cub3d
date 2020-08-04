/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_rselection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 00:35:09 by atemfack          #+#    #+#             */
/*   Updated: 2020/04/24 21:18:11 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylibft.h"

void	ft_sort_rselection(int *tab, int size)
{
	int	i;
	int	j;
	int	imax;

	if (!(tab))
		return ;
	j = 0;
	while (j < size - 1)
	{
		i = j;
		imax = i;
		while (i++ < size - 1)
			if (tab[imax] < tab[i])
				imax = i;
		ft_swap(&tab[imax], &tab[j++]);
	}
}
