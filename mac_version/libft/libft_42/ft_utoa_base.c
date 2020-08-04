/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:52:34 by atemfack          #+#    #+#             */
/*   Updated: 2020/06/11 00:06:10 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_utoa_base(unsigned int nb, int base)
{
	int				len;
	char			*str;
	unsigned int	n;

	len = 1;
	n = nb;
	while (n >= (unsigned int)base)
	{
		len++;
		n /= base; 
	}
	if ((str = (char *)malloc(sizeof(*str) * (len + 1))) == NULL)
		return (NULL);
	str[len] = '\0';
	if (!nb)
		str[0] = '0';
	while (nb)
	{
		n = nb % base;
		str[--len] = (n < 10) ? n + 48 : n % 10 + 'a';
		nb /= base;
	}
	return (str);
}
