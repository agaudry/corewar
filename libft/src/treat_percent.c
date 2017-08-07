/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:45:49 by agaudry           #+#    #+#             */
/*   Updated: 2017/02/27 15:12:15 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void		ft_treat_percent(t_fmt *fmt, t_save *save)
{
	if (!(fmt->option & MIN) && (fmt->min_width))
		ft_treat_min_width(fmt, save);
	save->ret[save->i] = '%';
	save->i += 1;
	if ((fmt->option & MIN) && (fmt->min_width))
		ft_treat_min_width(fmt, save);
}
