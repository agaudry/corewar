/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_style.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 14:11:29 by agaudry           #+#    #+#             */
/*   Updated: 2017/03/02 14:43:26 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void		ft_get_color(t_fmt *fmt, char *str, int *i)
{
	if (ft_strchr("drgybmc", str[*i]))
	{
		fmt->style |= COLOR;
		if (str[*i] == 'd')
			fmt->style |= DARK;
		else if (str[*i] == 'r')
			fmt->style |= RED;
		else if (str[*i] == 'g')
			fmt->style |= GREEN;
		else if (str[*i] == 'y')
			fmt->style |= YELLOW;
		else if (str[*i] == 'b')
			fmt->style |= BLUE;
		else if (str[*i] == 'm')
			fmt->style |= MAGENTA;
		else if (str[*i] == 'c')
			fmt->style |= CYAN;
		(*i)++;
		fmt->style_len += 3;
	}
}

void		ft_get_background(t_fmt *fmt, char *str, int *i)
{
	if (str[*i] && str[*i] == '.')
	{
		(*i)++;
		if (ft_strchr("drgybmc", str[*i]))
		{
			fmt->style |= BACKGROUND;
			if (str[*i] == 'd')
				fmt->style |= (DARK << 12);
			else if (str[*i] == 'r')
				fmt->style |= (RED << 12);
			else if (str[*i] == 'g')
				fmt->style |= (GREEN << 12);
			else if (str[*i] == 'y')
				fmt->style |= (YELLOW << 8);
			else if (str[*i] == 'b')
				fmt->style |= (BLUE << 8);
			else if (str[*i] == 'm')
				fmt->style |= (MAGENTA << 8);
			else if (str[*i] == 'c')
				fmt->style |= (CYAN << 8);
			(*i)++;
			fmt->style_len += 3;
		}
	}
}

void		ft_get_typo(t_fmt *fmt, char *str, int *i)
{
	while (ft_strchr("BIUF", str[*i]))
	{
		fmt->style |= TYPO;
		if (str[*i] == 'B')
			fmt->style |= BOLD;
		else if (str[*i] == 'I')
			fmt->style |= ITALIC;
		else if (str[*i] == 'U')
			fmt->style |= UNDERLINE;
		else if (str[*i] == 'F')
			fmt->style |= FLICKER;
		(*i)++;
	}
	if (fmt->style & BOLD)
		fmt->style_len += 2;
	if (fmt->style & ITALIC)
		fmt->style_len += 2;
	if (fmt->style & UNDERLINE)
		fmt->style_len += 2;
	if (fmt->style & FLICKER)
		fmt->style_len += 2;
}

int			ft_get_style(t_fmt *fmt, char *str, int *i)
{
	if (str[*i] == '[')
	{
		(*i)++;
		if (str[*i] == '0')
		{
			(*i) += 1;
			fmt->style |= RESET_STYLE;
			fmt->style_len += 1;
		}
		ft_get_color(fmt, str, i);
		ft_get_background(fmt, str, i);
		ft_get_typo(fmt, str, i);
		if (str[*i] == ']' && str[(*i) + 1] == 'T')
			(*i) += 1;
		else
			return (-1);
		fmt->style |= 1;
	}
	return (0);
}
