/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 18:53:41 by agaudry           #+#    #+#             */
/*   Updated: 2016/11/14 09:19:28 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char const *s1, char const *s2)
{
	int		i;

	i = 0;
	while ((unsigned char)s1[i] == (unsigned char)s2[i] && (unsigned char)s1[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
