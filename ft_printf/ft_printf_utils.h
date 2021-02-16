/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CWatcher <cwatcher@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 23:26:13 by CWatcher          #+#    #+#             */
/*   Updated: 2021/01/28 18:44:34 by CWatcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H
# include <sys/types.h>
# include <stdbool.h>
# include <stdarg.h>

typedef struct	s_fmt
{
	ssize_t	wdh;
	ssize_t	prc;
	bool	lft;
	char	pad;
	char	*pfx;
}				t_fmt;

void			set_fmt(t_fmt	*pfmt, char const **ps, va_list *pap);
void			set_fmt_integer(t_fmt *pfmt, char c);
ssize_t			print_c(t_fmt *pfmt, int c);
ssize_t			print_s(t_fmt *pfmt, char *s);
ssize_t			print_d(t_fmt *pfmt, long long num);
ssize_t			print_u_base(t_fmt *pfmt, unsigned long long unum, char base);

#endif
