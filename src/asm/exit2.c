/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:07:55 by agaudry           #+#    #+#             */
/*   Updated: 2017/07/13 17:07:59 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	ft_label_error_exit(char *str, int line_nb)
{
	if (ft_is_dir(str))
		ft_dprintf(2,
		"No label called \"%s\" (referenced on line %d)\n", str + 2, line_nb);
	else
		ft_dprintf(2,
		"No label called \"%s\" (referenced on line %d)\n", str + 1, line_nb);
	exit(EXIT_FAILURE);
}

void	ft_file_error_exit(char *str)
{
	ft_dprintf(2, "Can't read source file %s\n", str);
	exit(EXIT_FAILURE);
}
