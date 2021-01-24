#include <stddef.h>
#include <stdbool.h>

int	ft_printf(const char *s, ...);

typedef struct	s_fmt
{
	size_t	wdth;
	size_t	prec;
	bool	left;
	char	padd;
}				t_fmt;

