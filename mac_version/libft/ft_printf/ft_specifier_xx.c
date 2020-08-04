/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_xx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 19:45:23 by atemfack          #+#    #+#             */
/*   Updated: 2020/06/08 23:46:46 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_utoa_hex_pf(unsigned long long int nbr, t_format *fpara)
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
	if ((str = (char *)malloc(sizeof(*str) * (i + 1))) == NULL)
		return (NULL);
	str[i] = '\0';
	if (!nbr)
		str[0] = '0';
	while (nbr)
	{
		j = nbr % 16;
		str[--i] = j < 10 ? j + 48 : j % 10 + fpara->specifier - 23;
		nbr /= 16;
	}
	return (str);
}

static char	*ft_add_precision(char *str, t_format *fpara, size_t n)
{
	char	*s;
	int		i;
	int		precision;

	i = (fpara->flags[3] == '#' && *str != '0') ? 2 : 0;
	if (fpara->dot == '.' && fpara->precision >= 0)
		precision = fpara->precision;
	else if (fpara->flags[4] == '0' && fpara->flags[0] != '-')
		precision = fpara->width - i;
	else
		return (str);
	if ((int)n < precision)
	{
		if ((s = (char *)malloc(sizeof(*s) * (precision + 1))) == NULL)
			return (NULL);
		n = (size_t)precision - n;
		s = ft_memset(s, '0', n);
		i = 0;
		while (str[i])
			s[n++] = str[i++];
		s[n] = '\0';
		free(str);
		return (s);
	}
	return (str);
}

static char	*ft_add_0xx(char *str, int len, char specifier)
{
	char	*s;

	if ((s = (char *)malloc(sizeof(*s) * (len + 3))) == NULL)
	{
		free(str);
		return (NULL);
	}
	s[0] = '0';
	s[1] = specifier;
	ft_strcpy(s + 2, str);
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

int			ft_specifier_xx(va_list args, t_format *fpara)
{
	char			*str;
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	if ((str = ft_utoa_hex_pf(nbr, fpara)) == NULL)
		return (ft_pf_perror(-1));
	if (*str == '0' && fpara->dot == '.' && !fpara->precision)
		*str = '\0';
	else if ((str = ft_add_precision(str, fpara, ft_strlen(str))) == NULL)
	{
		free(str);
		return (ft_pf_perror(-1));
	}
	if (fpara->flags[3] == '#' && *str && nbr
	&& (str = ft_add_0xx(str, ft_strlen(str), fpara->specifier)) == NULL)
		return (ft_pf_perror(-1));
	return (ft_put(str, (int)ft_strlen(str), fpara));
}
