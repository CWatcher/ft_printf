#ifdef LIBC
# include <stdio.h>
#else
# include "ft_printf.h"
#endif

int	 main(int ac, char *av[]) {
	int (*print)(const char *, ...);
	#ifdef LIBC
		print = printf;
		print("================LibC================\n");
	#else
		print = ft_printf;
		print("================LibFT===============\n");
	#endif
	print("ab%s%s%si\n", "cde", "fg", "h");
}
