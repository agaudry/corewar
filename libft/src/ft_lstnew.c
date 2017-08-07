/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:35:00 by agaudry           #+#    #+#             */
/*   Updated: 2016/11/28 16:17:26 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ret;

	if ((ret = (t_list *)malloc(sizeof(t_list))))
	{
		if (content == NULL)
		{
			ret->content = NULL;
			ret->content_size = 0;
		}
		else
		{
			if ((ret->content = (void *)malloc(sizeof(void) * content_size)))
			{
				ft_memcpy(ret->content, content, content_size);
				ret->content_size = content_size;
			}
			else
			{
				free(ret);
				return (NULL);
			}
		}
		ret->next = NULL;
	}
	return (ret);
}
