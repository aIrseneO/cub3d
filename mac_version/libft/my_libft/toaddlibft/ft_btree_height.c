/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_height.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 21:42:43 by atemfack          #+#    #+#             */
/*   Updated: 2020/03/02 21:59:08 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_btree_height(t_tree *node)
{
	int static	hleft;
	int static	hright;

	if (!(node))
		return (0);
	hleft = ft_btree_height(node->left);
	hright = ft_btree_height(node->right);
	return (max(hleft, hright) + 1);
}
