/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinnfree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 09:41:16 by agaudry           #+#    #+#             */
/*   Updated: 2017/06/14 15:41:44 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 0 pour ne rien free
** 1 pour free s1
** 2 pour free s2
** 3 pour free les deux
*/
#include "libft.h"

char	*ft_strjoinnfree(char *s1, char *s2, int xfree)
{
	char	*ret;

	if (!(s1) && s2)
		ret = ft_strdup(s2);
	else if (!(s2) && s1)
		ret = ft_strdup(s1);
	else if (!s1 && !s2)
		ret = NULL;
	else
		ret = ft_strjoin(s1, s2);
	if ((xfree & 1) && s1)
		free(s1);
	if ((xfree & 2) && s2)
		free(s2);
	return (ret);
}
