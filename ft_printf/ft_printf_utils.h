/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 23:26:13 by CWatcher          #+#    #+#             */
/*   Updated: 2021/01/28 01:06:28 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H
# include <sys/types.h>
# include <stdbool.h>
# include <stdarg.h>

typedef struct	s_fmt
{
	ssize_t	wdth;
	ssize_t	prec;
	bool	left;
	char	padd;
	char	sign[2];
}				t_frmt;

void			set_frmt(t_frmt	*pfrmt, char const **ps, va_list *pap);
ssize_t			print_c(t_frmt *pfrmt, int c);
ssize_t			print_s(t_frmt *pfrmt, char *s);
ssize_t			print_d(t_frmt *pfrmt, long long num);

#endif
