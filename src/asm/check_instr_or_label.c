/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instr_or_label.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:07:15 by agaudry           #+#    #+#             */
/*   Updated: 2017/08/02 15:23:44 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

char	*ft_is_label(char *str, t_list *file, int size)
{
	int	i;

	i = 0;
	while (str[i] && ft_is_whitespace(str[i]))
		i++;
	if (!(ft_strchr(LABEL_CHARS, str[i])))
		return (NULL);
	while (str[i] && ft_strchr(LABEL_CHARS, str[i]))
		i++;
	if (str[i] == ':'
	&& (ft_str_is_ignored(str + i + 1) || ft_is_instr(str + i + 1, file, size)))
		return (str + i + 1);
	else
		return (NULL);
}

int		ft_is_label_param(char *str)
{
	int	i;

	i = 0;
	if (str[i] != ':')
		return (0);
	i++;
	if (!(ft_strchr(LABEL_CHARS, str[i])))
		return (0);
	while (str[i] && ft_strchr(LABEL_CHARS, str[i]))
		i++;
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}

int		ft_check_arg_comma(char *str, int diff_arg, int *i)
{
	while (str[(*i)] && ft_is_whitespace(str[(*i)]))
		(*i) += 1;
	if (str[(*i)] && diff_arg > 1 && str[(*i)] != ',')
		return (0);
	else if (str[(*i)] && diff_arg == 1 && str[(*i)] == ',')
		return (0);
	else if (str[(*i)])
	{
		if (diff_arg > 1)
			(*i) += 1;
		while (str[(*i)] && ft_is_whitespace(str[(*i)]))
			(*i) += 1;
		return (1);
	}
	return (1);
}

int		ft_check_commas(char *str, int arg_nb)
{
	int	i;
	int	len;
	int	arg;

	i = 0;
	len = 0;
	arg = 0;
	while (str[i] && ft_is_whitespace(str[i]))
		i++;
	while (str[i] && str[i] != ',' && !(ft_is_whitespace(str[i])))
		i++;
	while (str[i] && ft_is_whitespace(str[i]))
		i++;
	if (str[i] == ',')
		return (0);
	while (str[i] && arg < arg_nb)
	{
		while (str[i] && str[i] != ',' && !(ft_is_whitespace(str[i])))
			i++;
		if (str[i] && !(ft_check_arg_comma(str, arg_nb - arg, &i)))
			return (0);
		arg++;
	}
	return (1);
}

int		ft_is_instr(char *str, t_list *file, int size)
{
	char	**split;
	int		instr_nb;
	int		ret;

	ret = 0;
	instr_nb = 0;
	split = ft_split_whitespace_commas(str);
	while (instr_nb < 16
	&& !(ft_strequ(split[0], g_op_tab[instr_nb].instr_name)))
		instr_nb++;
	if (instr_nb == 16)
		ret = 0;
	else if (!(ft_check_commas(str, g_op_tab[instr_nb].arg_nb)))
		ret = 0;
	else if (ft_check_instr_args(g_op_tab[instr_nb].arg_nb,
	g_op_tab[instr_nb].param, split))
	{
		ft_set_ln_idx(file->content, size);
		ret = instr_nb + 1;
	}
	else
		ret = 0;
	ft_dblarray_del((void **)split);
	return (ret);
}
