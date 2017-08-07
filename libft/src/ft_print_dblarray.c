/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dblarray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 17:19:43 by agaudry           #+#    #+#             */
/*   Updated: 2017/06/23 17:22:39 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_dblarray(char **dblarray)
{
	int		i;

	i = 0;
	while (dblarray[i])
	{
		ft_putendl(dblarray[i]);
		i++;
	}
}
