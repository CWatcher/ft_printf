/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fmt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:05:28 by CWatcher          #+#    #+#             */
/*   Updated: 2021/02/20 20:47:52 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf_utils.h"
#include "libft.h"

static void	set_flg(t_fmt *pfmt, char const **ps)
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

static void	set_wdh(t_fmt *pfmt, char const **ps, va_list *pap)
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

static void	set_prc(t_fmt *pfmt, char const **ps, va_list *pap)
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

void		set_fmt(t_fmt *pfmt, char const **ps, va_list *pap)
{
	static const t_fmt	fmt0 = {.prc = -1, .pad = ' ', .pfx = ""};

	*pfmt = fmt0;
	set_flg(pfmt, ps);
	set_wdh(pfmt, ps, pap);
	set_prc(pfmt, ps, pap);
}
