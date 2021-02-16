/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_frmt_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:04:13 by CWatcher          #+#    #+#             */
/*   Updated: 2021/01/28 18:41:47 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf_utils.h"
#include "libft.h"

void	set_fmt_integer(t_fmt *pfmt, char c)
{
	if (pfmt->prc >= 0)
		pfmt->pad = ' ';
	else
		pfmt->prc = 1;
	if (c == 'p')
		pfmt->pfx = "0x";
}
