/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:30:02 by atemfack          #+#    #+#             */
/*   Updated: 2020/05/19 21:58:37 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list			args;
	int				ct;
	int				n;

	va_start(args, (char *)format);
	if (!format)
		return (-1);
	ct = 0;
	n = 0;
	while (*format)
	{
		if (*format != '%')
			ct += write(1, format++, 1);
		else
		{
			format++;
			if ((n = ft_args1((char **)(&format), args, ct)) < 0)
				break ;
			ct += n;
		}
	}
	va_end(args);
	return (n < 0 ? -1 : ct);
}
