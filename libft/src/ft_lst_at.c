/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:37:20 by agaudry           #+#    #+#             */
/*   Updated: 2017/06/24 16:37:15 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	count;

	count = 0;
	while (begin_list)
	{
		if (count == nbr)
			return (begin_list);
		count++;
		begin_list = begin_list->next;
	}
	return (NULL);
}
