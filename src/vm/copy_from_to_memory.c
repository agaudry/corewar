/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_from_to_memory.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 08:34:54 by agaudry           #+#    #+#             */
/*   Updated: 2017/08/06 18:56:29 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		get_arg_from_memory(t_env *e, t_process *p, int arg_nb, int i)
{
	p->arg[arg_nb] = 0;
	while ((p->pc + i) < 0)
		i += MEM_SIZE;
	if (p->arg_len[arg_nb] == 1)
		p->arg[arg_nb] = (unsigned char)(e->field[(p->pc + i) % MEM_SIZE]);
	else if (p->arg_len[arg_nb] == 2)
	{
		p->arg[arg_nb] = ((e->field[(p->pc + i) % MEM_SIZE]) << 8);
		p->arg[arg_nb] |= (e->field[(p->pc + i + 1) % MEM_SIZE]);
		p->arg[arg_nb] = (short)p->arg[arg_nb];
	}
	else if (p->arg_len[arg_nb] == 4)
	{
		p->arg[arg_nb] = ((e->field[(p->pc + i) % MEM_SIZE]) << 24);
		p->arg[arg_nb] |= ((e->field[(p->pc + i + 1) % MEM_SIZE]) << 16);
		p->arg[arg_nb] |= ((e->field[(p->pc + i + 2) % MEM_SIZE]) << 8);
		p->arg[arg_nb] |= (e->field[(p->pc + i + 3) % MEM_SIZE]);
		p->arg[arg_nb] = (int)p->arg[arg_nb];
	}
	return (p->arg_len[arg_nb]);
}

void	cpy_to_memory_from_reg(t_env *e, t_process *p, int reg_c, int i)
{
	while ((p->pc + i) < 0)
		i += MEM_SIZE;
	e->field[(p->pc + i) % MEM_SIZE] =
	(unsigned char)((reg_c & 0xFF000000) >> 24);
	e->field[(p->pc + i + 1) % MEM_SIZE] =
	(unsigned char)((reg_c & 0x00FF0000) >> 16);
	e->field[(p->pc + i + 2) % MEM_SIZE] =
	(unsigned char)((reg_c & 0x0000FF00) >> 8);
	e->field[(p->pc + i + 3) % MEM_SIZE] =
	(unsigned char)((reg_c & 0x000000FF));
}

int		cpy_from_memory_to_reg(t_env *e, t_process *p, int reg, int i)
{
	p->reg[reg] = 0;
	while ((p->pc + i) < 0)
		i += MEM_SIZE;
	p->reg[reg] = ((e->field[(p->pc + i) % MEM_SIZE]) << 24);
	p->reg[reg] |= ((e->field[(p->pc + i + 1) % MEM_SIZE]) << 16);
	p->reg[reg] |= ((e->field[(p->pc + i + 2) % MEM_SIZE]) << 8);
	p->reg[reg] |= (e->field[(p->pc + i + 3) % MEM_SIZE]);
	return (p->reg[reg]);
}
