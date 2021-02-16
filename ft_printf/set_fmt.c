/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fmt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <CWatcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:05:28 by CWatcher          #+#    #+#             */
/*   Updated: 2021/02/16 21:30:13 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf_utils.h"
#include "libft.h"

t_fmt	g_fmt0;

static void	ini_frmt(t_fmt *pfmt)
{
	*pfmt = g_fmt0;
	pfmt->prc = -1;
	pfmt->pad = ' ';
	pfmt->pfx = "";
}

static void	set_flgs(t_fmt *pfmt, char const **ps)
{
	while (*++*ps)
		if (**ps == '-')
		{
			pfmt->lft = true;
			pfmt->pad = ' ';
		}
		else if (**ps == '0' && !pfmt->lft)
			pfmt->pad = '0';
		else
			return ;
}

static void	set_wdth(t_fmt *pfmt, char const **ps, va_list *pap)
{
	int	n;

	if (**ps == '*')
	{
		n = va_arg(*pap, int);
		if (n < 0)
		{
			pfmt->lft = true;
			pfmt->wdh = -n;
		}
		else
			pfmt->wdh = n;
		++*ps;
	}
	else
		while (ft_isdigit(**ps))
		{
			pfmt->wdh = pfmt->wdh * 10 + (**ps - '0');
			++*ps;
		}
}

static void	set_prec(t_fmt *pfmt, char const **ps, va_list *pap)
{
	if (**ps != '.')
		return ;
	pfmt->prc = 0;
	++*ps;
	if (**ps == '*')
	{
		pfmt->prc = va_arg(*pap, int);
		++*ps;
	}
	else
		while (ft_isdigit(**ps))
		{
			pfmt->prc = pfmt->prc * 10 + (**ps - '0');
			++*ps;
		}
}

void		set_fmt(t_fmt *pfrmt, char const **ps, va_list *pap)
{
	ini_frmt(pfrmt);
	set_flgs(pfrmt, ps);
	set_wdth(pfrmt, ps, pap);
	set_prec(pfrmt, ps, pap);
}
