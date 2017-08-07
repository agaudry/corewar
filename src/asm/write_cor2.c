/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_cor2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:09:53 by agaudry           #+#    #+#             */
/*   Updated: 2017/08/02 15:29:57 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	ft_write_cor(t_main *main, char *name)
{
	t_list	*cropped_file;

	ft_parse_header(main->file, main);
	cropped_file = ft_lst_at(main->file, main->last_header_line);
	ft_check_labels(cropped_file, main);
	if ((main->fd =
	open(name, O_CREAT | O_RDWR | O_TRUNC, S_IRWXU | S_IRWXG)) == -1)
	{
		ft_dprintf(2, strerror(errno));
		exit(EXIT_FAILURE);
	}
	ft_write_header(main->fd, main->header);
	ft_write_code(cropped_file, main);
}
