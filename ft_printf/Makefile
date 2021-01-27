SRC		= ft_printf.c	\
		  set_frmt.c	\
		  print_c.c		\
		  print_s.c		\
		  print_d.c
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

