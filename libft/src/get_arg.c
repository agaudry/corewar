/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 15:57:52 by agaudry           #+#    #+#             */
/*   Updated: 2017/03/06 14:34:37 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_get_unsignednb(t_fmt *fmt)
{
	if ((fmt->length_modifier & HH) && fmt->conv_type == 'O')
		fmt->unsignednb_arg = va_arg(fmt->ap, int);
	else if ((fmt->length_modifier & HH) && fmt->conv_type != 'U')
		fmt->unsignednb_arg = (unsigned char)va_arg(fmt->ap, int);
	else if ((fmt->length_modifier & H) && fmt->conv_type != 'U')
		fmt->unsignednb_arg = (unsigned short)va_arg(fmt->ap, int);
	else if ((fmt->length_modifier & L) || fmt->conv_type == 'O'
	|| fmt->conv_type == 'U' || fmt->conv_type == 'B'
	|| fmt->length_modifier & LL || fmt->conv_type == 'p')
		fmt->unsignednb_arg = va_arg(fmt->ap, unsigned long);
	else if (fmt->length_modifier & J)
		fmt->unsignednb_arg = (unsigned long)va_arg(fmt->ap, unsigned long);
	else if (fmt->length_modifier & Z)
		fmt->unsignednb_arg = (size_t)va_arg(fmt->ap, ssize_t);
	else
		fmt->unsignednb_arg = (unsigned int)va_arg(fmt->ap, unsigned int);
}

void	ft_get_signednb(t_fmt *fmt)
{
	int			nbr;

	nbr = 0;
	if ((fmt->length_modifier & HH) && fmt->conv_type != 'D')
		fmt->signednb_arg = (char)va_arg(fmt->ap, int);
	else if (fmt->length_modifier & H && fmt->conv_type != 'D')
		fmt->signednb_arg = (short)va_arg(fmt->ap, int);
	else if (fmt->length_modifier & H && fmt->conv_type == 'D')
		fmt->signednb_arg = (unsigned int)va_arg(fmt->ap, unsigned int);
	else if (fmt->length_modifier & LL)
		fmt->signednb_arg = va_arg(fmt->ap, long long);
	else if (fmt->length_modifier & L || fmt->conv_type == 'D')
		fmt->signednb_arg = va_arg(fmt->ap, long);
	else if (fmt->length_modifier & J)
		fmt->signednb_arg = va_arg(fmt->ap, intmax_t);
	else if (fmt->length_modifier & Z)
		fmt->signednb_arg = va_arg(fmt->ap, ssize_t);
	else
	{
		nbr = va_arg(fmt->ap, int);
		fmt->signednb_arg = nbr;
	}
}

void	ft_get_str(t_fmt *fmt)
{
	if (fmt->conv_type == 's' || fmt->conv_type == 'r')
	{
		fmt->str_arg = va_arg(fmt->ap, char *);
		if (fmt->str_arg == NULL)
			fmt->str_arg = NULL_STR;
	}
	if (fmt->conv_type == 'S')
	{
		fmt->wstr_arg = va_arg(fmt->ap, wint_t *);
		if (fmt->wstr_arg == NULL)
		{
			fmt->str_arg = NULL_STR;
			fmt->conv_type = 's';
		}
	}
}

void	ft_get_argnlen(t_fmt *fmt)
{
	if (ft_strchr("oOuUxXbBp", fmt->conv_type))
		ft_get_unsignednb(fmt);
	else if (ft_strchr("dDicC", fmt->conv_type))
		ft_get_signednb(fmt);
	else if (ft_strchr("sSr", fmt->conv_type))
		ft_get_str(fmt);
	else if (fmt->conv_type == '%')
		fmt->signednb_arg = '%';
	if ((fmt->conv_type == 'p' && fmt->unsignednb_arg == 0)
	|| fmt->conv_type == '%')
		fmt->arg_len = 1;
	else
		fmt->arg_len = ft_get_len(fmt);
	fmt->arg_fmtlen = ft_get_fmtlen(fmt);
	if (fmt->min_width > fmt->precision && (fmt->option & ZERO)
	&& fmt->conv_type != '%')
	{
		fmt->precision = fmt->min_width - (fmt->arg_fmtlen - fmt->arg_len);
		fmt->min_width = 0;
	}
	if (fmt->precision > fmt->arg_len && fmt->arg_fmtlen < fmt->precision
	&& ft_strchr("Ssr", fmt->conv_type) == NULL)
		fmt->arg_fmtlen = fmt->precision;
}
