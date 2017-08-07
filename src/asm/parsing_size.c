/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:09:16 by agaudry           #+#    #+#             */
/*   Updated: 2017/08/02 11:52:58 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static int		ft_label_already_there(t_main *main, char *str)
{
	t_list	*label;
	size_t	len;

	len = 0;
	label = main->label;
	while (label)
	{
		len = ft_strclen(str, ':');
		if (label && label->content && ft_strlen(ft_get_lb_name(label)) > len)
			len = ft_strlen(ft_get_lb_name(label));
		if (label && label->content
		&& ft_strict_strnequ(str, ft_get_lb_name(label), len))
			return (1);
		label = label->next;
	}
	return (0);
}

void			ft_stock_label(t_main *main, t_list **label, char *str, int a)
{
	t_list	*new;

	if (ft_label_already_there(main, str))
		return ;
	if ((*label)->content == NULL)
	{
		ft_set_content((*label), (void *)ft_new_label());
		ft_set_label_straddress(ft_get_content_lb(*label), str, a);
		(*label)->content_size = sizeof(t_label);
		(*label)->next = NULL;
	}
	else
	{
		new = ft_new_list();
		ft_set_content(new, (void *)ft_new_label());
		ft_set_label_straddress(ft_get_content_lb(new), str, a);
		new->content_size = sizeof(t_label);
		new->next = NULL;
		ft_lstback(label, new);
	}
}

int				ft_param_size(int instr_nb, char *str)
{
	if (ft_is_reg(str))
		return (1);
	else if (ft_is_dir(str) && !(g_op_tab[instr_nb].label_sz))
		return (4);
	else
		return (2);
}

int				ft_instr_size(int instr_nb, char *str)
{
	int				i;
	unsigned int	size;
	int				arg_nb;
	char			**split;

	i = 0;
	size = 1 + g_op_tab[instr_nb].ocp;
	arg_nb = g_op_tab[instr_nb].arg_nb;
	split = ft_split_whitespace_commas(str);
	while (i < arg_nb)
	{
		size += ft_param_size(instr_nb, split[i + 1]);
		i++;
	}
	ft_dblarray_del((void **)split);
	return (size);
}

unsigned int	ft_parse_size(t_list **file, t_main *main)
{
	unsigned int	size;
	int				instr_nb;
	char			*rest;

	size = 0;
	instr_nb = 17;
	while (*file)
	{
		if ((*file) && ft_str_is_ignored(ft_get_ln_str(*file)))
			;
		else if ((rest = ft_is_label(ft_get_ln_str(*file), *file, size)))
		{
			ft_stock_label(main, &(main->label), ft_get_ln_str(*file), size);
			if ((instr_nb = ft_is_instr(rest, *file, size)))
				size += ft_instr_size(instr_nb - 1, rest);
		}
		else if ((instr_nb = ft_is_instr(ft_get_ln_str(*file), *file, size)))
			size += ft_instr_size(instr_nb - 1, ft_get_ln_str(*file));
		else
			ft_syntax_error_exit(ft_get_ln_nb(*file));
		*file = (*file)->next;
	}
	if (size == 0 && main->label->content == NULL)
		ft_missing_code_error_exit();
	return (size);
}
