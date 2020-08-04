# my_libft
<br>Structures used are:
```C
typedef struct		q_list
{
	void			*data;
	struct q_list	*next;
}					r_list;
```
```C
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
```
```C
typedef struct		s_tree
{
	void			*data;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;
```
| Output     | Function                        | Input  |
| --------- |:---------------------------| :-----|
| void | ft_swap | (int *a, int *b) |
| int | ft_max | (int a, int b) |
| char *| ft_strrev | (char *str) |

| Output     | Function                        | Input  |
| --------- |:---------------------------| :-----|
| void | ft_sort_selection | (int *tab, int size) |
| void | ft_sort_rselection | (int *tab, int size) |
| void | ft_sort_bubble | (int *tab, int size) |
| void | ft_sort_rbubble | (int *tab, int size) |
| void | ft_sort_insertion | (int *tab, int size) |
| void | ft_putarr| (int **arr, int row, int col, char *sep) |
