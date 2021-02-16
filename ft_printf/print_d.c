/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 00:01:50 by CWatcher          #+#    #+#             */
/*   Updated: 2021/01/28 18:41:15 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "libft.h"
#include "ft_printf_utils.h"

static	ssize_t	max(ssize_t x, ssize_t y)
{
	return (x > y ? x : y);
}

ssize_t			print_d(t_fmt *pfmt, long long num)
{
	ssize_t						n;
	const unsigned long long	unum = num < 0 ? -num : num;
	char						*s;
	ssize_t						l;

	n = 0;
	s = ft_ulltoa_base(unum, 10);
	l = ft_strlen(s);
	if (num < 0)
		pfmt->pfx = "-";
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
