/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 14:03:06 by agaudry           #+#    #+#             */
/*   Updated: 2017/08/06 18:53:11 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	verb_spec(t_process *p, int instr_nb, int index)
{
	if (instr_nb == 9)
		ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
		p->arg[0], p->arg[1], p->arg[0] + p->arg[1], index);
	else if (instr_nb == 10)
		ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
		p->arg[1], p->arg[2], p->arg[1] + p->arg[2], index);
	else if (instr_nb == 13)
		ft_printf("       | -> load from %d + %d = %d (with pc %d)\n",
		p->arg[0], p->arg[1], p->arg[0] + p->arg[1], index);
}

void	verb_process(t_env *env, t_process *process, int instr_nb, int index)
{
	int		arg_nb;

	arg_nb = 0;
	if (env->verb & OP)
	{
		ft_printf("P %4d | %s", process->process_nb,
		g_op_tab[instr_nb].instr_name);
		while (arg_nb < g_op_tab[instr_nb].arg_nb)
		{
			if (process->arg_len[arg_nb] == 1
			&& g_op_tab[instr_nb].param[arg_nb] == T_REG)
				ft_printf(" r%d", process->arg[arg_nb]);
			else if (process->arg_len[arg_nb] == 1)
				ft_printf(" %d", process->arg[arg_nb]);
			else if (process->arg_len[arg_nb] == 2)
				ft_printf(" %d", (short int)process->arg[arg_nb]);
			else
				ft_printf(" %d", process->arg[arg_nb]);
			arg_nb++;
		}
		verb_p2(env, process, instr_nb, index);
	}
}

void	verb_p2(t_env *env, t_process *process, int instr_nb, int index)
{
	if (env->verb & OP)
	{
		if (instr_nb == 11 || instr_nb == 14)
			ft_printf(" (%d)", index);
		if (instr_nb == 8 && index)
			ft_putstr(" OK");
		if (instr_nb == 8 && !index)
			ft_putstr(" FAILED");
		ft_putchar('\n');
		if (instr_nb == 9 || instr_nb == 10 || instr_nb == 13)
			verb_spec(process, instr_nb, index);
	}
}

void	verb_adv(t_env *env, t_process *process)
{
	int		len;
	int		i;

	len = env->instr_len;
	i = 0;
	if (env->verb & PC_MOVE)
	{
		ft_printf("ADV %d (", len);
		if (process->pc == 0)
			ft_putstr("0x");
		ft_printf("%#.4x -> ", process->pc);
		if (process->pc + len == 0)
			ft_putstr("0x");
		ft_printf("%#.4x) ", process->pc + len);
		while (i < len)
		{
			ft_printf("%.2hhx ", env->field[(process->pc + i) % MEM_SIZE]);
			i++;
		}
		ft_putchar('\n');
	}
}

void	verb_player_is_alive(t_env *env, t_list *champ)
{
	if (env->verb & LIVES)
		ft_printf("Player %d (%s) is said to be alive\n",
		get_c_n(champ) * -1, get_c_header(champ)->prog_name);
}
