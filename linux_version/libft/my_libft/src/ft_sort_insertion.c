/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_insertion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 19:48:27 by atemfack          #+#    #+#             */
/*   Updated: 2020/04/24 21:17:28 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylibft.h"

void	ft_sort_insertion(int *tab, int size)
{
	int	i;
	int	j;
	int	k;

	if (!(tab))
		return ;
	i = 1;
	while (i < size)
	{
		j = i - 1;
		k = i++;
		while (j >= 0)
		{
			if (tab[k] < tab[j])
			{
				ft_swap(&tab[k], &tab[j]);
				k = j;
			}
			j--;
		}
	}
}
