/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 13:57:17 by atemfack          #+#    #+#             */
/*   Updated: 2020/06/08 23:45:30 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_utoa_hex(unsigned long long int nbr, t_format *fpara)
{
	char					*str;
	unsigned int			i;
	unsigned long long int	j;

	i = 1;
	j = nbr;
	while (j >= 16)
	{
		j /= 16;
		i++;
	}
	i += (!nbr && !fpara->precision && fpara->dot == '.') ? 1 : 2;
	if ((str = (char *)malloc(sizeof(*str) * (i + 1))) == NULL)
		return (NULL);
	str[0] = '0';
	str[1] = 'x';
	str[i] = '\0';
	while (i > 2)
	{
		j = nbr % 16;
		str[--i] = j < 10 ? j + 48 : j % 10 + 'a';
		nbr /= 16;
	}
	return (str);
}

static char	*ft_add_precision_undef_beh(char *str, t_format *fpara, int n)
{
	char	*s;
	int		nbr;

	if (!(fpara->dot == '.' && fpara->precision > n - 2))
		return (str);
	nbr = fpara->precision + 2;
	if ((s = (char *)malloc(sizeof(*s) * (nbr + 1))) == NULL)
	{
		free(str);
		return (NULL);
	}
	s[0] = '0';
	s[1] = 'x';
	ft_memset(s + 2, '0', fpara->precision - (n - 2));
	ft_strcpy(s + fpara->precision - n + 4, str + 2);
	free(str);
	return (s);
}

static int	ft_put(char *str, int n, t_format *fpara)
{
	if (fpara->width > n)
	{
		n = fpara->width - n;
		if (fpara->flags[0] == '-')
		{
			ft_putstr_fd(str, 1);
			while (n--)
				write(1, " ", 1);
			free(str);
			return (fpara->width);
		}
		while (n--)
			write(1, " ", 1);
		ft_putstr_fd(str, 1);
		free(str);
		return (fpara->width);
	}
	ft_putstr_fd(str, 1);
	free(str);
	return (n);
}

int			ft_specifier_p(va_list args, t_format *fpara)
{
	char	*str;

	if ((str = ft_utoa_hex(va_arg(args, unsigned long long int),
						fpara)) == NULL)
		return (ft_pf_perror(-1));
	str = ft_add_precision_undef_beh(str, fpara, ft_strlen(str));
	if (str == NULL)
		return (ft_pf_perror(-1));
	return (ft_put(str, (int)ft_strlen(str), fpara));
}
