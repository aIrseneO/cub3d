/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_rinsertion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 23:37:49 by atemfack          #+#    #+#             */
/*   Updated: 2020/04/24 21:17:43 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylibft.h"

void	ft_sort_rinsertion(int *tab, int size)
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
			if (tab[k] > tab[j])
			{
				ft_swap(&tab[k], &tab[j]);
				k = j;
			}
			j--;
		}
	}
}
