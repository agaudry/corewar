/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 18:53:41 by agaudry           #+#    #+#             */
/*   Updated: 2017/06/23 14:29:11 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	if (n == 0)
		return (1);
	while ((int)i < (int)n - 1 && s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (s1[i] == s2[i] || s1[i] == 0 || s2[i] == 0)
		return (1);
	else
		return (0);
}
