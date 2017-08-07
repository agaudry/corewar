/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_stx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichals <amichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 18:50:52 by amichals          #+#    #+#             */
/*   Updated: 2017/08/07 14:40:39 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		op_st(t_env *env, t_process *p)
{
	int ocp;

	ocp = env->field[(p->pc + 1) % MEM_SIZE];
	if ((check_instr(ocp, 2, env, p)))
	{
		get_instr_args(env, p, 2, 1);
		verb_process(env, p, 2, 0);
		if (p->arg_type[1] == REG_CODE)
			p->reg[p->arg[1] - 1] = p->reg[p->arg[0] - 1];
		else
			cpy_to_memory_from_reg(env, p, p->reg[p->arg[0] - 1],
			(short int)p->arg[1] % IDX_MOD);
	}
	verb_adv(env, p);
	return (env->instr_len);
}

int		op_sti(t_env *env, t_process *p)
{
	int ocp;
	int	sum;

	sum = 0;
	ocp = env->field[(p->pc + 1) % MEM_SIZE];
	if ((check_instr(ocp, 10, env, p)))
	{
		get_instr_args(env, p, 3, 1);
		treat_reg(p, 1);
		treat_reg(p, 2);
		treat_ind(env, p, 1);
		sum = p->arg[1] + p->arg[2];
		verb_process(env, p, 10, p->pc + (sum % IDX_MOD));
		cpy_to_memory_from_reg(env, p, p->reg[p->arg[0] - 1],
		(sum % IDX_MOD));
	}
	verb_adv(env, p);
	return (env->instr_len);
}
