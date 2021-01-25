#ifdef LIBC
# include <stdio.h>
#else
# include "ft_printf.h"
#endif

int	 main(int ac, char *av[]) {
	int (*pr)(const char *, ...);
	#ifdef LIBC
		pr = printf;
		pr("================LibC================\n");
	#else
		pr = ft_printf;
		pr("================LibFT===============\n");
	#endif
	pr("ab%s%s%si\n", "cde", "fg", "h");
	pr("1234\n%4s", "de");
	pr("\n");
}
