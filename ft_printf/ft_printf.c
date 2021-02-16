/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <CWatcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 00:00:44 by CWatcher          #+#    #+#             */
/*   Updated: 2021/02/16 21:32:43 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf_utils.h"

static ssize_t	prn_frmt(t_fmt *pfrmt, char const **ps, va_list *pap)
{
	ssize_t	n;

	if (!ps || !*ps || !**ps)
		return (-1);
	else if (**ps == '%')
		n = print_c(pfrmt, '%');
	else if (**ps == 'c')
		n = print_c(pfrmt, va_arg(*pap, int));
	else if (**ps == 's')
		n = print_s(pfrmt, va_arg(*pap, char *));
	else if (ft_strchr("diuxXp", **ps))
	{
		set_fmt_integer(pfrmt, **ps);
		if (**ps == 'p')
			n = print_u_base(pfrmt, (size_t)va_arg(*pap, void *), **ps);
		else if ((ft_strchr("di", **ps)))
			n = print_d(pfrmt, va_arg(*pap, int));
		else
			n = print_u_base(pfrmt, va_arg(*pap, unsigned), **ps);
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
	ssize_t r;
	t_fmt	frmt;

	n = 0;
	va_start(ap, s);
	while (*s)
		if (*s == '%')
		{
			set_fmt(&frmt, &s, &ap);
			if (0 > (r = prn_frmt(&frmt, &s, &ap)))
			{
				va_end(ap);
				return (-1);
			}
			n += r;
		}
		else
			n += ft_putc(*s++);
	va_end(ap);
	return (n);
}
