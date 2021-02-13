SRC		= main.c
PROJ	= ft_printf
LIBA	= $(PROJ)/libftprintf.a
DEF		= LIBFT
NAME	= aa

$(NAME)	: $(SRC) liba
	cc -Wall -Wextra -Werror -I$(PROJ) -L$(PROJ) -D $(DEF) -o aa main.c -lftprintf -g

liba	: force

force	:
	make -C $(PROJ)

all		: $(NAME)

clean	:
	make -C $(PROJ) clean

fclean	: clean
	make -C $(PROJ) clean
	$(RM) $(LIBA)
	$(RM) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re liba
