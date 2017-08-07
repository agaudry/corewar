/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 13:29:18 by agaudry           #+#    #+#             */
/*   Updated: 2017/03/06 15:05:22 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include <libft.h>

typedef struct	s_fmt
{
	int				option;
	int				min_width;
	int				precision;
	int				length_modifier;
	char			conv_type;
	va_list			ap;
	long			signednb_arg;
	unsigned long	unsignednb_arg;
	char			*str_arg;
	wchar_t			*wstr_arg;
	int				arg_len;
	int				arg_fmtlen;
	int				style;
	int				style_len;
}				t_fmt;

typedef	struct	s_save
{
	char		*ret;
	int			i;
}				t_save;

/*
** ft_printf.c
*/
int				ft_printf(char const *format, ...);
int				ft_exit(t_fmt *fmt, t_save *save, int ret);
int				ft_get_fmt(t_fmt *fmt, char *str, int *i);
int				ft_treat_arg(t_fmt *fmt, t_save *save, char *str, int *i);
int				ft_stock(char const *format, t_fmt *fmt, t_save *save);

/*
** ft_sdprintf.c
*/
int				ft_dprintf(int fd, char const *format, ...);
int				ft_sprintf(char *str, char const *format, ...);

/*
** get_len.c
*/
int				ft_get_len(t_fmt *fmt);
int				ft_get_fmtlen(t_fmt *fmt);

/*
** get_arg.c
*/
void			ft_get_argnlen(t_fmt *fmt);
int				ft_get_fmtlen(t_fmt *fmt);
int				ft_get_len(t_fmt *fmt);
void			ft_get_signednb(t_fmt *fmt);
void			ft_get_str(t_fmt *fmt);
void			ft_get_unsignednb(t_fmt *fmt);

/*
** get_fmt.c
*/
void			ft_get_option(t_fmt *fmt, char *str, int *i);
void			ft_get_min_width(t_fmt *fmt, char *str, int *i);
void			ft_get_precision(t_fmt *fmt, char *str, int *i);
void			ft_get_length_modifier(t_fmt *fmt, char *str, int *i);
int				ft_get_conv_type(t_fmt *fmt, char *str, int *i);

/*
** check_fmt.c
*/
int				ft_check_fmt(t_fmt *fmt);
int				ft_limits(t_fmt *fmt);

/*
** struc_init.c
*/
t_fmt			*ft_struct_init(t_fmt *fmt);
t_fmt			*ft_equivalence(t_fmt *fmt);
t_save			*ft_struct_init_save(t_save *save);
char			*ft_conv_nb(t_fmt *fmt);

/*
** treat_c.c
*/
int				ft_nb_len(long long value, long long base);
int				ft_ulnb_len(unsigned long long value, unsigned long long base);
void			ft_c(t_fmt *fmt, t_save *save);

/*
** treat_percent.c
*/
void			ft_treat_percent(t_fmt *fmt, t_save *save);

/*
** treat_str.c
*/
char			*ft_strcpy_alt(char *dest, char const *src, int j);
void			ft_str(t_fmt *fmt, t_save *save);

/*
** treat_wc.c
*/
int				ft_define_mask(int len);
int				ft_define_count(int len);
int				ft_apply_mask(int nb, int mask, int count);
void			ft_wc(int nb, int len, t_save *save);
int				ft_wstrlen(wchar_t *str, int prec);

/*
** treat_nb.c
*/
void			ft_treat_min_width(t_fmt *fmt, t_save *save);
void			ft_put_option(t_fmt *fmt, t_save *save);
void			ft_put_precision(t_fmt *fmt, t_save *save);
void			ft_treat_nb(t_fmt *fmt, t_save *save);
void			ft_put_hash(t_fmt *fmt, t_save *save);

/*
** get_style.c
*/
void			ft_get_color(t_fmt *fmt, char *str, int *i);
void			ft_get_background(t_fmt *fmt, char *str, int *i);
void			ft_get_typo(t_fmt *fmt, char *str, int *i);
int				ft_get_style(t_fmt *fmt, char *str, int *i);

/*
** treat_style.c
*/
void			ft_write_seq(t_save *save, char *seq);
void			ft_write_color(t_fmt *fmt, t_save *save);
void			ft_write_background(t_fmt *fmt, t_save *save);
void			ft_write_typo(t_fmt *fmt, t_save *save);
void			ft_treat_style(t_fmt *fmt, t_save *save);

# define NULL_STR "(null)"

/*
** options and length modifiers
*/
# define MIN	0b00000001
# define ZERO	0b00000010
# define HASH	0b00000100
# define PLUS	0b00001000
# define SPACE	0b00010000

# define HH		0b00000001
# define H		0b00000010
# define L		0b00000100
# define LL		0b00001000
# define J		0b00010000
# define Z		0b00100000

/*
** wchar masks
*/
# define ONE	0b00000000
# define TWO	0b1100000010000000
# define THREE	0b111000001000000010000000
# define FOUR	0b11110000100000001000000010000000

/*
** style
*/
# define RESET_STYLE	0x80000
# define COLOR			0x10000
# define TYPO			0x20000
# define BACKGROUND		0x40000
# define RESET_COLOR	0x3FFF01
# define DARK			0x2
# define RED			0x4
# define GREEN			0x8
# define YELLOW			0x10
# define BLUE			0x20
# define MAGENTA		0x40
# define CYAN			0x80
# define BOLD			0x100
# define ITALIC			0x200
# define UNDERLINE		0x400
# define FLICKER		0x800

#endif
