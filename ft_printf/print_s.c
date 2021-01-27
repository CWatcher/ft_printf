/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 00:01:35 by CWatcher          #+#    #+#             */
/*   Updated: 2021/01/28 00:53:55 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "libft.h"
#include "ft_printf_utils.h"

ssize_t	print_s(t_frmt *pfrmt, char *s)
{
	ssize_t			n;
	const ssize_t	l = ft_strlen(s);

	n = 0;
	if (pfrmt->prec < 0 || pfrmt->prec > l)
		pfrmt->prec = l;
	if (!pfrmt->left)
		n += ft_putcn(pfrmt->padd, pfrmt->wdth - pfrmt->prec);
	n += ft_putsn(s, pfrmt->prec);
	if (pfrmt->left)
		n += ft_putcn(pfrmt->padd, pfrmt->wdth - pfrmt->prec);
	return (n);
}
