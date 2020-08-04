/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_mod.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 09:49:18 by atemfack          #+#    #+#             */
/*   Updated: 2020/05/19 21:57:33 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put(char *str, t_format *fpara)
{
	int	n;

	n = fpara->width - 1;
	if (fpara->flags[0] == '-')
	{
		ft_putstr_fd(str, 1);
		while (n--)
			write(1, " ", 1);
		return (fpara->width);
	}
	while (n--)
		write(1, " ", 1);
	ft_putstr_fd(str, 1);
	return (fpara->width);
}

int			ft_specifier_mod(t_format *fpara)
{
	char	*str;

	if (fpara->width > 1)
	{
		if (fpara->flags[0] == '-' || fpara->flags[4] != '0')
		{
			if ((str = ft_strdup("%")) == NULL)
				return (-1);
			return (ft_put(str, fpara));
		}
		if ((str = (char *)malloc(sizeof(*str) * (fpara->width + 1)))
				== NULL)
			return (-1);
		str[fpara->width] = '\0';
		str = ft_memset(str, '0', fpara->width - 1);
		str[fpara->width - 1] = '%';
		ft_putstr_fd(str, 1);
		free(str);
		return (fpara->width);
	}
	write(1, "%", 1);
	return (1);
}
