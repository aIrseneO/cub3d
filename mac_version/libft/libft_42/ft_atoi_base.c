/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 19:17:14 by atemfack          #+#    #+#             */
/*   Updated: 2020/06/10 23:56:34 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi_base(char const *str, int base)
{
	char		c;
	long long	nbr;
	short int	signe;
	short int	tmp[2];

	if (!str || base < 2)
		return (-42);
	while (ft_isspace(*str))
		str++;
	signe = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	nbr = 0;
	tmp[0] = base + 48;
	tmp[1] = base % 10 + 'a';
	while ((c = ft_tolower(*str++)) && 
			((c > 47 && c < tmp[0] && c < 58) ||
			(c >= 'a' && c < tmp[1] && base > 10)))
		nbr = nbr * base + ((c > 57) ? (c - 'a' + 10) : 
						(c - 48));
	return (nbr * signe);
}
