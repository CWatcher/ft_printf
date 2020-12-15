#include "ft_printf/ft_printf.c"

int	 main(int ac, char *av[]) {
	for (int i = 0; i < ac; i++)
	{
		ft_printf(av[i]);
		ft_printf("\n");
	}
}
