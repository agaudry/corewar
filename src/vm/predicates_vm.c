/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predicates_vm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichals <amichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 14:21:51 by amichals          #+#    #+#             */
/*   Updated: 2017/07/17 14:22:48 by amichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

int		ft_str_isdigits(char *str)
{
	int		i;

	i = 0;
	if (!(str[i]))
		return (0);
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (0);
		i++;
	}
	return (1);
}
