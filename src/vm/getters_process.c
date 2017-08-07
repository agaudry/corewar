/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 15:31:24 by agaudry           #+#    #+#             */
/*   Updated: 2017/07/19 15:38:22 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

t_process	*get_p(t_list *lst)
{
	return ((t_process *)(lst->content));
}

int			get_p_countdown(t_list *lst)
{
	return (((t_process *)(lst->content))->countdown);
}
