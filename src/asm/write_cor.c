/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_cor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:09:53 by agaudry           #+#    #+#             */
/*   Updated: 2017/08/02 14:04:44 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	ft_write_header(int fd, t_header *header)
{
	write(fd, &header->magic, 4);
	write(fd, header->prog_name, PROG_NAME_LENGTH);
	write(fd, "\0\0\0\0", 4);
	write(fd, &header->prog_size, 4);
	write(fd, header->comment, COMMENT_LENGTH);
	write(fd, "\0\0\0\0", 4);
}

int		ft_label_exists(char *arg, t_main *main)
{
	t_list	*label;

	label = main->label;
	while (label && label->content)
	{
		if (ft_is_ind(arg) && ft_strequ(arg + 1, ft_get_lb_name(label)))
			return (1);
		else if (ft_is_dir(arg) && ft_strequ(arg + 2, ft_get_lb_name(label)))
			return (1);
		label = label->next;
	}
	return (0);
}

void	ft_wrong_label(int *i, t_main *main, t_list *file, char **split)
{
	if (((ft_is_ind(split[(*i)]) && ft_is_label_param(split[(*i)]))
	|| (ft_is_dir(split[(*i)]) && ft_is_label_param(split[(*i)] + 1)))
	&& !(ft_label_exists(split[(*i)], main)))
		ft_label_error_exit(split[(*i)], ft_get_ln_nb(file));
	(*i) += 1;
}

void	ft_check_labels(t_list *file, t_main *main)
{
	char	**split;
	int		instr_nb;
	int		i;
	char	*rest;
	char	*file_str;

	rest = NULL;
	split = NULL;
	i = 1;
	while (file)
	{
		file_str = ft_get_ln_str(file);
		if (((rest = ft_is_label(file_str, file, ft_get_ln_idx(file)))
		&& (instr_nb = ft_is_instr(rest, file, ft_get_ln_idx(file))))
		|| (instr_nb = ft_is_instr(file_str, file, ft_get_ln_idx(file))))
		{
			split = ft_split_whitespace_commas(file_str);
			while (split[i] && i <= g_op_tab[instr_nb - 1].arg_nb)
				ft_wrong_label(&i, main, file, split);
			ft_dblarray_del((void **)split);
			i = 1;
		}
		file = file->next;
	}
}

void	ft_write_code(t_list *file, t_main *main)
{
	char	*line;
	char	*rest;
	int		instr_nb;

	line = NULL;
	rest = NULL;
	instr_nb = 0;
	while (file)
	{
		line = ft_get_ln_str(file);
		if ((rest = ft_is_label(line, file, ft_get_ln_idx(file)))
		&& (instr_nb = ft_is_instr(rest, file, ft_get_ln_idx(file))))
			ft_write_instr(instr_nb - 1, rest, main, ft_get_content_ln(file));
		else if ((instr_nb = ft_is_instr(line, file, ft_get_ln_idx(file))))
			ft_write_instr(instr_nb - 1, line, main, ft_get_content_ln(file));
		file = file->next;
	}
}
