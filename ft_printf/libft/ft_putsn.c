/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:11:54 by CWatcher          #+#    #+#             */
/*   Updated: 2021/01/26 19:19:48 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

ssize_t	ft_putsn(char *s, ssize_t n)
{
	const ssize_t	l = ft_strlen(s);

	if (n >= 0)
		return (write(1, s, n < l ? n : l));
	else
		return (write(1, s, l));
}
