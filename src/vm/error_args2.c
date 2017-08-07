/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_args2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 16:01:53 by agaudry           #+#    #+#             */
/*   Updated: 2017/08/01 14:42:39 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	print_usage(void)
{
	ft_printf(
	"Usage: ./corewar [-d N -s N -v N -a] [-n N] <champion1.cor> <...>\n");
	ft_printf(
	"\t-a        : Prints output from \"aff\" (Default is to hide it)\n");
	ft_printf("\t-d N      : Dumps memory after N cycles then exits\n");
	ft_printf(
	"\t-s N      : Runs N cycles, dumps memory, pauses, then repeats\n");
	ft_printf(
	"\t-v N      : Verbosity levels, can be added together\n");
	ft_printf("\t\t   - 0 : Show only essentials\n");
	ft_printf("\t\t   - 1 : Show lives\n");
	ft_printf("\t\t   - 2 : Show cycles\n");
	ft_printf("\t\t   - 4 : Show operations (Params are NOT litteral ...)\n");
	ft_printf("\t\t   - 8 : Show deaths\n");
	ft_printf("\t\t   - 16 : Show PC movements (Except for jumps)\n");
	ft_printf("\t-n  N     : Specify player number\n");
	exit(EXIT_FAILURE);
}

void	invalid_option_error(char *arg)
{
	ft_dprintf(2, "Error: %s is not a valid option\n", arg);
	exit(EXIT_FAILURE);
}

void	invalid_arg_error(char *arg)
{
	ft_dprintf(2, "Can't read source file %s\n", arg);
	exit(EXIT_FAILURE);
}

void	invalid_n_error(void)
{
	ft_dprintf(2,
	"Error: option -n takes a number from 1 to the number of players\n");
	exit(EXIT_FAILURE);
}

void	too_many_champs_error(void)
{
	ft_dprintf(2, "Too many champions\n");
	exit(EXIT_FAILURE);
}
