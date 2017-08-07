/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:45:49 by agaudry           #+#    #+#             */
/*   Updated: 2017/03/06 14:34:47 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void		ft_treat_min_width(t_fmt *fmt, t_save *save)
{
	while ((fmt->min_width - fmt->arg_fmtlen) > 0 && !(fmt->option & ZERO))
	{
		save->ret[save->i] = ' ';
		save->i += 1;
		fmt->min_width -= 1;
	}
	while ((fmt->min_width - fmt->arg_fmtlen) > 0 && (fmt->option & ZERO))
	{
		save->ret[save->i] = '0';
		save->i += 1;
		fmt->min_width -= 1;
	}
}

void		ft_put_option(t_fmt *fmt, t_save *save)
{
	if (fmt->signednb_arg >= 0)
	{
		if (fmt->option & PLUS)
		{
			save->ret[save->i] = '+';
			save->i += 1;
		}
		if (fmt->option & SPACE)
		{
			save->ret[save->i] = ' ';
			save->i += 1;
		}
	}
	else
	{
		save->ret[save->i] = '-';
		save->i += 1;
	}
}

void		ft_put_precision(t_fmt *fmt, t_save *save)
{
	while ((fmt->precision) > fmt->arg_len)
	{
		save->ret[save->i] = '0';
		save->i += 1;
		fmt->precision -= 1;
	}
}

void		ft_put_hash(t_fmt *fmt, t_save *save)
{
	if ((fmt->conv_type == 'x' || fmt->conv_type == 'X' ||
	fmt->conv_type == 'b' || fmt->conv_type == 'B')
	&& (fmt->unsignednb_arg || fmt->signednb_arg))
	{
		save->ret[save->i] = '0';
		save->i += 1;
		save->ret[save->i] = fmt->conv_type;
		save->i += 1;
	}
	if ((fmt->conv_type == 'o' || fmt->conv_type == 'O')
	&& fmt->precision <= fmt->arg_len && fmt->unsignednb_arg)
		save->ret[save->i++] = '0';
	else if ((fmt->conv_type == 'o' || fmt->conv_type == 'O')
	&& fmt->precision == 0)
		save->ret[save->i++] = '0';
	if (fmt->conv_type == 'p')
	{
		save->ret[save->i] = '0';
		save->i += 1;
		save->ret[save->i] = 'x';
		save->i += 1;
	}
}

void		ft_treat_nb(t_fmt *fmt, t_save *save)
{
	char	*conv;

	if (!(fmt->option & MIN) && (fmt->min_width))
		ft_treat_min_width(fmt, save);
	if ((fmt->option & HASH) || (fmt->conv_type == 'p'))
		ft_put_hash(fmt, save);
	if ((fmt->option) || fmt->signednb_arg < 0)
		ft_put_option(fmt, save);
	if (fmt->precision > 0)
		ft_put_precision(fmt, save);
	if (!(fmt->precision) && ft_strchr("dDioOuUxXbB", fmt->conv_type) &&
	fmt->unsignednb_arg == 0 && fmt->signednb_arg == 0)
		;
	else
	{
		conv = ft_conv_nb(fmt);
		if (conv)
			ft_strncpynfree(save->ret + save->i, conv, fmt->arg_len);
	}
	save->i += fmt->arg_len;
	if ((fmt->option & MIN) && (fmt->min_width))
		ft_treat_min_width(fmt, save);
}
