/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 11:45:31 by CWatcher          #+#    #+#             */
/*   Updated: 2021/01/28 18:09:29 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

ssize_t	ft_putcn(char c, ssize_t n)
{
	ssize_t	w;
	ssize_t	l;

	l = 0;
	while (n-- > 0)
	{
		w = write(1, &c, sizeof(c));
		if (w < 0)
		{
			l = w;
			break ;
		}
		else
			l += w;
	}
	return (l);
}
