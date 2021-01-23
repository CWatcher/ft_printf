PROJ	= ft_printf
LIBA	= $(PROJ)/libftprintf.a
DEFS	= NO_LIBC

all:
	make -C $(PROJ)
	cc -I$(PROJ) -L$(PROJ) -l ftprintf -D $(DEFS) -o aa main.c
