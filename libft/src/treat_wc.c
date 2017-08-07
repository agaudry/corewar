/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_wc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 11:50:20 by agaudry           #+#    #+#             */
/*   Updated: 2017/03/03 18:26:37 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_wstrlen(wchar_t *str, int prec)
{
	int		i;
	int		lenwc;
	int		len;

	i = 0;
	lenwc = 0;
	len = 0;
	while (str[i])
	{
		lenwc = ft_define_count(ft_nb_len(str[i], 2));
		if (lenwc == 0)
			lenwc += 1;
		if (prec == -1 || len + lenwc <= prec)
			len += lenwc;
		else
			return (len);
		i++;
	}
	return (len);
}

int		ft_define_mask(int len)
{
	int mask;

	mask = 0;
	if (len <= 11)
		mask |= TWO;
	else if (len <= 16)
		mask |= THREE;
	else
		mask |= FOUR;
	return (mask);
}

int		ft_define_count(int len)
{
	int count;

	count = 0;
	if (len <= 7)
		count = 1;
	else if (len <= 11)
		count = 2;
	else if (len <= 16)
		count = 3;
	else
		count = 4;
	return (count);
}

int		ft_apply_mask(int nb, int mask, int count)
{
	int curs;
	int count2;
	int add;

	curs = 1;
	count2 = 0;
	add = 0;
	while (count > 0)
	{
		while (count2 < 6)
		{
			if (curs & nb)
				mask |= (curs << add);
			curs = (curs << 1);
			count2++;
		}
		count2 = 0;
		add += 2;
		count--;
	}
	return (mask);
}

void	ft_wc(int nb, int len, t_save *save)
{
	int		mask;
	int		count;
	int		maskednb;

	mask = ft_define_mask(len);
	count = ft_define_count(len);
	if (count > 1)
		maskednb = ft_apply_mask(nb, mask, count);
	else
		maskednb = nb;
	while (count > 0)
	{
		save->ret[save->i] = (unsigned char)(maskednb >> (8 * (count - 1)));
		save->i += 1;
		count--;
	}
}
