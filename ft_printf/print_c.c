/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 00:01:26 by CWatcher          #+#    #+#             */
/*   Updated: 2021/01/28 01:19:23 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "libft.h"
#include "ft_printf_utils.h"

ssize_t	print_c(t_fmt *pfmt, int c)
{
	ssize_t	n;

	n = 0;
	if (!pfmt->lft)
		n += ft_putcn(pfmt->pad, pfmt->wdh - sizeof(char));
	n += ft_putc(c);
	if (pfmt->lft)
		n += ft_putcn(pfmt->pad, pfmt->wdh - sizeof(char));
	return (n);
}
