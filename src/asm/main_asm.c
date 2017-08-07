/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_asm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:08:51 by agaudry           #+#    #+#             */
/*   Updated: 2017/08/02 15:58:53 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	ft_del_ln(void *content, size_t content_size)
{
	if (((t_stockln *)content))
	{
		free(((t_stockln *)content)->line_str);
		((t_stockln *)content)->line_nb = 0;
		((t_stockln *)content)->idx = 0;
		free((t_stockln *)content);
	}
	content_size = 0;
}

void	ft_del_lb(void *content, size_t content_size)
{
	if (((t_label *)content))
	{
		free(((t_label *)content)->name);
		((t_label *)content)->address = 0;
		free(((t_label *)content));
	}
	content_size = 0;
}

void	ft_free_all(char *name, t_main *main)
{
	if (name)
		free(name);
	if (main->file)
		ft_lstdel(&main->file, ft_del_ln);
	if (main->header)
		free(main->header);
	if (main->label)
		ft_lstdel(&main->label, ft_del_lb);
	if (main->arg_fmt)
		free(main->arg_fmt);
	free(main);
}

int		main(int argc, char **argv)
{
	static int	fd;
	t_main		*main;
	char		*name;

	name = NULL;
	if (argc > 1)
	{
		if ((fd = open(argv[argc - 1], O_RDONLY)) == -1)
			ft_file_error_exit(argv[argc - 1]);
		main = ft_new_main();
		main->file = ft_get_file(fd, argv[argc - 1]);
		name = ft_strjoinnfree(ft_strsub(argv[argc - 1], 0,
		ft_strlen(argv[argc - 1]) - 2), ".cor", 1);
		ft_write_cor(main, name);
		if (close(fd) == -1 || close(main->fd) == -1)
			return (ft_dprintf(2, strerror(errno)));
		ft_printf("Writing output program to %s\n", name);
		ft_free_all(name, main);
	}
	else
		ft_printf("Usage: ./asm <sourcefile.s>\n");
	return (0);
}
