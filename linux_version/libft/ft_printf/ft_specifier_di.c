/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_di.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 09:07:15 by atemfack          #+#    #+#             */
/*   Updated: 2020/06/08 23:45:04 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_add_precision(char *str, t_format *fpara, size_t n,
		short int signe)
{
	char	*s;
	int		precision;

	if (fpara->dot == '.' && fpara->precision >= 0)
		precision = fpara->precision;
	else if (fpara->flags[4] == '0' && fpara->flags[0] != '-')
		precision = (signe == -1 || fpara->flags[1] == '+' ||
		fpara->flags[2] == ' ') ? fpara->width - 1 : fpara->width;
	else
		return (str);
	if ((int)n < precision)
	{
		if ((s = (char *)malloc(sizeof(*s) * (precision + 1))) == NULL)
		{
			free(str);
			return (NULL);
		}
		n = (size_t)precision - n;
		s = ft_memset(s, '0', n);
		ft_strcpy(s + n, str);
		free(str);
		return (s);
	}
	return (str);
}

static char	*ft_begin(char *s, t_format *fpara, short int signe)
{
	size_t	n;
	char	*t;
	char	c;

	if (signe == -1)
		c = '-';
	else if (fpara->flags[1] == '+')
		c = '+';
	else if (fpara->flags[2] == ' ')
		c = ' ';
	else
		return (s);
	n = ft_strlen(s);
	if ((t = (char *)malloc(sizeof(*t) * (n + 2))) == NULL)
	{
		free(s);
		return (NULL);
	}
	t[0] = c;
	ft_memmove(t + 1, s, n + 1);
	free(s);
	return (t);
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

int			ft_specifier_di(va_list args, t_format *fpara)
{
	char		*str;
	short int	signe;
	int			n;

	n = va_arg(args, int);
	signe = 1;
	if (n < 0)
		signe = -1;
	if (!n && fpara->dot == '.' && !fpara->precision)
	{
		if ((str = ft_strdup("")) == NULL)
			return (ft_pf_perror(-1));
		str = ft_begin(str, fpara, signe);
		n = (fpara->flags[1] == '+' || fpara->flags[2] == ' ') ? 1 : 0;
		return (ft_put(str, n, fpara));
	}
	str = (n == -2147483648) ? ft_strdup("2147483648") : ft_itoa(n * signe);
	if (str == NULL)
		return (ft_pf_perror(-1));
	if ((str = ft_add_precision(str, fpara, ft_strlen(str), signe)) == NULL)
		return (-1);
	if ((str = ft_begin(str, fpara, signe)) == NULL)
		return (-1);
	return (ft_put(str, ft_strlen(str), fpara));
}
