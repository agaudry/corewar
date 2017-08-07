/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:07:49 by agaudry           #+#    #+#             */
/*   Updated: 2017/07/29 17:12:25 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	ft_malloc_error_exit(void)
{
	ft_dprintf(2, "Malloc error\n");
	exit(EXIT_FAILURE);
}

void	ft_header_error_exit(void)
{
	ft_dprintf(2,
	"Error in header: .name and .comment must be declared one time each\n");
	exit(EXIT_FAILURE);
}

void	ft_missing_code_error_exit(void)
{
	ft_dprintf(2, "Champion code is missing\n");
	exit(EXIT_FAILURE);
}

void	ft_syntax_error_exit(int line_nb)
{
	ft_dprintf(2, "Syntax error at line %d\n", line_nb);
	exit(EXIT_FAILURE);
}

void	ft_size_error_exit(int limit)
{
	if (limit == PROG_NAME_LENGTH)
		ft_dprintf(2, "Champion name too long (Max length 128)\n");
	else
		ft_dprintf(2, "Champion comment too long (Max length 2048)\n");
	exit(EXIT_FAILURE);
}
