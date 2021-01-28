/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_frmt_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:04:13 by CWatcher          #+#    #+#             */
/*   Updated: 2021/01/28 18:06:36 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf_utils.h"
#include "libft.h"

void	set_frmt_integer(t_frmt *pfrmt)
{
	if (pfrmt->prec >= 0)
		pfrmt->padd = ' ';
	else
		pfrmt->prec = 1;
}
