#include <unistd.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf_utils.h"

static ssize_t	prn_frmt(char const **ps, va_list *pap)
{
	t_frmt	frmt;
	ssize_t	n;

	set_frmt(&frmt, ps, pap);
	n = 0;
 	if (**ps == '%')
		n += ft_putc('%');
	else if (**ps == 'c')
	{
		if (!frmt.left)
			n += ft_putcn(frmt.padd, frmt.wdth - sizeof(char));
		n += ft_putc(va_arg(*pap, int));
		if (frmt.left)
			n += ft_putcn(frmt.padd, frmt.wdth - sizeof(char));
	}
	else if (**ps == 's')
	{
		const char *s = va_arg(*pap, char *);
		const ssize_t l = ft_strlen(s);

		if (frmt.prec < 0 || frmt.prec > l)
			frmt.prec = l;
		if (!frmt.left)
			n += ft_putcn(frmt.padd, frmt.wdth - frmt.prec);
		n += ft_putsn(s, frmt.prec);
		if (frmt.left)
			n += ft_putcn(frmt.padd, frmt.wdth - frmt.prec);
	}
	else if (ft_strchr("di", **ps))
		n += print_d(&frmt, va_arg(*pap, int));
	++*ps;
	return (n);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	ssize_t	n;

	n = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%') {
				++s;
				n += prn_frmt(&s, &ap);
		}
		else
			n += ft_putc(*s++);
	}
	va_end(ap);
	return (n);
}
