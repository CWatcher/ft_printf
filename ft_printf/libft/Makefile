# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: CWatcher <cwatcher@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/15 16:37:00 by CWatcher          #+#    #+#              #
#    Updated: 2021/01/28 18:25:40 by CWatcher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	ft_strlen.c 	\
			ft_strnlen.c 	\
			ft_isdigit.c	\
			ft_putc.c   	\
			ft_putcn.c   	\
			ft_puts.c		\
			ft_putsn.c		\
			ft_strchr.c		\
			ft_ulltoa_base.c
OBJ		= $(SRC:.c=.o)
OBJ_B	= $(SRC_B:.c=.o)
NAME	= libft.a
SO		= libft.so
CC		= clang
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs

$(NAME):	$(OBJ) Makefile
	$(AR) $@ $(OBJ)

all:		$(NAME)

%.o:		%.c libft.h Makefile
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(OBJ) $(OBJ_B)

fclean:		clean
	$(RM) $(NAME) $(SO)

re:			fclean all

bonus:	$(OBJ_B) all
	$(AR) $(NAME) $(OBJ_B)

so:
	$(CC) $(CFLAGS) -fpic -c $(SRC)
	$(CC) -shared -o $(SO) $(OBJ)

.PHONY:		clean fclean re bonus so
