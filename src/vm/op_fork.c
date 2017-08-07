/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichals <amichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 18:48:49 by amichals          #+#    #+#             */
/*   Updated: 2017/08/01 16:41:56 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

t_process	*copy_process(t_env *env, t_process *process)
{
	t_process	*new;
	int			reg_nb;

	reg_nb = -1;
	if ((new = (t_process *)malloc(sizeof(t_process))))
	{
		new->owner = process->owner;
		new->process_nb = env->nb_process + 1;
		env->nb_process += 1;
		new->last_live = process->last_live + 1;
		new->countdown = 0;
		new->pc = 0;
		new->live = process->live;
		while (++reg_nb < REG_NUMBER)
			new->reg[reg_nb] = process->reg[reg_nb];
		new->carry = process->carry;
		new->ft = NULL;
	}
	else
		ft_malloc_error_exit();
	return (new);
}

int			op_fork(t_env *env, t_process *p)
{
	t_list		*new;

	p->arg_len[0] = 2;
	env->instr_len = 3;
	get_instr_args(env, p, 1, 0);
	new = ft_new_list();
	new->content = copy_process(env, p);
	get_p(new)->pc = ((p->pc + (p->arg[0] % IDX_MOD)) % MEM_SIZE);
	ft_lstadd(&env->process, new);
	verb_process(env, p, 11, p->pc + (p->arg[0] % IDX_MOD));
	verb_adv(env, p);
	return (env->instr_len);
}

int			op_lfork(t_env *env, t_process *p)
{
	t_list		*new;

	p->arg_len[0] = 2;
	env->instr_len = 3;
	get_instr_args(env, p, 1, 0);
	new = ft_new_list();
	new->content = copy_process(env, p);
	get_p(new)->pc = ((p->pc + p->arg[0])) % MEM_SIZE;
	ft_lstadd(&env->process, new);
	verb_process(env, p, 14, p->pc + p->arg[0]);
	verb_adv(env, p);
	return (env->instr_len);
}
