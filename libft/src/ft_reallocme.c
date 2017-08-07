/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reallocme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 16:43:54 by agaudry           #+#    #+#             */
/*   Updated: 2017/02/17 18:23:49 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_reallocme(void *str, size_t size, size_t addsize)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * (size + addsize));
	if (ret == NULL)
		return (NULL);
	ret = ft_memcpy(ret, str, size);
	free(str);
	return (ret);
}
