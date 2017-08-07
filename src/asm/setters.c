/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:09:30 by agaudry           #+#    #+#             */
/*   Updated: 2017/08/02 15:32:51 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

t_list		*ft_set_content(t_list *lst, void *content)
{
	lst->content = content;
	return (lst);
}

t_stockln	*ft_set_ln_strnb(t_stockln *ln, char *content, int i)
{
	int		len;

	if (content && (ft_strchr(content, '#') || ft_strchr(content, '#')))
	{
		len = ft_strclen(content, '#');
		if (len > ft_strclen(content, ';'))
			len = ft_strclen(content, ';');
		ln->line_str = ft_strsub(content, 0, len);
		free(content);
		content = NULL;
	}
	else
		ln->line_str = content;
	ln->line_nb = i;
	return (ln);
}

t_stockln	*ft_set_ln_idx(t_stockln *ln, int idx)
{
	ln->idx = idx;
	return (ln);
}

t_label		*ft_set_label_straddress(t_label *label, char *str, int a)
{
	int		len;
	int		start;

	len = ft_strclen(str, ':');
	start = 0;
	while (str && ft_is_whitespace(str[start]))
		start++;
	label->name = ft_strsub(str, start, len);
	label->address = a;
	return (label);
}
