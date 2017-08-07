/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 15:52:54 by agaudry           #+#    #+#             */
/*   Updated: 2017/08/07 19:44:00 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <corewar.h>

typedef struct		s_stockln
{
	char			*line_str;
	int				line_nb;
	int				idx;
}					t_stockln;

typedef struct		s_label
{
	char			*name;
	int				address;
}					t_label;

typedef struct		s_arg
{
	char			arg_s;
	short int		arg_m;
	int				arg_l;
}					t_arg;

typedef struct		s_main
{
	int				fd;
	int				last_header_line;
	int				name_check;
	int				comment_check;
	t_list			*file;
	t_header		*header;
	t_list			*label;
	t_arg			*arg_fmt;
}					t_main;

/*
** main_asm.c
*/
void				ft_del_ln(void *content, size_t content_size);
void				ft_del_lb(void *content, size_t content_size);
void				ft_free_all(char *name, t_main *main);

/*
** exit.c
*/
void				ft_malloc_error_exit(void);
void				ft_header_error_exit(void);
void				ft_missing_code_error_exit(void);
void				ft_syntax_error_exit(int line_nb);
void				ft_size_error_exit(int limit);

/*
** exit2.c
*/
void				ft_label_error_exit(char *str, int line_nb);
void				ft_file_error_exit(char *str);

/*
** init_structs.c
*/
t_stockln			*ft_new_stockln(void);
t_label				*ft_new_label(void);
t_list				*ft_new_list(void);
t_arg				*ft_new_arg(void);
t_main				*ft_new_main(void);

/*
** setters.c
*/
t_list				*ft_set_content(t_list *lst, void *content);
t_stockln			*ft_set_ln_strnb(t_stockln *ln, char *content, int i);
t_stockln			*ft_set_ln_idx(t_stockln *ln, int idx);
t_label				*ft_set_label_straddress(t_label *label, char *str, int a);

/*
** getters.c
*/
t_stockln			*ft_get_content_ln(t_list *lst);
t_label				*ft_get_content_lb(t_list *lst);
char				*ft_get_lb_name(t_list *lst);
int					ft_get_lb_address(t_list *lst);
int					ft_get_ln_nb(t_list *lst);

/*
** getters2.c
*/
int					ft_get_ln_idx(t_list *lst);
char				*ft_get_ln_str(t_list *lst);

/*
** predicates.c
*/
int					ft_str_is_whitespace(char *str);
int					ft_str_isdigits(char *str);
int					ft_str_is_ignored(char *str);

/*
** split_whitespace_commas.c
*/
char				**ft_split_whitespace_commas(char const *s);

/*
** get_whole_file.c
*/
void				ft_get_line(char *line, t_list **file);
t_list				*ft_get_file(int fd, char *name);

/*
** parsing_header.c
*/
void				ft_get_name_comment(t_list **file, char *stock, int limit,
					t_main *main);
void				ft_find_name_comment(t_list **file, t_header *header,
					t_main *main);
void				ft_parse_header(t_list *file, t_main *main);

/*
** check_header.c
*/
void				ft_check_eol(char *str, int line_nb);
int					ft_check_len(char *tmp, int stockd_len,
					int limit, int final);
void				ft_check_ln_fmt(char *str, int line_nb);

/*
** check_instructions.c
*/
int					ft_is_reg(char *str);
int					ft_is_dir(char *str);
int					ft_is_ind(char *str);
int					ft_check_param(int param, char *str);
int					ft_check_instr_args(int arg_nb, int *param, char **split);

/*
** check_instr_or_label.c
*/
char				*ft_is_label(char *str, t_list *file, int size);
int					ft_is_label_param(char *str);
int					ft_is_instr(char *str, t_list *file, int size);

/*
** parsing_size.c
*/
void				ft_stock_label(t_main *main, t_list **label, char *str,
					int a);
int					ft_param_size(int instr_nb, char *str);
int					ft_instr_size(int instr_nb, char *str);
unsigned int		ft_parse_size(t_list **file, t_main *main);

/*
** treat_label_arg.c
*/
int					ft_match_label(char *arg, t_list *label);
void				ft_label_fmt(char *arg, int label_sz, t_main *main,
					t_stockln *ln);

/*
** write_instr.c
*/
char				ft_ocp_arg(char *str);
void				ft_write_ocp(int fd, int instr_nb, char **split);
void				ft_write_arg(char *arg, int label_sz, t_main *main);
void				ft_arg_fmt(char *arg, int label_sz, t_main *main,
					t_stockln *ln);
void				ft_write_instr(int instr_nb, char *str, t_main *main,
					t_stockln *ln);

/*
** write_cor.c
*/
void				ft_write_header(int fd, t_header *header);
int					ft_label_exists(char *arg, t_main *main);
void				ft_wrong_label(int *i, t_main *main, t_list *file,
					char **split);
void				ft_check_labels(t_list *file, t_main *main);
void				ft_write_code(t_list *file, t_main *main);

/*
** write_cor2.c
*/
void				ft_write_cor(t_main *main, char *name);

/*
** atoi_overflow.c
*/
long				ft_atoi_overflow(char *str);

#endif
