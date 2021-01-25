SRC		= ft_printf.c
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

$(LIBA)	:
	make -C $(LIBD)

$(NAME)	: $(OBJ) $(LIBA) Makefile
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

