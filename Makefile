PROJ	= ft_printf
LIBA	= $(PROJ)/libftprintf.a

all: $(LIBA)
	cc -I$(PROJ) -L$(PROJ) -l ftprintf -o aa main.c

$(LIBA):
	make -C $(PROJ)
