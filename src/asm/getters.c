/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:08:09 by agaudry           #+#    #+#             */
/*   Updated: 2017/08/02 14:21:50 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

t_stockln	*ft_get_content_ln(t_list *lst)
{
	if (!lst || !lst->content)
	{
		ft_dprintf(2, "Bad syntax\n");
		exit(EXIT_FAILURE);
	}
	return ((t_stockln *)(lst->content));
}

t_label		*ft_get_content_lb(t_list *lst)
{
	if (!lst || !lst->content)
	{
		ft_dprintf(2, "Bad syntax\n");
		exit(EXIT_FAILURE);
	}
	return ((t_label *)(lst->content));
}

char		*ft_get_lb_name(t_list *lst)
{
	if (!lst || !lst->content)
	{
		ft_dprintf(2, "Bad syntax\n");
		exit(EXIT_FAILURE);
	}
	return (((t_label *)(lst->content))->name);
}

int			ft_get_lb_address(t_list *lst)
{
	if (!lst || !lst->content)
	{
		ft_dprintf(2, "Bad syntax\n");
		exit(EXIT_FAILURE);
	}
	return (((t_label *)(lst->content))->address);
}

int			ft_get_ln_nb(t_list *lst)
{
	if (!lst || !lst->content)
	{
		ft_dprintf(2, "Bad syntax\n");
		exit(EXIT_FAILURE);
	}
	return (((t_stockln *)(lst->content))->line_nb);
}
