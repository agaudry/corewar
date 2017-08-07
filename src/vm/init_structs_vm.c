/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs_vm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:08:47 by agaudry           #+#    #+#             */
/*   Updated: 2017/07/30 15:02:02 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

t_champ		*ft_new_last_heard_of(void)
{
	t_champ	*champ;

	champ = (t_champ *)malloc(sizeof(t_champ));
	if (!champ)
		ft_malloc_error_exit();
	return (champ);
}

t_champ		*ft_new_champ(void)
{
	t_champ	*champ;

	if ((champ = (t_champ *)malloc(sizeof(t_champ))))
	{
		champ->header = (t_header *)malloc(sizeof(t_header));
		if (champ->header == NULL)
			ft_malloc_error_exit();
		ft_bzero(champ->code, CHAMP_MAX_SIZE);
		champ->n = 0;
	}
	else
		ft_malloc_error_exit();
	return (champ);
}

t_process	*ft_new_process(void)
{
	t_process	*process;
	int			reg_nb;

	reg_nb = -1;
	if ((process = (t_process *)malloc(sizeof(t_process))))
	{
		process->owner = NULL;
		process->process_nb = 0;
		process->last_live = 0;
		process->countdown = 1;
		process->pc = 0;
		process->live = 0;
		while (++reg_nb < REG_NUMBER)
			process->reg[reg_nb] = 0;
		process->carry = 0;
		process->ft = NULL;
	}
	else
		ft_malloc_error_exit();
	return (process);
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

t_env		*ft_new_env(void)
{
	t_env	*env;

	if ((env = (t_env *)malloc(sizeof(t_env))))
	{
		ft_bzero(env->field, MEM_SIZE + 1);
		env->cycle_counter = 0;
		env->nb_players = 0;
		env->nb_process = 0;
		env->champs = ft_new_list();
		env->process = ft_new_list();
		env->last_heard_of = ft_new_last_heard_of();
		env->param_code = 0;
		env->instr_len = 1;
		env->live_nb = 0;
		env->aff = 0;
		env->dump = -1;
		env->step = 0;
		env->verb = 0;
	}
	else
		ft_malloc_error_exit();
	return (env);
}
