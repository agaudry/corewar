/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 16:01:53 by agaudry           #+#    #+#             */
/*   Updated: 2017/07/17 11:34:21 by amichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	n_already_taken_error(int n)
{
	ft_dprintf(2, "Error: player number %d is assigned more than once\n", n);
	exit(EXIT_FAILURE);
}
