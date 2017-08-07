/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:44:09 by agaudry           #+#    #+#             */
/*   Updated: 2017/03/06 11:36:01 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

t_fmt		*ft_struct_init(t_fmt *fmt)
{
	if (!(fmt))
	{
		fmt = (t_fmt *)malloc(sizeof(t_fmt));
		if (fmt == NULL)
			return (NULL);
	}
	fmt->option = 0;
	fmt->min_width = 0;
	fmt->precision = -1;
	fmt->length_modifier = 0;
	fmt->conv_type = '\0';
	fmt->str_arg = NULL;
	fmt->wstr_arg = NULL;
	fmt->signednb_arg = 0;
	fmt->unsignednb_arg = 0;
	fmt->arg_len = 0;
	fmt->arg_fmtlen = 0;
	fmt->style = 0;
	fmt->style_len = 3;
	return (fmt);
}

t_save		*ft_struct_init_save(t_save *save)
{
	if (save == NULL)
		save = (t_save *)malloc(sizeof(t_save));
	if (save == NULL)
		return (NULL);
	save->i = 0;
	save->ret = NULL;
	return (save);
}

void		ft_fmt_interractions(t_fmt *fmt)
{
	if (fmt->conv_type == '%')
	{
		if (fmt->precision != -1)
			fmt->precision = -1;
		if (fmt->option & HASH)
			fmt->option ^= HASH;
		if (fmt->option & PLUS)
			fmt->option ^= PLUS;
		if (fmt->option & SPACE)
			fmt->option ^= SPACE;
	}
	if ((fmt->option & ZERO) && (fmt->option & MIN))
		fmt->option ^= ZERO;
	if ((fmt->option & SPACE) && (fmt->option & PLUS))
		fmt->option ^= SPACE;
	if (ft_strchr("dDioOuUxXbBp", fmt->conv_type) && fmt->precision > -1
	&& (fmt->option & ZERO))
		fmt->option ^= ZERO;
	if (fmt->precision == -1 && !(ft_strchr("sSr", fmt->conv_type)))
		fmt->precision = 1;
}

t_fmt		*ft_equivalence(t_fmt *fmt)
{
	if (fmt->length_modifier & L)
	{
		if (fmt->conv_type == 's')
			fmt->conv_type = 'S';
		if (fmt->conv_type == 'd')
			fmt->conv_type = 'D';
		if (fmt->conv_type == 'o')
			fmt->conv_type = 'O';
		if (fmt->conv_type == 'c')
			fmt->conv_type = 'C';
		if (fmt->conv_type == 'b')
			fmt->conv_type = 'B';
		if (ft_strchr("SDOCB", fmt->conv_type))
			fmt->length_modifier = 0;
	}
	ft_fmt_interractions(fmt);
	return (fmt);
}

char		*ft_conv_nb(t_fmt *fmt)
{
	char	*str;

	str = NULL;
	if (fmt->conv_type == 'd' || fmt->conv_type == 'D' || fmt->conv_type == 'i')
		str = ft_ltoa_u_conv(fmt->signednb_arg);
	if (fmt->conv_type == 'u' || fmt->conv_type == 'U')
		str = ft_ultoa_base(fmt->unsignednb_arg, "0123456789");
	if (fmt->conv_type == 'o' || fmt->conv_type == 'O')
		str = ft_ultoa_base(fmt->unsignednb_arg, "01234567");
	if (fmt->conv_type == 'x' || fmt->conv_type == 'p')
		str = ft_ultoa_base(fmt->unsignednb_arg, "0123456789abcdef");
	if (fmt->conv_type == 'X')
		str = ft_ultoa_base(fmt->unsignednb_arg, "0123456789ABCDEF");
	if (fmt->conv_type == 'b' || fmt->conv_type == 'B')
		str = ft_ultoa_base(fmt->unsignednb_arg, "01");
	return (str);
}
