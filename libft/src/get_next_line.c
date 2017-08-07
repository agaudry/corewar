/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 14:23:33 by agaudry           #+#    #+#             */
/*   Updated: 2017/07/31 11:45:29 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		*ft_lst_init(t_list **alst, int fd)
{
	t_list	*temp;
	t_list	*lst;

	if (*alst == NULL)
	{
		(*alst) = (t_list *)malloc(sizeof(t_list));
		(*alst)->content = NULL;
		(*alst)->next = NULL;
		(*alst)->content_size = fd;
		return (*alst);
	}
	temp = *alst;
	while (temp)
	{
		if (temp->content_size == (size_t)fd)
			return (temp);
		else
			temp = temp->next;
	}
	lst = (t_list *)malloc(sizeof(t_list));
	lst->content_size = fd;
	lst->content = NULL;
	lst->next = NULL;
	ft_lstback(alst, lst);
	return (lst);
}

static int			ft_extract_content(char **line, t_list *new)
{
	int		i;
	char	*stock;

	i = 0;
	stock = new->content;
	while (stock[i] != '\n')
		i++;
	*line = ft_strsub(stock, 0, i);
	new->content = ft_strsub(stock, i + 1, ft_strlen(stock) - i - 1);
	free(stock);
	return (1);
}

static void			ft_finish_line_n_stock(char **line, char *buf, t_list *new)
{
	int		i;
	char	*tmp;

	i = 0;
	while (buf[i] != '\n')
		i++;
	new->content = ft_strjoinnfree(new->content, ft_strsub(buf, 0, i), 3);
	tmp = new->content;
	*line = ft_strdup(new->content);
	new->content = ft_strsub(buf, i + 1, BUFF_SIZE - i - 1);
	free(tmp);
}

static int			ft_ret_val(int ret, char **line, t_list *new)
{
	if (ret == 0)
	{
		*line = ft_strdup(new->content);
		ft_memdel((void **)&(new->content));
		return (1);
	}
	return (-1);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*new;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	new = ft_lst_init(&list, fd);
	if (new->content && ft_strchr(new->content, '\n'))
		return (ft_extract_content(line, new));
	ret = read(fd, buf, BUFF_SIZE);
	if (new->content && ft_strlen(new->content) && ret == 0)
		return (ft_ret_val(ret, line, new));
	else if (ret == 0 || ret == -1)
		return (ret);
	buf[ret] = '\0';
	while (ft_strchr(buf, '\n') == NULL)
	{
		new->content = ft_strjoinnfree(new->content, ft_strsub(buf, 0, ret), 3);
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		if (ret == 0 || ret == -1)
			return (ft_ret_val(ret, line, new));
	}
	ft_finish_line_n_stock(line, buf, new);
	return (1);
}
