/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:08:40 by agaudry           #+#    #+#             */
/*   Updated: 2017/08/02 14:28:19 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int			ft_get_ln_idx(t_list *lst)
{
	if (!lst || !lst->content)
	{
		ft_dprintf(2, "Bad syntax\n");
		exit(EXIT_FAILURE);
	}
	return (((t_stockln *)(lst->content))->idx);
}

char		*ft_get_ln_str(t_list *lst)
{
	if (!lst || !lst->content)
	{
		ft_dprintf(2, "Bad syntax\n");
		exit(EXIT_FAILURE);
	}
	return (((t_stockln *)(lst->content))->line_str);
}
