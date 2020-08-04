/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 00:22:37 by atemfack          #+#    #+#             */
/*   Updated: 2020/06/08 23:41:09 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_extract_format(char **format)
{
	char	*specifiers;
	size_t	n;

	specifiers = "cspdiuxX%nf";
	n = 0;
	while ((*format)[n] && ft_strchr(specifiers, (*format)[n]) == NULL)
		n++;
	if (!((*format)[n++]))
	{
		ft_pf_perror(-2);
		return (NULL);
	}
	specifiers = *format;
	*format = *format + n;
	if ((specifiers = ft_substr(specifiers, 0, n)) == NULL)
	{
		ft_pf_perror(-1);
		return (NULL);
	}
	return (specifiers);
}

static void	ft_initialize(t_format *fpara)
{
	fpara->flags[0] = '1';
	fpara->flags[1] = '1';
	fpara->flags[2] = '1';
	fpara->flags[3] = 33;
	fpara->flags[4] = '1';
	fpara->width = 0;
	fpara->dot = 0;
	fpara->precision = 0;
	fpara->length[0] = '\0';
	fpara->length[1] = '\0';
	fpara->specifier = 0;
}

int			ft_args1(char **format, va_list args, int ct)
{
	char		*nformat;
	t_format	*fpara;

	if ((nformat = ft_extract_format(format)) == NULL)
		return (-1);
	if ((fpara = (t_format *)malloc(sizeof(*fpara))) == NULL)
	{
		free(nformat);
		return (ft_pf_perror(-1));
	}
	ft_initialize(fpara);
	if (ft_extract_fparameters2(nformat, args, fpara) < 0)
	{
		free(nformat);
		free(fpara);
		return (-1);
	}
	free(nformat);
	if (ft_check_fparameters3(fpara) < 0)
	{
		free(fpara);
		return (-1);
	}
	return (ft_putargs4(args, fpara, ct));
}
