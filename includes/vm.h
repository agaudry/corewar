/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichals <amichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 15:29:06 by amichals          #+#    #+#             */
/*   Updated: 2017/08/07 14:41:10 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <corewar.h>

typedef struct		s_champ
{
	t_header		*header;
	char			code[CHAMP_MAX_SIZE];
	int				n;
}					t_champ;

typedef struct s_process	t_process;
typedef struct s_env		t_env;

struct				s_process
{
	t_champ			*owner;
	int				process_nb;
	int				last_live;
	int				countdown;
	int				pc;
	int				live;
	int				reg[REG_NUMBER];
	int				carry;
	int				arg_type[3];
	int				arg_len[3];
	int				arg[3];
	int				(*ft)(t_env *, t_process *);
};

struct				s_env
{
	unsigned char	field[MEM_SIZE + 1];
	int				cycle_counter;
	int				nb_players;
	int				nb_process;
	t_list			*champs;
	t_list			*process;
	t_champ			*last_heard_of;
	unsigned char	param_code;
	int				instr_len;
	int				instr_cycles;
	int				live_nb;
	int				cycle_to_die;
	int				aff;
	int				dump;
	int				step;
	int				verb;
	int				(*ft[16])(t_env *, t_process *);
};

/*
** verbose defines
*/
# define LIVES		1
# define CYCLES		2
# define OP			4
# define DEATHS		8
# define PC_MOVE	16

/*
** init_structs_vm.c
*/
t_champ				*ft_new_champ(void);
t_process			*ft_new_process(void);
t_list				*ft_new_list(void);
t_env				*ft_new_env(void);

/*
** assign_task.c
*/
void				assign_ft(t_env *e);
void				assign_task(unsigned char task,
					t_env *e, t_process *process);

/*
** error_args.c
*/
void				n_already_taken_error(int n);

/*
** error_args2.c
*/
void				print_usage(void);
void				invalid_option_error(char *arg);
void				invalid_arg_error(char *arg);
void				invalid_n_error();
void				too_many_champs_error();

/*
** error_headers.c
*/
void				invalid_header_error(char *arg);
void				code_too_small_error(char *arg);
void				code_too_big_error(char *arg, unsigned int size);
void				code_size_diff_error(char *arg);

/*
** error_misc.c
*/
void				ft_malloc_error_exit(void);

/*
** getters_vm.c
*/
t_champ				*get_c(t_list *lst);
t_header			*get_c_header(t_list *lst);
char				*get_c_code(t_list *lst);
int					get_c_n(t_list *lst);

/*
** getters_process.c
*/
t_process			*get_p(t_list *lst);
int					get_p_countdown(t_list *lst);

/*
** parse_args.c
*/
int					is_option(char **argv, int *i, t_env *env);
void				get_args(int argc, char **argv, t_env *env);

/*
** parse_champ.c
*/
void				get_code(int fd, char *arg, t_champ *champ);
void				get_name_comment_size(int fd, char *arg, t_champ *champ);
void				get_magic_number(int fd, char *arg, t_champ *champ);
void				stock_champ(char *arg, t_champ *champ);
void				get_champ(char *arg, t_list **champs, int n);

/*
** setters_vm.c
*/
t_champ				*set_champ_n(t_champ *champ, int n);
int					reset_p_live(t_list *lst);

/*
** treat_n.c
*/
int					champ_n_taken(int n, t_list *champs);
void				assign_champ_n(t_list **tmp, t_list *champs, int nb);
void				fill_n_check(t_env *env, t_list *champs);
void				treat_n(char **argv, int *i, t_env *env);

/*
** predicates.c
*/
int					ft_str_isdigits(char *str);

/*
** init_game.c
*/
void				setup_field(t_env *env);

/*
** dump.c
*/
void				print_field(unsigned char *field);

/*
** cycle_manager.c
*/
void				round_manager(t_env *env, int round_size);
void				cycle_manager(t_env *env);

/*
** verbose.c
*/
void				verb_process(t_env *env, t_process *process, int instr_nb,
					int index);
void				verb_p2(t_env *env, t_process *process, int instr_nb,
					int index);
void				verb_adv(t_env *env, t_process *process);
void				verb_player_is_alive(t_env *env, t_list *champ);

/*
** die_hard_process.c
*/
void				process_goes_to_heaven(t_list **dying_process);
void				kill_process(t_env *env, t_list *prev_process,
					t_list *this_process);

/*
** get_treat_args.c
*/
void				get_instr_args(t_env *env, t_process *p, int args, int ocp);
void				treat_reg(t_process *p, int arg_nb);
void				treat_ind(t_env *env, t_process *p, int arg_nb);

/*
** copy_from_to_memory.c
*/
int					get_arg_from_memory(t_env *e, t_process *p, int arg_nb,
					int i);
void				cpy_to_memory_from_reg(t_env *e, t_process *p, int reg_c,
					int i);
int					cpy_from_memory_to_reg(t_env *e, t_process *p, int reg,
					int i);

/*
**op_misc.c
*/
int					op_live(t_env *e, t_process *process);
int					op_aff(t_env *env, t_process *process);
int					op_zjmp(t_env *env, t_process *process);

/*
**op_stx.c
*/
int					op_st(t_env *env, t_process *p);
int					op_sti(t_env *env, t_process *p);

/*
** op_ld.c
*/
int					op_ld(t_env *env, t_process *p);
int					op_lld(t_env *env, t_process *p);

/*
** op_ldi.c
*/
int					op_ldi(t_env *env, t_process *p);
int					op_lldi(t_env *env, t_process *p);

/*
** op_math.c
*/
int					op_add(t_env *e, t_process *p);
int					op_sub(t_env *e, t_process *p);

/*
** op_logical.c
*/
int					op_and(t_env *env, t_process *p);
int					op_or(t_env *env, t_process *p);
int					op_xor(t_env *env, t_process *p);

/*
** check_instr.c
*/
unsigned char		get_param_code(int ocp, char param_nb);
int					check_param_code(t_env *env, unsigned char param_code,
					int param_type, int label_sz);
int					check_arg(t_process *process, int instr_nb, t_env *e,
					int arg_nb);
int					check_instr(int ocp, int instr_nb, t_env *e,
					t_process *process);

/*
** op_fork.c
*/
int					get_new_process_nb(t_list *process);
int					op_fork(t_env *env, t_process *p);
int					op_lfork(t_env *env, t_process *p);

#endif
