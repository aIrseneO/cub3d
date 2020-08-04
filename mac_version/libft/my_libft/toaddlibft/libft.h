#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdlib.h>

typedef struct s_tree
{
	void			*data;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

void            ft_swap(void *a, void *b);

int		ft_max(int a, int b);
int		ft_btree_height(t_tree *node);

#endif
