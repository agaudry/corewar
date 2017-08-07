/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_treat_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 12:07:46 by agaudry           #+#    #+#             */
/*   Updated: 2017/08/07 15:30:20 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	get_instr_args(t_env *env, t_process *p, int args, int ocp)
{
	int		arg_nb;
	int		i;

	arg_nb = 0;
	if (ocp)
		i = 2;
	else
		i = 1;
	while (arg_nb < args)
	{
		i += get_arg_from_memory(env, p, arg_nb, i);
		arg_nb++;
	}
}

void	treat_reg(t_process *p, int arg_nb)
{
	if (p->arg_type[arg_nb] == REG_CODE)
	{
		p->arg_len[arg_nb] = 4;
		p->arg[arg_nb] = p->reg[p->arg[arg_nb] - 1];
	}
}

void	treat_ind(t_env *env, t_process *p, int arg_nb)
{
	if (p->arg_type[arg_nb] == IND_CODE)
	{
		p->arg_len[arg_nb] = 4;
		if (p->ft == op_lld)
			p->arg_len[arg_nb] = 2;
		get_arg_from_memory(env, p, arg_nb, p->arg[arg_nb] % IDX_MOD);
	}
}
