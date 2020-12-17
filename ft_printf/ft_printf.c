#include <unistd.h>
#include <stdarg.h>
#include "libft.h"

int	ft_printf(const char *s, ...)
{
	int		n;
	va_list	ap;

	n = 0;
	va_start(ap, s);
	--s;
	while (*++s && *s != '%')
		n += write(STDOUT_FILENO, s, 1);
	if (*s == '%' && *++s == 's')
		ft_putstr_fd(va_arg(ap, char *), STDOUT_FILENO);
	va_end(ap);
	return (n);
}
