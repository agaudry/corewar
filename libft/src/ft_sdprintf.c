/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:34:48 by agaudry           #+#    #+#             */
/*   Updated: 2017/03/06 10:19:01 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_sprintf(char *str, char const *format, ...)
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
	save->ret[save->i] = '\0';
	ft_strncpy(str, save->ret, save->i + 1);
	va_end(fmt->ap);
	return (ft_exit(fmt, save, save->i));
}

int		ft_dprintf(int fd, char const *format, ...)
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
	write(fd, save->ret, save->i);
	va_end(fmt->ap);
	return (ft_exit(fmt, save, save->i));
}
