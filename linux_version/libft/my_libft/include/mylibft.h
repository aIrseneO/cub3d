/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylibft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 20:37:48 by atemfack          #+#    #+#             */
/*   Updated: 2020/06/11 00:02:56 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLIBFT_H
# define MYLIBFT_H

# include "libft.h"

void				ft_swap(int *a, int *b);
int					ft_max(int a, int b);
char				*ft_strrevs(char *str);

void				ft_sort_selection(int *tab, int size);
void				ft_sort_rselection(int *tab, int size);
void				ft_sort_bubble(int *tab, int size);
void				ft_sort_rbubble(int *tab, int size);
void				ft_sort_insertion(int *tab, int size);
void				ft_sort_rinsertion(int *tab, int size);

#endif
