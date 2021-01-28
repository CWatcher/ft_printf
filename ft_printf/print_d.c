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

ssize_t			print_d(t_frmt *pfrmt, long long num)
{
	ssize_t						n;
	const unsigned long long	unum = num < 0 ? -num : num;
	char						*s;
	ssize_t						l;

	n = 0;
	s = ft_ulltoa_base(unum, 10);
	l = ft_strlen(s);
	if (num < 0)
		pfrmt->prfx = "-";
	if (pfrmt->padd == '0')
		n += ft_puts(pfrmt->prfx);
	pfrmt->wdth -= (ft_strlen(pfrmt->prfx) + max(l, pfrmt->prec));
	if (!pfrmt->left)
		n += ft_putcn(pfrmt->padd, pfrmt->wdth);
	if (pfrmt->padd != '0')
		n += ft_puts(pfrmt->prfx);
	n += ft_putcn('0', pfrmt->prec - l);
	n += ft_puts(s);
	if (pfrmt->left)
		n += ft_putcn(' ', pfrmt->wdth);
	free(s);
	return (n);
}
