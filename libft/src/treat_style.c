/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_style.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:14:57 by agaudry           #+#    #+#             */
/*   Updated: 2017/03/02 16:17:34 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void		ft_write_seq(t_save *save, char *seq)
{
	if (ft_isdigit(save->ret[save->i - 1]))
	{
		save->ret[save->i] = ';';
		save->i += 1;
	}
	save->ret[save->i] = seq[0];
	save->i += 1;
	save->ret[save->i] = seq[1];
	save->i += 1;
}

void		ft_write_color(t_fmt *fmt, t_save *save)
{
	if (fmt->style & DARK)
		ft_write_seq(save, "30");
	else if (fmt->style & RED)
		ft_write_seq(save, "31");
	else if (fmt->style & GREEN)
		ft_write_seq(save, "32");
	else if (fmt->style & YELLOW)
		ft_write_seq(save, "33");
	else if (fmt->style & BLUE)
		ft_write_seq(save, "34");
	else if (fmt->style & MAGENTA)
		ft_write_seq(save, "35");
	else if (fmt->style & CYAN)
		ft_write_seq(save, "36");
}

void		ft_write_background(t_fmt *fmt, t_save *save)
{
	if (fmt->style & (DARK << 12))
		ft_write_seq(save, "40");
	else if (fmt->style & (RED << 12))
		ft_write_seq(save, "41");
	else if (fmt->style & (GREEN << 12))
		ft_write_seq(save, "42");
	else if (fmt->style & (YELLOW << 8))
		ft_write_seq(save, "43");
	else if (fmt->style & (BLUE << 8))
		ft_write_seq(save, "44");
	else if (fmt->style & (MAGENTA << 8))
		ft_write_seq(save, "45");
	else if (fmt->style & (CYAN << 8))
		ft_write_seq(save, "46");
}

void		ft_write_typo(t_fmt *fmt, t_save *save)
{
	if (fmt->style & BOLD)
		ft_write_seq(save, "1;");
	if (fmt->style & ITALIC)
		ft_write_seq(save, "3;");
	if (fmt->style & UNDERLINE)
		ft_write_seq(save, "4;");
	if (fmt->style & FLICKER)
		ft_write_seq(save, "5;");
}

void		ft_treat_style(t_fmt *fmt, t_save *save)
{
	char	*seq;
	int		i;

	i = -1;
	seq = ft_strdup("\033[");
	while (seq[++i] != '\0')
		save->ret[save->i++] = seq[i];
	free(seq);
	if (fmt->style & COLOR)
		ft_write_color(fmt, save);
	if (fmt->style & BACKGROUND)
		ft_write_background(fmt, save);
	if (fmt->style & TYPO)
		ft_write_typo(fmt, save);
	save->ret[save->i] = 'm';
	save->i += 1;
}
