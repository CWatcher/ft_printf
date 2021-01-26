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
	pr("Percent:\n%%%%%%\n");
	pr("Char:\n%c%c%c\n", 'A', 'B', 'C');
	pr("123\n%3c\n", 'c');
	pr("String:\nab%s%s%si\n", "cde", "fg", "h");
	pr("1234\n%4s", "de");

	pr("\n");
}
