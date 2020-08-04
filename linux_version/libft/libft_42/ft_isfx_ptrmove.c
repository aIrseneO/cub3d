/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfx_ptrmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 07:11:02 by atemfack          #+#    #+#             */
/*   Updated: 2020/06/16 07:47:11 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
   Return the pointer to the char in 'str' where 'f1' and 'f2' applied
   successively to the value at that location return false
*/
char	*ft_isfx_ptrmove(char const *str, int (*f1)(int), int (*f2)(int))
{
	while (f1(*str))
		str++;
	if (f2)
		while (f2(*str))
			str++;
	return ((char *)str);
}
