/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 10:28:04 by atemfack          #+#    #+#             */
/*   Updated: 2020/06/08 23:43:49 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct
{
	char	flags[5];
	int		width;
	char	dot;
	int		precision;
	char	length[2];
	char	specifier;
}			t_format;

int			ft_printf(const char *format, ...);
int			ft_args1(char **format, va_list args, int ct);
int			ft_extract_fparameters2(char *nformat, va_list args,
		t_format *fpara);
int			ft_check_fparameters3(t_format *fpara);
int			ft_putargs4(va_list args, t_format *fpara, int ct);
int			ft_pf_perror(int errorno);
int			ft_specifier_c(va_list args, t_format *fpara);
int			ft_specifier_s(va_list args, t_format *fpara);
int			ft_specifier_p(va_list args, t_format *fpara);
int			ft_specifier_di(va_list args, t_format *fpara);
int			ft_specifier_u(va_list args, t_format *fpara);
int			ft_specifier_xx(va_list args, t_format *fpara);
int			ft_specifier_mod(t_format *fpara);
int			ft_specifier_n(va_list agrs, int ct);
int			ft_specifier_f(va_list args, t_format *fpara);

#endif
