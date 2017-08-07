/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 14:27:58 by agaudry           #+#    #+#             */
/*   Updated: 2017/05/26 15:33:48 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_get_fmt(t_fmt *fmt, char *str, int *i)
{
	fmt = ft_struct_init(fmt);
	if (fmt == NULL)
		return (-1);
	if (ft_get_style(fmt, str, i) == -1)
		return (-1);
	ft_get_option(fmt, str, i);
	ft_get_min_width(fmt, str, i);
	ft_get_precision(fmt, str, i);
	ft_get_length_modifier(fmt, str, i);
	if (ft_get_conv_type(fmt, str, i) == -1)
		return (-1);
	return (0);
}

int		ft_treat_arg(t_fmt *fmt, t_save *save, char *str, int *i)
{
	if (ft_get_fmt(fmt, str, i) == -1 || ft_check_fmt(fmt) == -1)
		return (-1);
	ft_equivalence(fmt);
	ft_get_argnlen(fmt);
	if (ft_limits(fmt) == -1)
		return (-1);
	(fmt->min_width < fmt->arg_fmtlen) ?
	(save->ret = ft_reallocme(save->ret, save->i, fmt->arg_fmtlen)) :
	(save->ret = ft_reallocme(save->ret, save->i, fmt->min_width));
	if (save->ret == NULL)
		return (-1);
	if (fmt->conv_type == 'c' || fmt->conv_type == 'C')
		ft_c(fmt, save);
	else if (ft_strchr("sSr", fmt->conv_type))
		ft_str(fmt, save);
	else if (fmt->conv_type == 'T')
		ft_treat_style(fmt, save);
	else if (fmt->conv_type == '%')
		ft_treat_percent(fmt, save);
	else
		ft_treat_nb(fmt, save);
	return (0);
}

int		ft_exit(t_fmt *fmt, t_save *save, int ret)
{
	if (fmt)
		free(fmt);
	if (save->ret)
		free(save->ret);
	if (save)
		free(save);
	return (ret);
}

int		ft_stock(char const *format, t_fmt *fmt, t_save *save)
{
	int start;
	int i;

	i = 0;
	start = 0;
	while (format[i])
	{
		if (format[i] && format[i] == '%')
		{
			++i;
			if (!(format[i])
			|| ft_treat_arg(fmt, save, (char *)format, &i) == -1)
				return (-1);
		}
		if (format[i] && format[i] != '%')
		{
			start = i;
			while (format[i] && format[i] != '%')
				++i;
			save->ret = ft_reallocme(save->ret, save->i, i - start);
			ft_strncpy(save->ret + save->i, format + start, i - start);
			save->i += (i - start);
		}
	}
	return (0);
}

int		ft_printf(char const *format, ...)
{
	t_fmt	*fmt;
	t_save	*save;

	fmt = NULL;
	save = NULL;
	fmt = ft_struct_init(fmt);
	if (fmt == NULL)
		return (ft_exit(fmt, save, -1));
	save = ft_struct_init_save(save);
	if (save == NULL)
		return (ft_exit(fmt, save, -1));
	va_start(fmt->ap, format);
	if (ft_stock(format, fmt, save) == -1)
		return (ft_exit(fmt, save, -1));
	write(1, save->ret, save->i);
	va_end(fmt->ap);
	return (ft_exit(fmt, save, save->i));
}
