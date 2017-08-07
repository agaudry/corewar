/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichals <amichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 18:50:25 by amichals          #+#    #+#             */
/*   Updated: 2017/08/07 14:59:26 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		op_ld(t_env *env, t_process *p)
{
	int ocp;

	ocp = env->field[(p->pc + 1) % MEM_SIZE];
	if ((check_instr(ocp, 1, env, p)))
	{
		get_instr_args(env, p, 2, 1);
		treat_ind(env, p, 0);
		p->reg[p->arg[1] - 1] = p->arg[0];
		p->carry = !(p->reg[p->arg[1] - 1]);
		verb_process(env, p, 1, 0);
	}
	verb_adv(env, p);
	return (env->instr_len);
}

int		op_lld(t_env *env, t_process *p)
{
	int ocp;

	ocp = env->field[(p->pc + 1) % MEM_SIZE];
	if ((check_instr(ocp, 12, env, p)))
	{
		get_instr_args(env, p, 2, 1);
		treat_ind(env, p, 0);
		p->reg[p->arg[1] - 1] = p->arg[0];
		p->carry = !(p->reg[p->arg[1] - 1]);
		verb_process(env, p, 12, 0);
	}
	verb_adv(env, p);
	return (env->instr_len);
}

int		op_ldi(t_env *env, t_process *p)
{
	int	s;
	int ocp;

	s = 0;
	ocp = env->field[(p->pc + 1) % MEM_SIZE];
	if ((check_instr(ocp, 9, env, p)))
	{
		get_instr_args(env, p, 3, 1);
		treat_ind(env, p, 0);
		treat_reg(p, 0);
		treat_reg(p, 1);
		s = p->arg[0] + p->arg[1];
		cpy_from_memory_to_reg(env, p, p->arg[2] - 1, (s % IDX_MOD));
		verb_process(env, p, 9, (p->pc + (s % IDX_MOD)));
	}
	verb_adv(env, p);
	return (env->instr_len);
}

int		op_lldi(t_env *env, t_process *p)
{
	int	s;
	int ocp;

	s = 0;
	ocp = env->field[(p->pc + 1) % MEM_SIZE];
	if ((check_instr(ocp, 13, env, p)))
	{
		get_instr_args(env, p, 3, 1);
		treat_ind(env, p, 0);
		treat_reg(p, 0);
		treat_reg(p, 1);
		s = p->arg[0] + p->arg[1];
		cpy_from_memory_to_reg(env, p, p->arg[2] - 1, s);
		p->carry = !(p->reg[p->arg[2] - 1]);
		verb_process(env, p, 13, p->pc + s);
	}
	verb_adv(env, p);
	return (env->instr_len);
}
