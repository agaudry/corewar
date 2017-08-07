/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die_hard_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 11:27:03 by agaudry           #+#    #+#             */
/*   Updated: 2017/07/29 12:05:43 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	process_goes_to_heaven(t_list **dying_process)
{
	get_p(*dying_process)->owner = NULL;
	free(get_p(*dying_process));
	(*dying_process)->content = NULL;
	free(*dying_process);
	*dying_process = NULL;
}

void	kill_process(t_env *env, t_list *prev_process, t_list *this_process)
{
	if (env->verb & DEATHS)
		ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
		get_p(this_process)->process_nb,
		get_p(this_process)->last_live,
		env->cycle_to_die);
	if (prev_process)
		prev_process->next = this_process->next;
	else
		env->process = this_process->next;
	process_goes_to_heaven(&this_process);
}
