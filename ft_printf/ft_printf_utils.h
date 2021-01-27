#include <sys/types.h>
#include <stdbool.h>
#include <stdarg.h>

typedef struct	s_fmt
{
	ssize_t	wdth;
	ssize_t	prec;
	bool	left;
	char	padd;
	char	sign[2];
}				t_frmt;

void	set_frmt(t_frmt	*pfrmt, char const **ps, va_list *pap);
ssize_t	print_d(t_frmt *pfrmt, long long num);
