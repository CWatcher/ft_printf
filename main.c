#ifdef LIBC
# include <stdio.h>
#else
# include "ft_printf.h"
# include "libft/libft.h"
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
	pr("123\n%*c\n", 3, 'c');
	pr("String:\nab%s%s%si\n", "cde", "fg", "h");
	pr("%6s\n%*s\n", "1234", 6, "de");

	pr("\n");
}
