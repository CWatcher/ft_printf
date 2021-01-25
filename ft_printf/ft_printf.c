#include <unistd.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

t_fmt	fmt0;

void	init_fmt(t_fmt *fmt)
{
//	fmt->wdth = 0;
//	fmt->prec = 0;
	*fmt = fmt0;
	fmt->padd = ' ';
}


int	ft_printf(const char *s, ...)
{
	va_list	ap;
	ssize_t	n;
	ssize_t *pn;
	t_fmt	fmt;

	n = 0;
	init_fmt (&fmt);
	pn = &fmt.wdth;
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == '-')
				fmt.left = true;
			else if (ft_isdigit(*s))
			{
				if (*s == '0' && !*pn)
					fmt.padd = '0';
				*pn = *pn * 10 + (*s - '0');
			}
			else if (*s == '*')
			{	
				fmt.left = va_arg(ap, int) < 0;
				*pn = va_arg(ap, int) < 0 ? -va_arg(ap, int) : va_arg(ap, int);
			}
			else if (*s == 's')
			{	
				ft_putcn(fmt.padd, fmt.wdth - ft_strlen(va_arg(ap, char *)));
				n += ft_putstr(va_arg(ap, char *));
			}
			else if (*s == 'c')
				n += ft_putc(*s);
			s++;
		}
		else
			n += write(1, s++, 1);
	}
	va_end(ap);
	return (n);
}
