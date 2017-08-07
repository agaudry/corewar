/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_logical.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichals <amichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 18:50:04 by amichals          #+#    #+#             */
/*   Updated: 2017/08/07 14:40:31 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int			op_and(t_env *env, t_process *p)
{
	int ocp;

	ocp = env->field[(p->pc + 1) % MEM_SIZE];
	if ((check_instr(ocp, 5, env, p)))
	{
		get_instr_args(env, p, 3, 1);
		treat_reg(p, 0);
		treat_ind(env, p, 0);
		treat_reg(p, 1);
		treat_ind(env, p, 1);
		p->reg[p->arg[2] - 1] = p->arg[0] & p->arg[1];
		p->carry = !(p->reg[p->arg[2] - 1]);
		verb_process(env, p, 5, 0);
	}
	verb_adv(env, p);
	return (env->instr_len);
}

int			op_or(t_env *env, t_process *p)
{
	int ocp;

	ocp = env->field[(p->pc + 1) % MEM_SIZE];
	if ((check_instr(ocp, 6, env, p)))
	{
		get_instr_args(env, p, 3, 1);
		treat_reg(p, 0);
		treat_ind(env, p, 0);
		treat_reg(p, 1);
		treat_ind(env, p, 1);
		p->reg[p->arg[2] - 1] = p->arg[0] | p->arg[1];
		p->carry = !(p->reg[p->arg[2] - 1]);
		verb_process(env, p, 6, 0);
	}
	verb_adv(env, p);
	return (env->instr_len);
}

int			op_xor(t_env *env, t_process *p)
{
	int ocp;

	ocp = env->field[(p->pc + 1) % MEM_SIZE];
	if ((check_instr(ocp, 7, env, p)))
	{
		get_instr_args(env, p, 3, 1);
		treat_reg(p, 0);
		treat_ind(env, p, 0);
		treat_reg(p, 1);
		treat_ind(env, p, 1);
		p->reg[p->arg[2] - 1] = p->arg[0] ^ p->arg[1];
		p->carry = !(p->reg[p->arg[2] - 1]);
		verb_process(env, p, 7, 0);
	}
	verb_adv(env, p);
	return (env->instr_len);
}
