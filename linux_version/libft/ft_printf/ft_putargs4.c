/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putargs4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 00:33:23 by atemfack          #+#    #+#             */
/*   Updated: 2020/05/19 16:03:37 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putargs4(va_list args, t_format *fpara, int ct)
{
	int	n;

	n = -1;
	if (fpara->specifier == 'c')
		n = ft_specifier_c(args, fpara);
	else if (fpara->specifier == 's')
		n = ft_specifier_s(args, fpara);
	else if (fpara->specifier == 'p')
		n = ft_specifier_p(args, fpara);
	else if (fpara->specifier == 'd' || fpara->specifier == 'i')
		n = ft_specifier_di(args, fpara);
	else if (fpara->specifier == 'u')
		n = ft_specifier_u(args, fpara);
	else if (fpara->specifier == 'x' || fpara->specifier == 'X')
		n = ft_specifier_xx(args, fpara);
	else if (fpara->specifier == '%')
		n = ft_specifier_mod(fpara);
	else if (fpara->specifier == 'n')
		n = ft_specifier_n(args, ct);
	else if (fpara->specifier == 'f')
		n = ft_specifier_f(args, fpara);
	free(fpara);
	return (n);
}
