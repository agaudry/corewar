/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:07:24 by agaudry           #+#    #+#             */
/*   Updated: 2017/07/29 15:37:42 by amichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		ft_is_reg(char *str)
{
	if (str && str[0] == 'r'
	&& ft_str_isdigits(str + 1)
	&& ft_strlen(str + 1) <= 2)
		return (1);
	else
		return (0);
}

int		ft_is_dir(char *str)
{
	if (str && str[0] == '%'
	&& (ft_is_label_param(str + 1)
	|| ft_str_isdigits(str + 1)
	|| ((str[1] == '-' && ft_str_isdigits(str + 2)))))
		return (1);
	else
		return (0);
}

int		ft_is_ind(char *str)
{
	if (str && (ft_is_label_param(str) || ft_str_isdigits(str)
	|| ((str[0] == '-' && ft_str_isdigits(str + 1)))))
		return (1);
	else
		return (0);
}

int		ft_check_param(int param, char *str)
{
	if (param == T_REG && ft_is_reg(str))
		return (1);
	else if (param == T_DIR && ft_is_dir(str))
		return (1);
	else if (param == (T_REG | T_DIR) && (ft_is_reg(str) || ft_is_dir(str)))
		return (1);
	else if (param == T_IND && ft_is_ind(str))
		return (1);
	else if (param == (T_REG | T_IND) && (ft_is_reg(str) || ft_is_ind(str)))
		return (1);
	else if (param == (T_DIR | T_IND) && (ft_is_dir(str) || ft_is_ind(str)))
		return (1);
	else if (param == (T_REG | T_DIR | T_IND)
	&& (ft_is_reg(str) || ft_is_dir(str) || ft_is_ind(str)))
		return (1);
	else
		return (0);
}

int		ft_check_instr_args(int arg_nb, int *param, char **split)
{
	int		i;

	i = 0;
	while (i < arg_nb)
	{
		if (!(ft_check_param(param[i], split[i + 1])))
			return (0);
		i++;
	}
	if (split[i + 1] && !(ft_str_is_ignored(split[i + 1])))
		return (0);
	return (1);
}
