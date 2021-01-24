PROJ	= ft_printf
LIBA	= $(PROJ)/libftprintf.a
DEFS	= LIBFT
NAME	= aa

$(NAME)	:
	make -C $(PROJ)
	cc -I$(PROJ) -L$(PROJ) -D $(DEFS) -o aa main.c -lftprintf 

all		: $(NAME) 

clean	:
	make -C $(PROJ) clean

fclean	: clean
	$(RM) $(LIBA)
	$(RM) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re
