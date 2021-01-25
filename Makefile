PROJ	= ft_printf
LIBA	= $(PROJ)/libftprintf.a
DEF		= LIBFT
NAME	= aa

$(NAME)	:
	make -C $(PROJ)
	cc -I$(PROJ) -L$(PROJ) -D $(DEF) -o aa main.c -lftprintf

all		: $(NAME)

clean	:
	make -C $(PROJ) clean

fclean	: clean
	make -C $(PROJ) clean
	$(RM) $(LIBA)
	$(RM) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re
