/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:58:44 by CWatcher          #+#    #+#             */
/*   Updated: 2021/01/27 13:01:17 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_ulltoa_base(unsigned long long int num, unsigned char b)
{
	unsigned long long	n;
	size_t		l;
	char		*s;
	const char	digits[] = "0123456789abcdef";

	if (b < 2 || sizeof(digits) < b)
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
