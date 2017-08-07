/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 20:33:22 by agaudry           #+#    #+#             */
/*   Updated: 2017/07/24 19:34:34 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	print_field(unsigned char *field)
{
	int		i;
	int		line_char;

	i = 0;
	line_char = 0;
	while (i < MEM_SIZE)
	{
		if (i == 0)
			ft_printf("0x");
		ft_printf("%#.4x : ", i);
		while (line_char < 64)
		{
			ft_printf("%.2hhx ", field[i]);
			line_char++;
			i++;
		}
		ft_putchar('\n');
		line_char = 0;
	}
}
