#include <unistd.h>
#include <stdarg.h>
#include "libft.h"

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	ssize_t	n;

	n = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == 's')
				n += ft_putstr(va_arg(ap, char *));
			s++;
		}
		else
			n += write(1, s++, 1);
	}
	va_end(ap);
	return (n);
}
