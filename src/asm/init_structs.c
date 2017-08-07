/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:08:47 by agaudry           #+#    #+#             */
/*   Updated: 2017/08/02 12:08:46 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

t_stockln	*ft_new_stockln(void)
{
	t_stockln	*ln;

	if ((ln = (t_stockln *)malloc(sizeof(t_stockln))))
	{
		ln->line_str = NULL;
		ln->line_nb = 0;
		ln->idx = 0;
	}
	else
		ft_malloc_error_exit();
	return (ln);
}

t_label		*ft_new_label(void)
{
	t_label	*label;

	if ((label = (t_label *)malloc(sizeof(t_label))))
	{
		label->name = NULL;
		label->address = 0;
	}
	else
		ft_malloc_error_exit();
	return (label);
}

t_list		*ft_new_list(void)
{
	t_list	*lst;

	if ((lst = (t_list *)malloc(sizeof(t_list))))
	{
		lst->content = NULL;
		lst->content_size = 0;
		lst->next = NULL;
	}
	else
		ft_malloc_error_exit();
	return (lst);
}

t_arg		*ft_new_arg(void)
{
	t_arg	*arg;

	if ((arg = (t_arg *)malloc(sizeof(t_arg))))
	{
		arg->arg_s = 0;
		arg->arg_m = 0;
		arg->arg_l = 0;
	}
	else
		ft_malloc_error_exit();
	return (arg);
}

t_main		*ft_new_main(void)
{
	t_main	*main;

	if ((main = (t_main *)malloc(sizeof(t_main))))
	{
		main->fd = 0;
		main->last_header_line = 0;
		main->name_check = 0;
		main->comment_check = 0;
		main->file = NULL;
		main->label = ft_new_list();
		main->arg_fmt = ft_new_arg();
		main->header = (t_header *)malloc(sizeof(t_header));
		if (main->header == NULL)
			ft_malloc_error_exit();
	}
	else
		ft_malloc_error_exit();
	return (main);
}
