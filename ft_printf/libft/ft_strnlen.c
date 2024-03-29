/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:47:45 by cwatcher          #+#    #+#             */
/*   Updated: 2021/01/28 18:10:40 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

ssize_t	ft_strnlen(const char *s, ssize_t n)
{
	ssize_t l;

	l = 0;
	if (n >= 0)
		while (s && s[l] && l < n)
			++l;
	else
		while (s && s[l])
			++l;
	return (l);
}
