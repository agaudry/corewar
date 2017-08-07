/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fmt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 13:32:34 by agaudry           #+#    #+#             */
/*   Updated: 2017/03/03 18:36:48 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void		ft_get_option(t_fmt *fmt, char *str, int *i)
{
	while (str[*i] && (str[*i] == '-' || str[*i] == '0' || str[*i] == '#' ||
	str[*i] == '+' || str[*i] == ' '))
	{
		if (str[*i] == '-')
			fmt->option |= MIN;
		if (str[*i] == '0')
			fmt->option |= ZERO;
		if (str[*i] == '#')
			fmt->option |= HASH;
		if (str[*i] == '+')
			fmt->option |= PLUS;
		if (str[*i] == ' ')
			fmt->option |= SPACE;
		(*i) += 1;
	}
}

void		ft_get_min_width(t_fmt *fmt, char *str, int *i)
{
	if (str[*i] && str[*i] == '*')
	{
		fmt->min_width = va_arg(fmt->ap, int);
		(*i) += 1;
		if (fmt->min_width < 0)
		{
			fmt->min_width = -fmt->min_width;
			fmt->option |= MIN;
		}
	}
	else if (str[*i] && (str[*i] >= '0' && str[*i] <= '9'))
	{
		fmt->min_width = ft_atoi(str + *i);
		while (str[*i] && (str[*i] >= '0' && str[*i] <= '9'))
			(*i) += 1;
	}
}

void		ft_get_precision(t_fmt *fmt, char *str, int *i)
{
	if (str[*i] && str[*i] == '.')
	{
		(*i) += 1;
		if (str[*i] && str[*i] == '*')
		{
			fmt->precision = va_arg(fmt->ap, int);
			(*i) += 1;
			if (fmt->precision < 0)
				fmt->precision = -1;
		}
		else if (str[*i] && (str[*i] >= '0' && str[*i] <= '9'))
		{
			fmt->precision = ft_atoi(str + *i);
			while (str[*i] && (str[*i] >= '0' && str[*i] <= '9'))
				(*i) += 1;
		}
		else
			fmt->precision = 0;
	}
}

void		ft_get_length_modifier(t_fmt *fmt, char *str, int *i)
{
	if (str[*i] && (str[*i] == 'h' || str[*i] == 'l' || str[*i] == 'j' ||
	str[*i] == 'z'))
	{
		if (str[*i] == 'h' && str[(*i) + 1] != 'h')
			fmt->length_modifier = H;
		else if (str[*i] == 'h' && str[(*i) + 1] != '\0'
		&& str[(*i) + 1] == 'h')
		{
			fmt->length_modifier = HH;
			(*i) += 1;
		}
		else if (str[*i] == 'l' && str[(*i) + 1] != 'l')
			fmt->length_modifier = L;
		else if (str[*i] == 'l' && str[(*i) + 1] == 'l')
		{
			fmt->length_modifier = LL;
			(*i) += 1;
		}
		else if (str[*i] == 'j')
			fmt->length_modifier = J;
		else if (str[*i] == 'z')
			fmt->length_modifier = Z;
		(*i) += 1;
	}
}

int			ft_get_conv_type(t_fmt *fmt, char *str, int *i)
{
	if (str[*i] && ((ft_strchr("sSpdDioOuUxXcCbBrT", str[*i])
	|| str[*i] == '%')))
	{
		fmt->conv_type = str[*i];
		(*i) += 1;
		return (0);
	}
	return (-1);
}
