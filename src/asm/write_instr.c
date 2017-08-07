/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:09:59 by agaudry           #+#    #+#             */
/*   Updated: 2017/07/29 15:40:34 by amichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

char	ft_ocp_arg(char *str)
{
	if (ft_is_reg(str))
		return (REG_CODE);
	else if (ft_is_dir(str))
		return (DIR_CODE);
	else
		return (IND_CODE);
}

void	ft_write_ocp(int fd, int instr_nb, char **split)
{
	int		i;
	char	ocp;

	i = 1;
	ocp = 0;
	if (g_op_tab[instr_nb].ocp)
	{
		while (split[i] && i <= g_op_tab[instr_nb].arg_nb)
		{
			ocp |= (ft_ocp_arg(split[i]) << (8 - (i * 2)));
			i++;
		}
		write(fd, &ocp, 1);
	}
}

void	ft_write_arg(char *arg, int label_sz, t_main *main)
{
	if (ft_is_reg(arg))
		write(main->fd, &(main->arg_fmt->arg_s), 1);
	else if ((ft_is_dir(arg) && !(ft_is_label_param(arg + 1)) && label_sz)
	|| (ft_is_ind(arg) && !(ft_is_label_param(arg))))
		write(main->fd, &(main->arg_fmt->arg_m), 2);
	else if ((ft_is_dir(arg) && !(ft_is_label_param(arg + 1)) && !(label_sz)))
		write(main->fd, &(main->arg_fmt->arg_l), 4);
}

void	ft_arg_fmt(char *arg, int label_sz, t_main *main, t_stockln *ln)
{
	if (ft_is_reg(arg))
		main->arg_fmt->arg_s = (char)ft_atoi(arg + 1);
	else if ((ft_is_dir(arg) && !(ft_is_label_param(arg + 1)) && label_sz))
		main->arg_fmt->arg_m = ft_swap_bytes_short((short int)ft_atoi(arg + 1));
	else if (ft_is_ind(arg) && !(ft_is_label_param(arg)))
		main->arg_fmt->arg_m = ft_swap_bytes_short((short int)ft_atoi(arg));
	else if ((ft_is_dir(arg) && !(ft_is_label_param(arg + 1)) && !(label_sz)))
		main->arg_fmt->arg_l = ft_swap_bytes((int)ft_atoi(arg + 1));
	else if (ft_is_label_param(arg) || ft_is_label_param(arg + 1))
		ft_label_fmt(arg, label_sz, main, ln);
}

void	ft_write_instr(int instr_nb, char *str, t_main *main, t_stockln *ln)
{
	char	**split;
	int		i;

	split = ft_split_whitespace_commas(str);
	write(main->fd, &g_op_tab[instr_nb].opcode, 1);
	ft_write_ocp(main->fd, instr_nb, split);
	i = 1;
	while (split[i] && i <= g_op_tab[instr_nb].arg_nb)
	{
		ft_arg_fmt(split[i], g_op_tab[instr_nb].label_sz, main, ln);
		ft_write_arg(split[i], g_op_tab[instr_nb].label_sz, main);
		i++;
	}
	ft_dblarray_del((void *)split);
}
