/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 12:40:24 by agaudry           #+#    #+#             */
/*   Updated: 2017/02/17 18:24:19 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ret;
	size_t	i;

	i = 0;
	ret = (void *)malloc(sizeof(void *) * size);
	if (ret == NULL)
		return (NULL);
	while (i < size)
	{
		((char *)ret)[i] = 0;
		i++;
	}
	return (ret);
}
