/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:58:44 by CWatcher          #+#    #+#             */
/*   Updated: 2021/01/28 17:51:34 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_ulltoa_base(unsigned long long int num, unsigned char b)
{
	unsigned long long	n;
	size_t				l;
	char				*s;
	const char			*digits = "0123456789abcdef";

	if (b == 'X')
		digits = "0123456789ABCDEF";
	if (ft_strchr("xXp", b))
		b = 16;
	if (b < 2 || ft_strlen(digits) < b)
		return (NULL);
	l = 1;
	n = num;
	while (n /= b)
		l++;
	if (!(s = malloc((l + 1) * sizeof(char))))
		return (NULL);
	s[0] = '\0';
	s[l] = '\0';
	while (num)
	{
		s[--l] = digits[num % b];
		num /= b;
	}
	return (s);
}
