# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: CWatcher <CWatcher@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/28 18:13:06 by CWatcher          #+#    #+#              #
#    Updated: 2021/02/16 23:06:02 by CWatcher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= ft_printf.c		\
		  set_fmt.c			\
		  set_fmt_integer.c	\
		  print_c.c			\
		  print_s.c			\
		  print_d.c			\
		  print_u_base.c
OBJ		= $(SRC:.c=.o)
LIB		= ft
LIBD	= lib$(LIB)
LIBA	= $(LIBD)/lib$(LIB).a
LIBH	= $(LIBD)/lib$(LIB).h
NAME	= libftprintf.a
CC		= cc -Wall -Wextra -Werror

all		: $(NAME)

%.o		: %.c ft_printf.h $(LIBH)
	$(CC) -I$(LIBD) -c $<

liba	: force

force	:
	make -C $(LIBD)

$(NAME)	: $(OBJ) liba Makefile
	cp $(LIBA) $@
	ar rcs $@ $(OBJ)

clean	:
	make -C $(LIBD) clean
	$(RM) $(OBJ)

fclean	: clean
	make -C $(LIBD) clean
	$(RM) $(LIBA)
	$(RM) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re

