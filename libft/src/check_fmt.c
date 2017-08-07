/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 16:24:04 by agaudry           #+#    #+#             */
/*   Updated: 2017/03/06 14:08:49 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_check_fmt(t_fmt *fmt)
{
	if ((fmt->option & HASH) && ft_strchr("sSpdDiuUcCr", fmt->conv_type))
		return (-1);
	if ((fmt->option & ZERO) && ft_strchr("sSpcCr", fmt->conv_type))
		return (-1);
	if (((fmt->option & PLUS) || (fmt->option & SPACE))
	&& !(ft_strchr("dDi", fmt->conv_type)) && fmt->conv_type != '%')
		return (-1);
	if (fmt->precision > -1 && ft_strchr("pcC", fmt->conv_type))
		return (-1);
	if (fmt->conv_type == 'p' && fmt->length_modifier)
		return (-1);
	if (ft_strchr("sSpcCr", fmt->conv_type) && fmt->length_modifier
	&& !(fmt->length_modifier & L))
		return (-1);
	return (0);
}

int		ft_limits(t_fmt *fmt)
{
	if ((fmt->conv_type == 'C' ||
	(fmt->conv_type == 'c' && (fmt->length_modifier & L))) &&
	(fmt->signednb_arg < 0 || fmt->signednb_arg > 1114111))
		return (-1);
	return (0);
}
