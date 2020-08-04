# libft
42 - The library of functions that I'll use for my C projects
<br>Structures used are:
```C
typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
```
| Output     | Function                        | Input  |
| --------- |:---------------------------| :-----|
| void *| ft_memset | (void *b, int c, size_t len);|
| void  | ft_bzero | (void *s, size_t n);|
| void *| ft_memcpy | (void *dst, void const *src, size_t n);|
| void *| ft_memccpy | (void *dst, const void *src, int c, size_t n);|
| void *| ft_memmove | (void *dst, void const *src, size_t len);|
| void *| ft_memchr | (void const *s, int c, size_t n);|
| int | ft_memcmp | (void const *s1, void const *s2, size_t n);|
| size_t | ft_strlen | (char const *s);|
| char *| ft_strdup | (char const *s1);|
| char *| ft_strcpy | (char *dest, char const *src);|
| char *| ft_strncpy | (char *dest, char const *src, size_t n);|
| char *| ft_strcat | (char *s1, char const *s2);|
| char *| ft_strncat | (char *s1, const char *s2, size_t n);|
| size_t | ft_strlcat | (char *dest, char const *src, size_t l);|
| char *| ft_strchr | (char const *s, int c);|
| char *| ft_strrchr | (char const *s, int c);|
| char *| ft_strstr | (char const *haystack, char const *needle);|
| char *| ft_strnstr | (char const *haystack, char const *needle, size_t len);|
| int | ft_strcmp | (char const *s1, char const *s2);|
| int | ft_strncmp | (char const *s1, char const *s2, size_t n);|
| int | ft_atoi | (char const *str);|
| int | ft_isalpha | (int c);|
| int | ft_isdigit | (int c);|
| int | ft_isalnum | (int c);|
| int | ft_isascii | (int c);|
| int | ft_isprint | (int c);|
| int | ft_toupper | (int c);|
| int | ft_tolower | (int c);|

| Output     | Function                        | Input  |
| --------- |:---------------------------| :-----|
| void *| ft_memalloc | (size_t size);|
| void  | ft_memdel | (void **ap);|
| char *| ft_strnew | (size_t size);|
| void | ft_strdel | (char **as);|
| void | ft_strclr | (char *s);|
| void | ft_striter | (char *s, void (*f)(char *));|
| void | ft_striteri | (char *s, void (*f)(unsigned int, char *));|
| char *| ft_strmap | (char const *s, char (*f)(char));|
| char *| ft_strmapi | (char const *s, char (*f)(unsigned int, char));|
| int | ft_strequ | (char const *s1, char const *s2);|
| int | ft_strnequ | (char const *s1, char const *s2, size_t n);|
| char *| ft_strsub | (char const *s, unsigned int start, size_t len);|
| char *| ft_strjoin | (char const *s1, char const *s2);|
| char *| ft_strtrim | (char const *s);|
| char **| ft_strsplit | (char const *s, char c);|
| char *| ft_itoa | (int n);|
| void | ft_putchar | (char c)|
| void | ft_putstr | (char const *s);|
| void | ft_putendl | (char const *s);|
| void | ft_putnbr | (int n);|
| void | ft_putchar_fd | (char c, int fd);|
| void | ft_putstr_fd | (char const *s, int fd);|
| void | ft_putendl_fd | (char const *s, int fd);|
| void | ft_putnbr_fd | (int n, int fd);|

| Output     | Function                        | Input  |
| --------- |:---------------------------| :-----|
| t_list *| ft_lstnew | (void const *content, size_t content_size);|
| void | ft_lstdelone | (t_list **alst, void (*del)(void *, size_t));|
| void | ft_lstdel | (t_list **alst, void (*del)(void *, size_t));|
| void | ft_lstadd | (t_list **alst, t_list *nw);|
| void | ft_lstiter | (t_list *lst, void (*f)(t_list *elem));|
| t_list *| ft_lstmap | (t_list *lst, t_list *(*f)(t_list *elem)) |
