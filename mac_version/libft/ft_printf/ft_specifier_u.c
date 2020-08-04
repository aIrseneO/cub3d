/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:56:20 by atemfack          #+#    #+#             */
/*   Updated: 2020/06/08 23:46:21 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_utoa(unsigned int nb)
{
	int				len;
	char			*str;
	unsigned int	n;

	len = 1;
	n = nb;
	while (n >= 10)
	{
		len++;
		n /= 10;
	}
	if ((str = (char *)malloc(sizeof(*str) * (len + 1))) == NULL)
		return (NULL);
	str[len] = '\0';
	while (nb >= 10)
	{
		str[--len] = nb % 10 + 48;
		nb /= 10;
	}
	str[--len] = nb % 10 + 48;
	return (str);
}

static char	*ft_add_precision(char *str, t_format *fpara, size_t n)
{
	char	*s;
	int		i;
	int		precision;

	if (fpara->dot == '.' && fpara->precision >= 0)
		precision = fpara->precision;
	else if (fpara->flags[4] == '0' && fpara->flags[0] != '-')
		precision = fpara->width;
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

int			ft_specifier_u(va_list args, t_format *fpara)
{
	char			*str;
	unsigned int	n;

	n = va_arg(args, unsigned int);
	if (!n && fpara->dot == '.' && !fpara->precision)
	{
		if ((str = ft_strdup("")) == NULL)
			return (ft_pf_perror(-1));
		return (ft_put(str, 0, fpara));
	}
	if ((str = ft_utoa((unsigned int)n)) == NULL)
		return (ft_pf_perror(-1));
	if ((str = ft_add_precision(str, fpara, ft_strlen(str))) == NULL)
	{
		free(str);
		return (ft_pf_perror(-1));
	}
	return (ft_put(str, ft_strlen(str), fpara));
}
