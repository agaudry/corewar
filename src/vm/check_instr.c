/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 16:35:00 by agaudry           #+#    #+#             */
/*   Updated: 2017/07/29 12:07:10 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

unsigned char	get_param_code(int ocp, char param_nb)
{
	unsigned char	param_code;

	param_code = ocp & (0b00000011 << (8 - (param_nb * 2)));
	param_code = (param_code >> (8 - (param_nb * 2)));
	return (param_code);
}

int				check_op_vs_args(unsigned char param_code, int param_type)
{
	if ((param_code == REG_CODE) && !(T_REG & param_type))
		return (0);
	if ((param_code == DIR_CODE) && !(T_DIR & param_type))
		return (0);
	if ((param_code == IND_CODE) && !(T_IND & param_type))
		return (0);
	return (1);
}

int				check_arg(t_process *process, int instr_nb, t_env *e,
int arg_nb)
{
	process->arg_len[arg_nb] = 0;
	process->arg_type[arg_nb] = 0;
	if (e->param_code == REG_CODE)
		process->arg_len[arg_nb] = 1;
	else if (e->param_code == IND_CODE)
		process->arg_len[arg_nb] = 2;
	else if ((e->param_code == DIR_CODE) && g_op_tab[instr_nb].label_sz)
		process->arg_len[arg_nb] = 2;
	else if ((e->param_code == DIR_CODE) && !(g_op_tab[instr_nb].label_sz))
		process->arg_len[arg_nb] = 4;
	process->arg_type[arg_nb] = e->param_code;
	e->instr_len += process->arg_len[arg_nb];
	if (!(check_op_vs_args(e->param_code, g_op_tab[instr_nb].param[arg_nb])))
		return (0);
	return (process->arg_len[arg_nb]);
}

int				set_len(t_env *e, t_process *process, int instr_nb)
{
	int		tmp_pc;

	tmp_pc = 0;
	if (g_op_tab[instr_nb].ocp)
	{
		tmp_pc = (process->pc + 2) % MEM_SIZE;
		e->instr_len += 1;
	}
	else
		tmp_pc = (process->pc + 1) % MEM_SIZE;
	return (tmp_pc);
}

int				check_instr(int ocp, int instr_nb, t_env *e, t_process *process)
{
	int		tmp_pc;
	int		check;
	int		i;

	i = 0;
	check = 0;
	e->instr_len = 1;
	tmp_pc = set_len(e, process, instr_nb);
	while (i < g_op_tab[instr_nb].arg_nb)
	{
		e->param_code = get_param_code(ocp, i + 1);
		if (!(check_arg(process, instr_nb, e, i))
		|| ((e->param_code == REG_CODE)
		&& (e->field[tmp_pc] < 1 || e->field[tmp_pc] > 16)))
			;
		else
			check++;
		tmp_pc = (tmp_pc + process->arg_len[i]) % MEM_SIZE;
		i++;
	}
	if (check == g_op_tab[instr_nb].arg_nb)
		return (1);
	else
		return (0);
}
