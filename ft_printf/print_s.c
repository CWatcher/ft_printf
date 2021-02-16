/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 00:01:35 by CWatcher          #+#    #+#             */
/*   Updated: 2021/01/28 20:34:14 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "libft.h"
#include "ft_printf_utils.h"

ssize_t	print_s(t_fmt *pfmt, char *s)
{
	ssize_t	n;
	ssize_t	l;

	if (!s)
		s = "(null)";
	l = ft_strlen(s);
	n = 0;
	if (pfmt->prc < 0 || pfmt->prc > l)
		pfmt->prc = l;
	if (!pfmt->lft)
		n += ft_putcn(pfmt->pad, pfmt->wdh - pfmt->prc);
	n += ft_putsn(s, pfmt->prc);
	if (pfmt->lft)
		n += ft_putcn(pfmt->pad, pfmt->wdh - pfmt->prc);
	return (n);
}
