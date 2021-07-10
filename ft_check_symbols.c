#include <stdio.h>
#include "ft_strlen.c"

int	ft_check_symbols(char *s1, char **s2)
{
	int		k;
	int		l;
	int		m;

	m = ft_strlen(s2[0]);
	k = 0;
	l = 0;
	while (k < m)
	{
		l = 0;
		while (s2[k][l] != '\0')
		{
			if (s2[k][l] != s1[0] && s2[k][l] != s1[1] && s2[k][l] != s1[2])
				return (1);
			l++;
		}
		k++;
	}
	return (0);
}
