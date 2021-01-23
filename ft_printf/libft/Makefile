# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: CWatcher <cwatcher@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/15 16:37:00 by CWatcher          #+#    #+#              #
#    Updated: 2021/01/23 14:52:22 by CWatcher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= ft_memset.c \
		  ft_strlen.c \
		  ft_putstr.c

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
