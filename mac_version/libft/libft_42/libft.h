/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atemfack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:29:47 by atemfack          #+#    #+#             */
/*   Updated: 2020/06/16 07:46:11 by atemfack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

//# include <string.h>
# include <stdlib.h>
# include <unistd.h>

/* Structure */

typedef struct          s_list
{
        void                    *content;
        struct s_list   *next;
}                                       t_list;

/* Memory manipulation */

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, void const *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, void const *src, size_t len);
void				*ft_memchr(void const *s, int c, size_t n);
int					ft_memcmp(void const *s1, void const *s2, size_t n);

/* Memory allocation and clean */

void				*ft_calloc(size_t nmemb, size_t size);
void                            *ft_memalloc(size_t size);//*****//Old cursus
void                            ft_memdel(void **ap);//*****//Old cursus
char                            *ft_strnew(size_t size);//*****//Old cursus
void                            ft_strdel(char **as);//*****//Old cursus
void                            ft_strclr(char *s);//*****//Old cursus


/* Char manipulation and identity */

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isspace(int c);
/* String manipulation */

char				*ft_isfx_ptrmove(char const *str,
					int (*f1)(int), int (*f2)(int));
size_t				ft_strlen(char const *s);
char                            *ft_strcpy(char *dest, char const *src);//Old cursus
size_t				ft_strlcpy(char *dst, char const *src, size_t size);
char                            *ft_strcat(char *s1, char const *s2);//Old cursus
size_t				ft_strlcat(char *dest, char const *src, size_t l);
char				*ft_strchr(char const *s, int c);
char				*ft_strrchr(char const *s, int c);
char                            *ft_strstr(char const *haystack, char const *needle);//Old cursus
char				*ft_strnstr(char const *haystack, char const *needle, size_t len);
int                                     ft_strcmp(char const *s1, char const *s2);//Old cursus
int					ft_strncmp(char const *s1, char const *s2, size_t n);
int					ft_atoi(char const *str);
int					ft_atoi_base(char const *str, int base);
char				*ft_utoa_base(unsigned int nb, int base);
char				*ft_strdup(char const *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);//*****
char				*ft_strjoin(char const *s1, char const *s2);//*****
char				*ft_strtrim(char const *s1, char const *set);//*****
char				**ft_split(char const *s, char c);//*****
char				*ft_itoa(int n);//*****
void                            ft_striter(char *s, void (*f)(char *));//*****//Old cursus
void                            ft_striteri(char *s, void (*f)(unsigned int, char *));//*****//Old cursus
char                            *ft_strmap(char const *s, char (*f)(char));//*****//Old cursus
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));//*****


/* Output */

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/* Link list */

t_list                          *ft_lstnew(void *content);
void                            ft_lstadd_front(t_list **lst, t_list *nw);
int                                     ft_lstsize(t_list *lst);
t_list                          *ft_lstlast(t_list *lst);
void                            ft_lstadd_back(t_list **lst, t_list *nw);
void                            ft_lstdelone(t_list *lst, void (*del)(void*));
t_list				*ft_lstdelhead(t_list **lst,
					void (*del)(void*));
void                            ft_lstclear(t_list **lst, void (*del)(void*));
void                            ft_lstiter(t_list *lst, void (*f)(void *));
t_list                          *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* Others */
int					ft_rgbcolor(unsigned short r, unsigned 
						short g, unsigned short b);

#endif
