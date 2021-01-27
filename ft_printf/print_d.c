#include <sys/types.h>
#include "libft.h"
#include "ft_printf_utils.h"

static inline ssize_t max(ssize_t x, ssize_t y)
{
	return (x > y ? x : y);
}

ssize_t	print_d(t_frmt *pfrmt, long long num)
{
	ssize_t	n;
	const unsigned long long unum = num < 0 ? -num : num;
	char	*s;
	ssize_t l;

	n = 0;
	pfrmt->sign[0] = (num < 0) * '-';
	s = ft_ulltoa_base(unum, 10);
	l = ft_strlen(s);
	if (pfrmt->prec >= 0)
		pfrmt->padd = ' ';
	else
		pfrmt->prec = 1;
	if (!pfrmt->left)
		n += ft_putcn(' ', pfrmt->wdth - (ft_strlen(pfrmt->sign) + max(l, pfrmt->prec)));
	n += ft_puts(pfrmt->sign);
	n += ft_putcn('0', pfrmt->prec - l);
	n += ft_puts(s);
	if (pfrmt->left)
		n += ft_putcn(' ', pfrmt->wdth - (ft_strlen(pfrmt->sign) + max(l, pfrmt->prec)));
	free(s);
	return (n);
}
