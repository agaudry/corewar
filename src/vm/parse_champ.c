/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_champ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 16:09:37 by agaudry           #+#    #+#             */
/*   Updated: 2017/07/18 11:43:41 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	get_code(int fd, char *arg, t_champ *champ)
{
	char	buff;

	buff = 0;
	if (read(fd, &champ->code, champ->header->prog_size)
	!= champ->header->prog_size)
		code_size_diff_error(arg);
	if (read(fd, &buff, 1))
		code_size_diff_error(arg);
}

void	get_name_comment_size(int fd, char *arg, t_champ *champ)
{
	unsigned int	size;

	if (read(fd, &champ->header->prog_name, PROG_NAME_LENGTH)
	!= PROG_NAME_LENGTH)
		code_too_small_error(arg);
	lseek(fd, 4, SEEK_CUR);
	if (read(fd, &size, 4) != 4)
		code_too_small_error(arg);
	champ->header->prog_size = ft_swap_bytes(size);
	if (champ->header->prog_size > CHAMP_MAX_SIZE)
		code_too_big_error(arg, champ->header->prog_size);
	if (read(fd, &champ->header->comment, COMMENT_LENGTH) != COMMENT_LENGTH)
		code_too_small_error(arg);
	lseek(fd, 4, SEEK_CUR);
}

void	get_magic_number(int fd, char *arg, t_champ *champ)
{
	unsigned int	magic_nb;

	magic_nb = 0;
	if (read(fd, &magic_nb, 4) != 4)
		invalid_arg_error(arg);
	champ->header->magic = ft_swap_bytes(magic_nb);
	if (champ->header->magic != COREWAR_EXEC_MAGIC)
		invalid_header_error(arg);
}

void	stock_champ(char *arg, t_champ *champ)
{
	int	fd;

	fd = 0;
	if ((fd = open(arg, O_RDONLY)) == -1)
		invalid_arg_error(arg);
	get_magic_number(fd, arg, champ);
	get_name_comment_size(fd, arg, champ);
	get_code(fd, arg, champ);
}

void	get_champ(char *arg, t_list **champs, int n)
{
	t_list	*new;

	if ((*champs)->content == NULL)
	{
		(*champs)->content = (void *)ft_new_champ();
		stock_champ(arg, (*champs)->content);
		set_champ_n((*champs)->content, n);
	}
	else
	{
		new = ft_new_list();
		new->content = (void *)ft_new_champ();
		stock_champ(arg, new->content);
		set_champ_n(new->content, n);
		ft_lstadd(champs, new);
	}
}
