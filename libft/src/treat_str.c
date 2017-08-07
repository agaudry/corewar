/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:11:08 by agaudry           #+#    #+#             */
/*   Updated: 2017/03/03 18:27:56 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char		*ft_strncpy_r(char *dest, char const *src, size_t len)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0' && i < len)
	{
		if ((src[i] >= 0 && src[i] <= 31) || (src[i] == 127))
			dest[i] = '.';
		else
			dest[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char		*ft_wstrncpy(wchar_t *src, int len, t_save *save)
{
	int i;
	int	charlen;
	int	savelen;

	i = 0;
	savelen = 0;
	while (src[i] != '\0' && savelen < len)
	{
		charlen = ft_nb_len(src[i], 2);
		ft_wc(src[i], charlen, save);
		i++;
		savelen += ft_define_count(charlen);
	}
	return (save->ret);
}

void		ft_fill_space(t_fmt *fmt, t_save *save)
{
	save->ret[save->i] = ' ';
	save->i += 1;
	fmt->min_width -= 1;
}

void		ft_str(t_fmt *fmt, t_save *save)
{
	int		len;

	len = fmt->arg_fmtlen;
	while (!(fmt->option & MIN) && (fmt->min_width - len) > 0)
		ft_fill_space(fmt, save);
	if (fmt->conv_type == 's')
	{
		ft_strncpy(save->ret + save->i, fmt->str_arg, len);
		save->i += len;
	}
	else if (fmt->conv_type == 'r')
	{
		ft_strncpy_r(save->ret + save->i, fmt->str_arg, len);
		save->i += len;
	}
	else if (fmt->conv_type == 'S')
		ft_wstrncpy(fmt->wstr_arg, len, save);
	while ((fmt->option & MIN) && (fmt->min_width - len) > 0)
		ft_fill_space(fmt, save);
}
