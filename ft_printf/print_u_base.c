/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 00:01:50 by CWatcher          #+#    #+#             */
/*   Updated: 2021/01/28 18:42:20 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "libft.h"
#include "ft_printf_utils.h"

static	ssize_t	max(ssize_t x, ssize_t y)
{
	return (x > y ? x : y);
}

ssize_t			print_u_base(t_fmt *pfmt, unsigned long long unum, char base)
{
	ssize_t						n;
	char						*s;
	ssize_t						l;

	n = 0;
	s = ft_ulltoa_base(unum, base);
	l = ft_strlen(s);
	if (pfmt->pad == '0')
		n += ft_puts(pfmt->pfx);
	pfmt->wdh -= (ft_strlen(pfmt->pfx) + max(l, pfmt->prc));
	if (!pfmt->lft)
		n += ft_putcn(pfmt->pad, pfmt->wdh);
	if (pfmt->pad != '0')
		n += ft_puts(pfmt->pfx);
	n += ft_putcn('0', pfmt->prc - l);
	n += ft_puts(s);
	if (pfmt->lft)
		n += ft_putcn(' ', pfmt->wdh);
	free(s);
	return (n);
}
