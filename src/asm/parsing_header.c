/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_header.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:09:10 by agaudry           #+#    #+#             */
/*   Updated: 2017/08/02 14:19:07 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void		ft_get_name_comment(t_list **file, char *stock, int limit,
t_main *main)
{
	char	*tmp;
	int		stocked_len;
	int		len;

	stocked_len = 0;
	len = 0;
	ft_check_ln_fmt(ft_get_ln_str(*file), ft_get_ln_nb(*file));
	tmp = ft_strchr(ft_get_ln_str(*file), '\"') + 1;
	while (!(ft_strchr(tmp, '\"')) && (*file)->next)
	{
		len = ft_check_len(tmp, stocked_len, limit, 0);
		ft_memcpy(stock + stocked_len, tmp, len);
		*file = (*file)->next;
		stocked_len += len;
		stock[stocked_len - 1] = '\n';
		tmp = ft_get_ln_str(*file);
	}
	if (ft_strchr(tmp, '\"'))
	{
		len = ft_check_len(tmp, stocked_len, limit, 1);
		ft_memcpy(stock + stocked_len, tmp, len);
		ft_check_eol((tmp + len + 1), ft_get_ln_nb(*file));
		if (limit == 2048)
			main->last_header_line = ft_get_ln_nb(*file);
	}
}

void		ft_find_name_comment(t_list **file, t_header *header, t_main *main)
{
	while (*file && !(ft_is_instr(ft_get_ln_str(*file), *file, 0))
	&& !(ft_is_label(ft_get_ln_str(*file), *file, 0)))
	{
		if (ft_str_is_ignored(ft_get_ln_str(*file)))
			;
		else if (ft_strstr(ft_get_ln_str(*file), ".name"))
		{
			if (main->name_check != 0)
				ft_header_error_exit();
			main->name_check += 1;
			ft_get_name_comment(file, header->prog_name, 128, main);
		}
		else if (ft_strstr(ft_get_ln_str(*file), ".comment"))
		{
			if (main->comment_check != 0)
				ft_header_error_exit();
			main->comment_check += 1;
			ft_get_name_comment(file, header->comment, 2048, main);
		}
		else
			ft_syntax_error_exit(ft_get_ln_nb(*file));
		*file = (*file)->next;
	}
	if (main->name_check != 1 || main->comment_check != 1)
		ft_header_error_exit();
}

void		ft_parse_header(t_list *file, t_main *main)
{
	main->header->magic = ft_swap_bytes(COREWAR_EXEC_MAGIC);
	ft_bzero(main->header->prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(main->header->comment, COMMENT_LENGTH + 1);
	ft_find_name_comment(&file, main->header, main);
	main->header->prog_size = ft_swap_bytes(ft_parse_size(&file, main));
}
