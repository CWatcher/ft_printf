#include "ft_printf/ft_printf.c"

int	 main(int ac, char *av[]) {
	for (int i = 0; i < ac; i++) {
		if (i < ac - 1)
			ft_printf(av[i], av[i + 1]);
		else
			ft_printf(av[i]);
		ft_printf("\n");
	}
}
