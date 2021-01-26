#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

t_frmt	g_fmt0;

static void	ini_frmt(t_frmt *frmt)
{
	*frmt = g_fmt0;
//	frmt->wdth = 0;
	frmt->prec = -1;
	frmt->padd = ' ';
}

static	void set_flgs(t_frmt *frmt, char const **ps)
{
	while(**ps)
	{
		if (**ps == '-' && frmt->padd != '0')
			frmt->left = true;
		else if (**ps == '0')
		{
			frmt->padd = '0';
			frmt->left = false;
		}
		else
			return;
		(*ps)++;
	}
}

static void set_wdth(t_frmt *frmt, char const **ps, va_list *pap)
{
	int	n;

	if (**ps == '*')
	{
		n = va_arg(*pap, int);
		if (n < 0)
		{
			frmt->left = true;
			frmt->wdth = -n;
		}
		else
		 	frmt->wdth = n;
		++*ps;
	}
	else
		while (ft_isdigit(**ps))
		{
			frmt->wdth = frmt->wdth * 10 + (**ps - '0');
			++*ps;
		}
}

static void set_prec(t_frmt *frmt, char const **ps, va_list *pap)
{
	if(**ps != '.')
		return;
	frmt->prec = 0;
	++*ps;
	if (**ps == '*')
	{
		frmt->prec = va_arg(*pap, int);
		++*ps;
	}
	else
		while(ft_isdigit(**ps))
		{
			frmt->prec = frmt->prec * 10 + (**ps - '0');
			++*ps;
		}
}

void	set_frmt(t_frmt	*pfrmt, char const **ps, va_list *pap)
{
	ini_frmt(pfrmt);
	set_flgs(pfrmt, ps);
	set_wdth(pfrmt, ps, pap);
	set_prec(pfrmt, ps, pap);
}
