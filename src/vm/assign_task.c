/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_task.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichals <amichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 18:48:17 by amichals          #+#    #+#             */
/*   Updated: 2017/08/01 16:37:57 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	assign_ft(t_env *env)
{
	env->ft[0] = op_live;
	env->ft[1] = op_ld;
	env->ft[2] = op_st;
	env->ft[3] = op_add;
	env->ft[4] = op_sub;
	env->ft[5] = op_and;
	env->ft[6] = op_or;
	env->ft[7] = op_xor;
	env->ft[8] = op_zjmp;
	env->ft[9] = op_ldi;
	env->ft[10] = op_sti;
	env->ft[11] = op_fork;
	env->ft[12] = op_lld;
	env->ft[13] = op_lldi;
	env->ft[14] = op_lfork;
	env->ft[15] = op_aff;
}

void	assign_task(unsigned char task, t_env *env, t_process *process)
{
	if (task > 0 && task < 17)
	{
		process->ft = env->ft[task - 1];
		process->countdown = g_op_tab[task - 1].cycles - 1;
	}
	else
		process->pc = (process->pc + 1) % MEM_SIZE;
}
