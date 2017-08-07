# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 11:30:02 by agaudry           #+#    #+#              #
#    Updated: 2017/08/07 18:45:12 by agaudry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_NAME = 	ft_printf.c\
			ft_sdprintf.c\
			struct_init.c\
			get_fmt.c\
			check_fmt.c\
			get_len.c\
			get_arg.c\
			treat_c.c\
			treat_percent.c\
			treat_nb.c\
			treat_str.c\
			treat_wc.c\
			get_style.c\
			treat_style.c\
			ft_abs.c\
			ft_atoi.c\
			ft_itoa.c\
			ft_itoa_base.c\
			ft_itoa_u_conv.c\
			ft_uitoa_base.c\
			ft_ltoa_u_conv.c\
			ft_ltoa_base_u_conv.c\
			ft_ultoa_base.c\
			ft_bzero.c\
			ft_dblarray_del.c\
			ft_isalpha.c\
			ft_isalnum.c\
			ft_isdigit.c\
			ft_isascii.c\
			ft_isprint.c\
			ft_is_whitespace.c\
			ft_memalloc.c\
			ft_memdel.c\
			ft_memset.c\
			ft_memcpy.c\
			ft_memccpy.c\
			ft_memmove.c\
			ft_memcmp.c\
			ft_memchr.c\
			ft_print_dblarray.c\
			ft_putchar.c\
			ft_putchar_fd.c\
			ft_putendl.c\
			ft_putendl_fd.c\
			ft_putnbr.c\
			ft_putnbr_fd.c\
			ft_putstr.c\
			ft_putstr_fd.c\
			ft_reallocme.c\
			ft_split_whitespace.c\
			ft_strcat.c\
			ft_strncat.c\
			ft_strlcat.c\
			ft_strchr.c\
			ft_strrchr.c\
			ft_strcmp.c\
			ft_strncmp.c\
			ft_strcpy.c\
			ft_strdup.c\
			ft_strequ.c\
			ft_strnequ.c\
			ft_strict_strnequ.c\
			ft_strsub.c\
			ft_strjoin.c\
			ft_strjoinnfree.c\
			ft_strtrim.c\
			ft_strsplit.c\
			ft_strlen.c\
			ft_strclen.c\
			ft_strncpy.c\
			ft_strncpynfree.c\
			ft_strstr.c\
			ft_strnstr.c\
			ft_strnew.c\
			ft_strdel.c\
			ft_strclr.c\
			ft_striter.c\
			ft_striteri.c\
			ft_strmap.c\
			ft_strmapi.c\
			ft_toupper.c\
			ft_tolower.c\
			ft_lstnew.c\
			ft_lstadd.c\
			ft_lstiter.c\
			ft_lstdelone.c\
			ft_lstdel.c\
			ft_lstmap.c\
			ft_lstback.c\
			ft_lst_at.c\
			ft_lst_size.c\
			ft_tablen.c\
			get_next_line.c\

OBJ_NAME	= $(SRC_NAME:.c=.o)

OBJ_PATH	= ./obj/
OBJ			= $(addprefix $(OBJ_PATH),$(OBJ_NAME))

SRC_PATH	= ./src/

INCLUDES = ./includes

CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	gcc $(CFLAGS) -I $(INCLUDES) -c -o $@ $<

clean :
	rm -rf $(OBJ_PATH)

fclean : clean
	rm -f $(NAME)

re : fclean all
