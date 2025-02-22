/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:52:14 by agaudry           #+#    #+#             */
/*   Updated: 2017/06/23 17:23:01 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <ft_printf.h>
# define BUFF_SIZE 80

typedef	struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

int				ft_abs(int nb);
int				ft_atoi(char const *str);
void			ft_bzero(void *s, size_t n);
void			ft_dblarray_del(void **tab);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_is_whitespace(char c);
char			*ft_itoa(int n);
char			*ft_ltoa_u_conv(long long n);
char			*ft_itoa_base(int value, int base);
char			*ft_ltoa_base_u_conv(long long value, long long base);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstback(t_list **alst, t_list *new);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);
t_list			*ft_lst_at(t_list *begin_list, unsigned int nbr);
size_t			ft_lst_size(t_list *begin_list);
char			*ft_ltoa_u_conv(long long n);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *dst, void const *src, int c, size_t n);
void			*ft_memchr(void const *s, int c, size_t n);
int				ft_memcmp(void const *s1, void const *s2, size_t n);
void			*ft_memcpy(void *dst, void const *src, size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *dst, void const *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			ft_print_dblarray(char **dblarray);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(char const *str);
void			ft_putstr_fd(char const *s, int fd);
void			*ft_reallocme(void *str, size_t size, size_t addsize);
char			**ft_split_whitespace(char const *s);
char			*ft_strcat(char *s1, char const *s2);
char			*ft_strchr(char const *s, int c);
int				ft_strclen(char *str, char c);
void			ft_strclr(char *c);
int				ft_strcmp(char const *s1, char const *s2);
char			*ft_strcpy(char *dest, char const *src);
void			ft_strdel(char **as);
char			*ft_strdup(char const *src);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strict_strnequ(char const *s1, char const *s2, size_t n);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoinnfree(char *s1, char *s2, int xfree);
size_t			ft_strlcat(char *dst, char const *src, size_t size);
size_t			ft_strlen(char const *str);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *s1, char const *s2, size_t n);
int				ft_strncmp(char const *s1, char const *s2, size_t n);
char			*ft_strncpy(char *dest, char const *src, size_t len);
char			*ft_strncpynfree(char *dest, char const *src, size_t len);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(char const *big, char const *little, size_t len);
char			*ft_strrchr(char const *s, int c);
char			**ft_strsplit(char const *s, char c);
char			*ft_strstr(char const *big, char const *little);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_tablen(char **tab);
char			*ft_uitoa_base(unsigned int value, int base);
char			*ft_ultoa_base(unsigned long nbr, char *base);
int				get_next_line(const int fd, char **line);

#endif
