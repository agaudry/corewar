/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichals <amichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 18:50:36 by amichals          #+#    #+#             */
/*   Updated: 2017/08/01 16:43:27 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		op_add(t_env *env, t_process *p)
{
	int ocp;

	ocp = env->field[(p->pc + 1) % MEM_SIZE];
	if ((check_instr(ocp, 3, env, p)))
	{
		get_instr_args(env, p, 3, 1);
		p->reg[(p->arg[2] - 1)] =
		p->reg[(p->arg[0] - 1)] + p->reg[(p->arg[1] - 1)];
		p->carry = !(p->reg[p->arg[2] - 1]);
		verb_process(env, p, 3, 0);
	}
	verb_adv(env, p);
	return (env->instr_len);
}

int		op_sub(t_env *env, t_process *p)
{
	int ocp;

	ocp = env->field[(p->pc + 1) % MEM_SIZE];
	if ((check_instr(ocp, 4, env, p)))
	{
		get_instr_args(env, p, 3, 1);
		p->reg[(p->arg[2] - 1)] =
		p->reg[(p->arg[0] - 1)] - p->reg[(p->arg[1] - 1)];
		p->carry = !(p->reg[p->arg[2] - 1]);
		verb_process(env, p, 4, 0);
	}
	verb_adv(env, p);
	return (env->instr_len);
}
