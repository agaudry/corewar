/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 20:31:00 by agaudry           #+#    #+#             */
/*   Updated: 2017/07/17 13:55:10 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	invalid_header_error(char *arg)
{
	ft_dprintf(2, "Error: File %s has an invalid header\n", arg);
	exit(EXIT_FAILURE);
}

void	code_too_small_error(char *arg)
{
	ft_dprintf(2, "Error: File %s is too small to be a champion\n", arg);
	exit(EXIT_FAILURE);
}

void	code_too_big_error(char *arg, unsigned int size)
{
	ft_dprintf(2,
	"Error: File %s has too large a code (%d bytes > %d bytes)\n",
	arg, size, CHAMP_MAX_SIZE);
	exit(EXIT_FAILURE);
}

void	code_size_diff_error(char *arg)
{
	ft_dprintf(2,
	"Error: File %s has a code size that differ from what its header says\n",
	arg);
	exit(EXIT_FAILURE);
}
