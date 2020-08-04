/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgbcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 22:38:12 by atemfack          #+#    #+#             */
/*   Updated: 2020/06/10 23:28:58 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_rgbcolor(unsigned short r, unsigned short g, 
		unsigned short b)
{
	int	color;

	color = r / 16;
	color = color * 16 + r % 16;
	color = color * 16 + g / 16;
	color = color * 16 + g % 16;
	color = color * 16 + b / 16;
	return (color * 16 + b % 16);
}
