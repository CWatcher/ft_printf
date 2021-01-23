PROJ	= ft_printf
LIBA	= $(PROJ)/libftprintf.a
DEFS	= NO_LIBC
NAME	= aa

$(NAME)	:
	make -C $(PROJ)
	cc -I$(PROJ) -L$(PROJ) -l ftprintf -D $(DEFS) -o aa main.c

all		: $(NAME) 

clean	:
	make -C $(PROJ) clean

fclean	: clean
	$(RM) $(LIBA)
	$(RM) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re
