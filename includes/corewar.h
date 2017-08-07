/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 15:53:22 by agaudry           #+#    #+#             */
/*   Updated: 2017/08/01 10:18:07 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <fcntl.h>
# include <limits.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <libft.h>
# include <op.h>

typedef struct		s_op
{
	char			*instr_name;
	int				arg_nb;
	int				param[3];
	int				opcode;
	int				cycles;
	char			*instr_detail;
	int				ocp;
	int				label_sz;

}					t_op;

extern t_op			g_op_tab[];

/*
** swap_bytes.c
*/
int					ft_swap_bytes(int i);
short int			ft_swap_bytes_short(int i);

#endif
