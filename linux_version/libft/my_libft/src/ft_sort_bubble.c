/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_bubble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 01:21:36 by atemfack          #+#    #+#             */
/*   Updated: 2020/04/24 21:16:50 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylibft.h"

void	ft_sort_bubble(int *tab, int size)
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
			if (tab[i] > tab[i + 1])
			{
				ft_swap(&tab[i], &tab[i + 1]);
				check++;
			}
			i++;
		}
		size--;
	}
}
