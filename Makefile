# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/01 15:22:53 by agaudry           #+#    #+#              #
#    Updated: 2017/08/07 19:44:15 by agaudry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM_NAME = asm

VM_NAME = corewar

SRC_ASM = 	main_asm.c\
			op.c\
			exit.c\
			exit2.c\
			init_structs.c\
			setters.c\
			getters.c\
			getters2.c\
			predicates.c\
			swap_bytes.c\
			split_whitespace_commas.c\
			get_whole_file.c\
			parsing_header.c\
			check_header.c\
			check_instructions.c\
			check_instr_or_label.c\
			parsing_size.c\
			treat_label_arg.c\
			write_instr.c\
			write_cor.c\
			write_cor2.c\
			atoi_overflow.c

SRC_VM =	main_vm.c\
			init_structs_vm.c\
			error_misc.c\
			error_args.c\
			error_args2.c\
			error_header.c\
			getters_vm.c\
			getters_process.c\
			setters_vm.c\
			parse_args.c\
			parse_champ.c\
			treat_n.c\
			predicates_vm.c\
			swap_bytes.c\
			init_game.c\
			dump.c\
			cycle_manager.c\
			assign_task.c\
			die_hard_process.c\
			op_misc.c\
			op_math.c\
			op_logical.c\
			op_stx.c\
			op_ldx.c\
			op_fork.c\
			op.c\
			verbose.c\
			get_treat_args.c\
			copy_from_to_memory.c\
			check_instr.c\
			swap_bytes.c\

OBJ_ASM_NAME	=	$(SRC_ASM:.c=.o)

OBJ_VM_NAME		=	$(SRC_VM:.c=.o)

SRC_ASM_PATH	=	src/asm/
SRC_VM_PATH		=	src/vm/
LIB_PATH		=	libft/includes/
OBJ_PATH		=	obj/

OBJ_ASM			=	$(addprefix $(OBJ_PATH),$(OBJ_ASM_NAME))
OBJ_VM			=	$(addprefix $(OBJ_PATH),$(OBJ_VM_NAME))
LIB				=	$(addprefix -I,$(LIB_PATH))

CC			=	gcc
CFLAGS		=	-Iincludes -Wall -Wextra -Werror
LDFLAGS		=	-Llibft -lft

all:				$(ASM_NAME) $(VM_NAME)

$(ASM_NAME):		$(OBJ_ASM)
	make -C libft/
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(VM_NAME):			$(OBJ_VM)
	make -C libft/
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(OBJ_PATH)%.o:		$(SRC_ASM_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(LIB) -o $@ -c $<

$(OBJ_PATH)%.o:		$(SRC_VM_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(LIB) -o $@ -c $<

clean:
	rm -fv $(OBJ_VM) $(OBJ_ASM)
	rm -rfv $(OBJ_PATH)
	make clean -C libft/

fclean: clean
	rm -fv $(ASM_NAME) $(VM_NAME)
	make fclean -C libft/

re: fclean all

.PHONY: all, clean, fclean, re
