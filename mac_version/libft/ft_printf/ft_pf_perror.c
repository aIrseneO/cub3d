/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_perror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 12:16:12 by atemfack          #+#    #+#             */
/*   Updated: 2020/06/08 23:40:06 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pf_perror(int errorno)
{
	if (errorno == -1)
		ft_putstr_fd("\nError: Memory allocation faillure\n", 1);
	if (errorno == -2)
		ft_putstr_fd("\nError: Invalid Format\n", 1);
	if (errorno == -42)
		ft_putstr_fd("\nError: ...\n", 1);
	return (errorno);
}
