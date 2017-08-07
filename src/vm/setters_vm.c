/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters_vm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichals <amichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 11:56:25 by amichals          #+#    #+#             */
/*   Updated: 2017/07/20 10:13:14 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

t_champ		*set_champ_n(t_champ *champ, int n)
{
	champ->n = n;
	return (champ);
}

int			reset_p_live(t_list *lst)
{
	((t_process *)(lst->content))->live = 0;
	return (((t_process *)(lst->content))->live);
}
