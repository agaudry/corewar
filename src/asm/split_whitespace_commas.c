/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_whitespace_commas.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:09:37 by agaudry           #+#    #+#             */
/*   Updated: 2017/07/29 15:39:38 by amichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int				ft_is_whitespace_commas(char c)
{
	if (c == ',' || c == ' ' || c == '\n' || c == '\v' || c == '\t' || c == '\r'
	|| c == '\f' || c == '\0')
		return (1);
	else
		return (0);
}

static	int		ft_wrdlen_wc(char const *s)
{
	int i;

	i = 0;
	while (!(ft_is_whitespace_commas(s[i])) && s[i] != '\0')
		i++;
	return (i);
}

size_t			ft_count_wc(char const *s)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (ft_is_whitespace_commas(s[i]) && s[i] != '\0')
			i++;
		if (!(ft_is_whitespace_commas(s[i])) && s[i] != '\0')
			j++;
		while (!(ft_is_whitespace_commas(s[i])) && s[i] != '\0')
			i++;
	}
	return (j);
}

char			**ft_split_whitespace_commas(char const *s)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	nb_len;

	tab = NULL;
	if (s != NULL)
		if ((tab = (char **)ft_memalloc(sizeof(char *) * (ft_count_wc(s) + 1))))
		{
			i = 0;
			j = 0;
			while (j < ft_count_wc(s))
			{
				while (ft_is_whitespace_commas(s[i]) && s[i])
					i++;
				nb_len = ft_wrdlen_wc(s + i);
				tab[j] = ft_strsub(s, i, nb_len);
				i += nb_len;
				j++;
			}
			tab[j] = NULL;
		}
	return (tab);
}
