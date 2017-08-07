/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 19:21:22 by agaudry           #+#    #+#             */
/*   Updated: 2017/07/30 13:01:13 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	introduce_champs(t_list *champs, int nb_players)
{
	t_list	*tmp;
	int		check;

	tmp = champs;
	check = 1;
	ft_printf("Introducing contestants...\n");
	while (check <= nb_players)
	{
		while (tmp)
		{
			if ((get_c_n(tmp) * -1) == check)
			{
				ft_printf(
				"* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
				get_c_n(tmp) * -1,
				get_c_header(tmp)->prog_size,
				get_c_header(tmp)->prog_name,
				get_c_header(tmp)->comment);
				check++;
			}
			tmp = tmp->next;
		}
		tmp = champs;
	}
}

void	init_process(t_champ *champ, t_process *process, int nb_players)
{
	process->owner = champ;
	process->pc = ((champ->n * -1) - 1) * (MEM_SIZE / nb_players);
	process->reg[0] = champ->n;
	process->process_nb = champ->n * -1;
}

void	fill_process(t_champ *champ, t_list **process, int nb_players)
{
	t_list	*new;

	if ((*process)->content == NULL)
	{
		(*process)->content = (void *)ft_new_process();
		init_process(champ, (*process)->content, nb_players);
	}
	else
	{
		new = ft_new_list();
		new->content = (void *)ft_new_process();
		init_process(champ, new->content, nb_players);
		ft_lstadd(process, new);
	}
}

void	setup_process(t_list *champs, t_list **process, int nb_players)
{
	t_list	*tmp;
	int		check;

	check = 1;
	tmp = champs;
	while (check <= nb_players)
	{
		while (tmp)
		{
			if ((get_c_n(tmp) * -1) == check)
			{
				fill_process(tmp->content, process, nb_players);
				check++;
			}
			tmp = tmp->next;
		}
		tmp = champs;
	}
}

void	setup_field(t_env *env)
{
	t_list	*champs;
	int		check;
	int		i;

	champs = env->champs;
	check = 1;
	i = 0;
	introduce_champs(champs, env->nb_players);
	setup_process(champs, &env->process, env->nb_players);
	while (check <= env->nb_players)
	{
		while (champs)
		{
			if ((get_c_n(champs) * -1) == check)
			{
				i = (check - 1) * (MEM_SIZE / env->nb_players);
				ft_memcpy(env->field + i, get_c_code(champs),
				get_c_header(champs)->prog_size);
				check++;
			}
			champs = champs->next;
		}
		champs = env->champs;
	}
}
