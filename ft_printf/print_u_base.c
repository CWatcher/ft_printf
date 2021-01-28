/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 00:01:50 by CWatcher          #+#    #+#             */
/*   Updated: 2021/01/28 18:05:16 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "libft.h"
#include "ft_printf_utils.h"

static	ssize_t	max(ssize_t x, ssize_t y)
{
	return (x > y ? x : y);
}

ssize_t			print_u_base(t_frmt *pfrmt, unsigned long long unum, char base)
{
	ssize_t						n;
	char						*s;
	ssize_t						l;

	n = 0;
	s = ft_ulltoa_base(unum, base);
	l = ft_strlen(s);
	if (pfrmt->padd == '0')
		n += ft_puts(pfrmt->sign);
	pfrmt->wdth -= (ft_strlen(pfrmt->sign) + max(l, pfrmt->prec));
	if (!pfrmt->left)
		n += ft_putcn(pfrmt->padd, pfrmt->wdth);
	if (pfrmt->padd != '0')
		n += ft_puts(pfrmt->sign);
	n += ft_putcn('0', pfrmt->prec - l);
	n += ft_puts(s);
	if (pfrmt->left)
		n += ft_putcn(' ', pfrmt->wdth);
	free(s);
	return (n);
}
