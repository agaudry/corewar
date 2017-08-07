/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_misc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkantzer <mkantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 10:29:27 by mkantzer          #+#    #+#             */
/*   Updated: 2017/08/01 10:30:01 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		op_live(t_env *env, t_process *process)
{
	t_list	*tmp;

	process->arg_len[0] = 4;
	env->instr_len = 5;
	get_instr_args(env, process, 1, 0);
	tmp = env->champs;
	if (env->verb & OP)
		ft_printf("P %4d | live %d\n", process->process_nb, process->arg[0]);
	while (tmp)
	{
		if (get_c_n(tmp) == process->arg[0])
		{
			verb_player_is_alive(env, tmp);
			env->last_heard_of->n = get_c_n(tmp);
			env->last_heard_of->header = get_c_header(tmp);
		}
		tmp = tmp->next;
	}
	verb_adv(env, process);
	process->live += 1;
	process->last_live = -1;
	env->live_nb += 1;
	return (env->instr_len);
}

int		op_zjmp(t_env *env, t_process *process)
{
	process->arg_len[0] = 2;
	env->instr_len = 3;
	get_instr_args(env, process, 1, 0);
	verb_process(env, process, 8, process->carry);
	if (process->carry)
		return (process->arg[0] % IDX_MOD);
	verb_adv(env, process);
	return (env->instr_len);
}

int		op_aff(t_env *env, t_process *process)
{
	int ocp;

	ocp = (env->field[(process->pc + 1) % MEM_SIZE]);
	if ((check_instr(ocp, 15, env, process)))
	{
		get_instr_args(env, process, 1, 1);
		if (env->aff)
		{
			ft_putstr("Aff: ");
			ft_putchar(process->reg[process->arg[0] - 1] % 256);
			ft_putchar('\n');
		}
	}
	verb_adv(env, process);
	return (env->instr_len);
}
