/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 10:28:48 by agaudry           #+#    #+#             */
/*   Updated: 2017/08/01 10:30:06 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	del_process(void *content, size_t content_size)
{
	if ((t_process *)content)
	{
		((t_process *)content)->owner = NULL;
		free((t_process *)content);
	}
	((t_process *)content)->ft = NULL;
	content_size = 0;
}

void	del_champ(void *content, size_t content_size)
{
	if ((t_champ *)content)
	{
		if (((t_champ *)content)->header)
		{
			free(((t_champ *)content)->header);
			((t_champ *)content)->header = NULL;
		}
		free((t_champ *)content);
	}
	content_size = 0;
}

void	del_env(t_env *env)
{
	if (env->process)
		ft_lstdel(&env->process, del_process);
	if (env->champs)
		ft_lstdel(&env->champs, del_champ);
	if (env->last_heard_of)
	{
		env->last_heard_of->header = NULL;
		free(env->last_heard_of);
	}
	free(env);
}

void	the_winner_is(t_env *env)
{
	if (env->last_heard_of->n == 0)
		ft_printf("Contestant %d, \"%s\", has won !\n",
		get_c_n(env->champs) * -1,
		get_c_header(env->champs)->prog_name);
	else
		ft_printf("Contestant %d, \"%s\", has won !\n",
		env->last_heard_of->n * -1, env->last_heard_of->header->prog_name);
	del_env(env);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		arg_ref;
	t_env	*env;

	fd = 0;
	arg_ref = 1;
	if (argc < 2)
		print_usage();
	env = ft_new_env();
	get_args(argc, argv, env);
	assign_ft(env);
	setup_field(env);
	cycle_manager(env);
	the_winner_is(env);
	return (0);
}
