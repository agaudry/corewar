/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichals <amichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 11:47:36 by amichals          #+#    #+#             */
/*   Updated: 2017/07/17 19:58:41 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		champ_n_taken(int n, t_list *champs)
{
	int		q;

	q = 0;
	while (champs)
	{
		if (get_c_n(champs) == n && q == 1)
			return (2);
		else if (get_c_n(champs) == n && q == 0)
			q = 1;
		champs = champs->next;
	}
	return (q);
}

void	assign_champ_n(t_list **tmp, t_list *champs, int nb)
{
	int i;

	i = nb * -1;
	while (i <= -1)
	{
		if (!(champ_n_taken(i, champs)))
		{
			set_champ_n((*tmp)->content, i);
			return ;
		}
		i++;
	}
}

void	fill_n_check(t_env *env, t_list *champs)
{
	t_list	*tmp;

	tmp = champs;
	while (tmp && tmp->content)
	{
		env->nb_players += 1;
		if (env->nb_players > 4)
			too_many_champs_error();
		if (tmp->content && get_c_n(tmp) != 0
		&& (champ_n_taken(get_c_n(tmp), champs)) == 2)
			n_already_taken_error(get_c_n(tmp));
		tmp = tmp->next;
	}
	tmp = champs;
	while (tmp && tmp->content)
	{
		if (tmp->content && get_c_n(tmp) == 0)
			assign_champ_n(&tmp, champs, env->nb_players);
		if (tmp->content && (get_c_n(tmp) * -1) > env->nb_players)
			invalid_n_error();
		tmp = tmp->next;
	}
}

void	treat_n(char **argv, int *i, t_env *env)
{
	if ((*i)++ && argv[(*i)] && ft_strlen(argv[(*i)]) == 1
	&& argv[(*i)][0] >= '1' && argv[(*i)][0] <= '4')
	{
		(*i)++;
		get_champ(argv[(*i)], &env->champs, ft_atoi(argv[(*i) - 1]) * -1);
	}
	else
		invalid_n_error();
}
