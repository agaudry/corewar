/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_vm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichals <amichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 11:03:33 by amichals          #+#    #+#             */
/*   Updated: 2017/07/19 15:35:12 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

t_champ		*get_c(t_list *lst)
{
	return ((t_champ *)(lst->content));
}

t_header	*get_c_header(t_list *lst)
{
	return (((t_champ *)(lst->content))->header);
}

char		*get_c_code(t_list *lst)
{
	return (((t_champ *)(lst->content))->code);
}

int			get_c_n(t_list *lst)
{
	return (((t_champ *)(lst->content))->n);
}
