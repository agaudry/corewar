/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_whole_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:08:03 by agaudry           #+#    #+#             */
/*   Updated: 2017/08/02 17:24:05 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	ft_get_line(char *line, t_list **file)
{
	static int	i;

	(*file) = ft_new_list();
	ft_set_content((*file), (void *)ft_new_stockln());
	ft_set_ln_strnb(ft_get_content_ln(*file), line, i + 1);
	(*file)->content_size = sizeof(t_stockln);
	(*file)->next = NULL;
	i++;
}

t_list	*ft_get_file(int fd, char *name)
{
	t_list		*file;
	t_list		*new;
	char		*line;
	int			ret;

	file = NULL;
	new = NULL;
	ret = 0;
	if ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			ft_file_error_exit(name);
		ft_get_line(line, &file);
	}
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			ft_file_error_exit(name);
		ft_get_line(line, &new);
		ft_lstback(&file, new);
	}
	return (file);
}
