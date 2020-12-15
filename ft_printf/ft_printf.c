#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *s, ...)
{
	int	n;

	n = 0;
	--s;
	while (*++s)
		n += write(STDOUT_FILENO, s, 1);
}
