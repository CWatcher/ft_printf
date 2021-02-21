# include <stdio.h>
# include "ft_printf.h"
# include "libft/libft.h"

int	 main(/*int ac, char *av[] */) {
	int (*pr)(const char *, ...);
	#ifdef LIBC
		pr = printf;
		pr("================LibC================\n");
	#else
		pr = ft_printf;
		pr("================LibFT===============\n");
	#endif
	int	r;
	int a = 12; int i = 18;
	//r = pr("chmod - w the lib*.txt file and press any key" , 0); pr("| %d\n", r);
	getchar();
//	r = pr(NULL , 0); pr("| %d\n", r);
	r = pr("%p" , 0); pr("| %d\n", r);
	r = pr("%.p" , 0); pr("| %d\n", r);
	r = pr("%.p" , 111111); pr("| %d\n", r);
	r = pr("%0.*p" , 0, 111111); pr("| %d\n", r);
	r = pr("%0*c" , -6, 'Y'); pr("| %d\n", r);
	r = pr("%0*i" , -6, 777); pr("| %d\n", r);
	r = pr("%-0*i", a, i, a, i, a, i, a, i, a, i) ; pr("| %d\n", r);
	r = pr("%7", "254"); pr("| %d\n", r);
	r = pr("%p", "254"); pr("| %d\n", r);
	r = pr("%X", 254); pr("| %d\n", r);
	pr("Percent:\n%%%%%%\n");
	pr("Char:\n%c%c%c\n", 'A', 'B', 'C');
	pr("123\n%3c\n", 'c');
	pr("123\n%*c\n", 3, 'c');
	pr("String:\n%s%s%s\n", "abc", "de", "f");
	pr("%6s\n%*s\n", "1234", 6, "de");
	pr("12\n%.2s\n", "defg");
	pr("%.*s\n", 2, "defg");
	pr("1234\n%4.2s\n", "defg");
	r = pr("Decimal:\n%d%d%03d%04d%-03d", 1, 234, 5, -6, -7); pr("| %d\n", r);
	r = pr("%s", NULL); pr("| %d\n", r);

	pr("\n");
}
