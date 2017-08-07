/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predicates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:09:24 by agaudry           #+#    #+#             */
/*   Updated: 2017/07/29 15:39:17 by amichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		ft_str_is_whitespace(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!(ft_is_whitespace(str[i])))
			return (0);
		i++;
	}
	return (1);
}

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

int		ft_str_is_ignored(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		while (str[i] && ft_is_whitespace(str[i]))
			i++;
		if (str[i] == '#' || str[i] == ';' || str[i] == '\0')
			return (1);
		else
			return (0);
		i++;
	}
	return (1);
}
