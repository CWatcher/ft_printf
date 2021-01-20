/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 13:40:07 by CWatcher          #+#    #+#             */
/*   Updated: 2021/01/19 08:49:24 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa_base(int num, unsigned char b)
{
	unsigned	n;
	size_t		l;
	char		*s;
	char	digits[] = "0123456789ABCDEF";
 
	if (b < 2 || b > sizeof(digits))
		return (NULL);
	n = num > 0 ? num : -num;
	l = 1 + (n < 0);
	while (n /= b)
		l++;
	if (!(s = malloc((l + 1) * sizeof(char))))
		return (NULL);
	s[l] = '\0';
	if (num < 0)
		s[0] = '-';
	else if (n == 0)
		s[0] = '0';
	while (n)
	{
		s[--l] = digits[n % b - 1];
		n /= b;
	}
	return (s);
}
