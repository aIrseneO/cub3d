/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 01:22:02 by atemfack          #+#    #+#             */
/*   Updated: 2020/05/19 21:56:25 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_specifier_c(va_list args, t_format *fpara)
{
	int		n;
	char	c;

	c = va_arg(args, int);
	if (fpara->width > 1)
	{
		n = fpara->width - 1;
		if (fpara->flags[0] == '-')
		{
			write(1, &c, 1);
			while (n--)
				write(1, " ", 1);
			return (fpara->width);
		}
		while (n--)
			write(1, " ", 1);
		write(1, &c, 1);
		return (fpara->width);
	}
	write(1, &c, 1);
	return (1);
}
