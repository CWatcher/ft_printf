#include <stddef.h>
#include <sys/types.h>
#include <stdbool.h>

int	ft_printf(const char *s, ...);

typedef struct	s_fmt
{
	ssize_t	wdth;
	ssize_t	prec;
	bool	left;
	char	padd;
}				t_frmt;

