/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:07:04 by agaudry           #+#    #+#             */
/*   Updated: 2017/07/29 16:09:48 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	ft_check_eol(char *str, int line_nb)
{
	if (str && !(ft_str_is_ignored(str)))
		ft_syntax_error_exit(line_nb);
}

int		ft_check_len(char *tmp, int stockd_len, int limit, int final)
{
	int len;

	if (final)
		len = ft_strclen(tmp, '\"');
	else
		len = ft_strlen(tmp) + 1;
	if (stockd_len + len >= limit + 1)
		ft_size_error_exit(limit);
	return (len);
}

void	ft_check_ln_fmt(char *str, int line_nb)
{
	char	*unwanted_char;
	char	*quote;
	int		i;

	i = 0;
	while (str[i] && ft_is_whitespace(str[i]))
		i++;
	if (ft_strnequ(str + i, ".name", 5))
		i += 5;
	else if (ft_strnequ(str + i, ".comment", 8))
		i += 8;
	while (str[i] && ft_is_whitespace(str[i]))
		i++;
	quote = ft_strchr(str, '\"');
	unwanted_char = str + i;
	if ((unwanted_char && (unwanted_char < quote)) || !quote)
		ft_syntax_error_exit(line_nb);
}
