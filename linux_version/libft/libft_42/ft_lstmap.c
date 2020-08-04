/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 16:40:18 by atemfack          #+#    #+#             */
/*   Updated: 2020/04/22 14:38:35 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*lstmap(t_list *lst, void *(*f)(void *))
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (!lst->next)
		return (ft_lstnew(f(lst->content)));
	if ((tmp1 = lstmap(lst->next, f)) == NULL)
		return (NULL);
	if ((tmp2 = ft_lstnew(f(lst->content))) == NULL)
		return (NULL);
	ft_lstadd_front(&tmp1, tmp2);
	return (tmp1);
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
		void (*del)(void *))
{
	if (!lst || !f)
		return (NULL);
	(void)del;
	return (lstmap(lst, f));
}
