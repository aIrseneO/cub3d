/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 23:07:41 by atemfack          #+#    #+#             */
/*   Updated: 2020/04/21 12:41:57 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *nw)
{
	if (!lst || !nw)
		return ;
	if (!(*lst))
	{
		*lst = nw;
		return ;
	}
	ft_lstlast(*lst)->next = nw;
}
