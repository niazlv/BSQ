#include "bsq.h"

int	ft_is_argum(char *str, t_map *abc)
{
	int		k;
	int		n;
    int     i;

	n = 0;
	k = ft_strlen(str);
	if (k > 3)
	{
        abc->param[0] = str[k - 3];
        abc->param[1] = str[k - 2];
        abc->param[2] = str[k - 1];
        k = k - 4;
	}
    i = 0;
	while (i <= k)
	{
		if (str[i] >= '0' && str[i] <= '9')
			n = n * 10 + (str[i] - 48);
		else
			return (1);
        i++;
	}
    abc->n = n;
	return (0);
}
