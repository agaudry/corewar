/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_label_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:09:48 by agaudry           #+#    #+#             */
/*   Updated: 2017/07/29 15:39:51 by amichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		ft_match_label(char *arg, t_list *label)
{
	if (ft_is_dir(arg)
	&& ft_strequ(ft_get_lb_name(label), arg + 2))
		return (1);
	if (ft_is_ind(arg)
	&& ft_strequ(ft_get_lb_name(label), arg + 1))
		return (1);
	return (0);
}

void	ft_label_fmt(char *arg, int label_sz, t_main *main, t_stockln *ln)
{
	t_list		*label;

	label = main->label;
	while (label)
	{
		if (ft_match_label(arg, label))
		{
			if (ft_is_dir(arg) && !(label_sz))
			{
				main->arg_fmt->arg_l =
				ft_swap_bytes((int)(ft_get_lb_address(label)) - ln->idx);
				write(main->fd, &(main->arg_fmt->arg_l), 4);
			}
			else
			{
				main->arg_fmt->arg_m =
				ft_swap_bytes_short((short int)(ft_get_lb_address(label)) -
				ln->idx);
				write(main->fd, &(main->arg_fmt->arg_m), 2);
			}
		}
		label = label->next;
	}
}
