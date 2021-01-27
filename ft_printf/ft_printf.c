/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 00:00:44 by CWatcher          #+#    #+#             */
/*   Updated: 2021/01/28 01:04:48 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		n += print_c(&frmt, va_arg(*pap, int));
	else if (**ps == 's')
		n += print_s(&frmt, va_arg(*pap, char *));
	else if (ft_strchr("di", **ps))
	{
		if (frmt.prec >= 0)
			frmt.padd = ' ';
		else
			frmt.prec = 1;
		n += print_d(&frmt, va_arg(*pap, int));
	}
	else
		return (-1);
	++*ps;
	return (n);
}

int				ft_printf(const char *s, ...)
{
	va_list	ap;
	ssize_t	n;

	n = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%')
		{
			++s;
			n += prn_frmt(&s, &ap);
		}
		else
			n += ft_putc(*s++);
	}
	va_end(ap);
	return (n);
}
