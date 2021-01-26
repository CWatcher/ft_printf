#include <unistd.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

t_frmt	g_fmt0;

void	ini_frmt(t_frmt *frmt)
{
	*frmt = g_fmt0;
//	frmt->wdth = 0;
	frmt->prec = -1;
	frmt->padd = ' ';
}

static	void set_flgs(t_frmt *frmt, char const **ps)
{
	while(**ps)
	{
		if (**ps == '-' && frmt->padd != '0')
			frmt->left = true;
		else if (**ps == '0')
		{
			frmt->padd = '0';
			frmt->left = false;
		}
		else
			return;
		(*ps)++;
	}
}

static void set_wdth(t_frmt *frmt, char const **ps, va_list ap)
{
	int	n;

	if (**ps == '*')
	{
		n = va_arg(ap, int);
		if (n < 0)
		{
			frmt->left = true;
			frmt->wdth = -n;
		}
		else
		 	frmt->wdth = n;
		++*ps;
	}
	else while(ft_isdigit(**ps))
	{
		frmt->wdth = frmt->wdth * 10 + (**ps - '0');
		++*ps;
	}
}

static void set_prec(t_frmt *frmt, char const **ps, va_list ap)
{
	if(**ps != '.')
		return;
	++*ps;
	if (**ps == '*')
	{
		frmt->prec = va_arg(ap, int);
		++*ps;
	}
	else while(ft_isdigit(**ps))
	{
		frmt->wdth = frmt->wdth * 10 + (**ps - '0');
		++*ps;
	}
}

static void	set_frmt(t_frmt	*pfrmt, char const **ps, va_list ap)
{
	ini_frmt(pfrmt);
	set_flgs(pfrmt, ps);
	set_wdth(pfrmt, ps, ap);
	set_prec(pfrmt, ps, ap);
}

static ssize_t	prn_frmt(char const **ps, va_list ap)
{
	t_frmt	frmt;
	ssize_t	n;

	if (**ps != '%')
		return (0);
	++*ps;
	set_frmt(&frmt, ps, ap);
	n = 0;
	if (**ps == 's')
	{
		char *s = va_arg(ap, char *);
		n += ft_putcn(frmt.padd, frmt.wdth - ft_strlen(s));
		n += ft_puts(s);
	}
	else if (**ps == 'c')
		n += ft_putc(va_arg(ap, int));
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
		n += prn_frmt(&s, ap);
		n += write(1, s++, 1);
	}
	va_end(ap);
	return (n);
}
