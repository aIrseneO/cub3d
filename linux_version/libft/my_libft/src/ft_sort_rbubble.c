/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_rbubble.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 01:49:35 by atemfack          #+#    #+#             */
/*   Updated: 2020/04/24 21:17:02 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylibft.h"

void	ft_sort_rbubble(int *tab, int size)
{
	int	i;
	int	check;

	if (!(tab))
		return ;
	check = 1;
	while (check)
	{
		i = 0;
		check = 0;
		while (i < size - 1)
		{
			if (tab[i] < tab[i + 1])
			{
				ft_swap(&tab[i], &tab[i + 1]);
				check++;
			}
			i++;
		}
		size--;
	}
}
