/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 18:59:12 by agaudry           #+#    #+#             */
/*   Updated: 2017/03/03 19:07:20 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_get_len(t_fmt *fmt)
{
	int		len;

	len = 0;
	if (ft_strchr("dDioOuUbBxX", fmt->conv_type) && !(fmt->signednb_arg)
	&& !(fmt->unsignednb_arg) && fmt->precision == 0)
		return (len);
	else if (ft_strchr("dDi", fmt->conv_type))
		len = ft_nb_len(fmt->signednb_arg, 10);
	else if (ft_strchr("uU", fmt->conv_type))
		len = ft_ulnb_len(fmt->unsignednb_arg, 10);
	else if (ft_strchr("oO", fmt->conv_type))
		len = ft_ulnb_len(fmt->unsignednb_arg, 8);
	else if (ft_strchr("bB", fmt->conv_type))
		len = ft_ulnb_len(fmt->unsignednb_arg, 2);
	else if (ft_strchr("xXp", fmt->conv_type))
		len = ft_ulnb_len(fmt->unsignednb_arg, 16);
	else if (ft_strchr("cC", fmt->conv_type))
		len = ft_nb_len(fmt->signednb_arg, 2);
	else if (fmt->conv_type == 's' || fmt->conv_type == 'r')
		len = ft_strlen(fmt->str_arg);
	else if (fmt->conv_type == 'S')
		len = ft_wstrlen(fmt->wstr_arg, fmt->precision);
	else if (fmt->conv_type == 'T')
		len = fmt->style_len;
	return (len);
}

int		ft_get_fmtlen(t_fmt *fmt)
{
	int		fmtlen;

	fmtlen = fmt->arg_len;
	if (ft_strchr("Cc", fmt->conv_type))
		fmtlen = ft_define_count(fmt->arg_len);
	if (fmt->precision > fmt->arg_len
	&& ft_strchr("dDioOuUxXbB", fmt->conv_type))
		fmtlen = fmt->precision;
	if (fmt->precision > -1 && fmt->precision < fmt->arg_len &&
			(ft_strchr("Ssr", fmt->conv_type)))
		fmtlen = fmt->precision;
	if ((fmt->option & SPACE) || (fmt->option & PLUS) || fmt->signednb_arg < 0)
		fmtlen += 1;
	if (((fmt->option & HASH) && ft_strchr("xXbB", fmt->conv_type))
	|| fmt->conv_type == 'p')
		fmtlen += 2;
	if ((fmt->option & HASH) && ft_strchr("oO", fmt->conv_type)
	&& fmt->precision <= fmt->arg_len && fmt->unsignednb_arg)
		fmtlen += 1;
	return (fmtlen);
}
