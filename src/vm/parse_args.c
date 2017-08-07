/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 16:29:57 by agaudry           #+#    #+#             */
/*   Updated: 2017/08/01 14:54:21 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		is_option(char **argv, int *i, t_env *env)
{
	if (argv[(*i)] && argv[(*i)][1] == 'a' && ft_strlen(argv[(*i)]) == 2)
		env->aff = 1;
	else if (argv[(*i)] && argv[(*i)][1] == 'v' && ft_strlen(argv[(*i)]) == 2
	&& (*i)++ && argv[(*i)] && ft_str_isdigits(argv[(*i)]))
		env->verb = ft_atoi(argv[(*i)]);
	else if (argv[(*i)] && argv[(*i)][1] == 'd' && ft_strlen(argv[(*i)]) == 2
	&& (*i)++ && argv[(*i)] && ft_str_isdigits(argv[(*i)]))
		env->dump = ft_atoi(argv[(*i)]);
	else if (argv[(*i)] && argv[(*i)][1] == 's' && ft_strlen(argv[(*i)]) == 2
	&& (*i)++ && argv[(*i)] && ft_str_isdigits(argv[(*i)]))
		env->step = ft_atoi(argv[(*i)]);
	else
		return (0);
	return (1);
}

void	get_args(int argc, char **argv, t_env *env)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i] && argv[i][0] == '-')
		{
			if (argv[i] && argv[i][1] == 'n' && ft_strlen(argv[i]) == 2)
				treat_n(argv, &i, env);
			else if (!(is_option(argv, &i, env)))
				invalid_option_error(argv[i]);
		}
		else
			get_champ(argv[i], &env->champs, 0);
		i++;
	}
	fill_n_check(env, env->champs);
	env->nb_process = env->nb_players;
	if (env->nb_players < 1)
		print_usage();
}
