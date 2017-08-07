/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:11:33 by agaudry           #+#    #+#             */
/*   Updated: 2017/03/03 18:33:57 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_nb_len(long long value, long long base)
{
	int len;

	len = 0;
	if (value == (-9223372036854775807 - 1))
		return (19);
	if (value < 0)
		value = -value;
	while (value >= base)
	{
		value = value / base;
		len++;
	}
	len++;
	return (len);
}

int		ft_ulnb_len(unsigned long long value, unsigned long long base)
{
	int len;

	len = 0;
	while (value >= base)
	{
		value = value / base;
		len++;
	}
	len++;
	return (len);
}

void	ft_c(t_fmt *fmt, t_save *save)
{
	int		len;

	len = fmt->arg_fmtlen;
	while (!(fmt->option & MIN) && fmt->min_width - len > 0)
	{
		save->ret[save->i] = ' ';
		save->i += 1;
		fmt->min_width -= 1;
	}
	if (fmt->conv_type == 'c')
	{
		save->ret[save->i] = (char)fmt->signednb_arg;
		save->i += 1;
	}
	else
		ft_wc(fmt->signednb_arg, fmt->arg_len, save);
	while ((fmt->option & MIN) && fmt->min_width - len > 0)
	{
		save->ret[save->i] = ' ';
		save->i += 1;
		fmt->min_width -= 1;
	}
}
