//#include "ft_check_symbols.c"
#include "bsq.h"
#include <stdio.h>

int	main(void)
{
	//char	s1[3] = ".ox";
	/*char	*s2[5] = {
		"..o..",
		".....",
		".....",
		".o.o.",
		".o..."
	};*/
    t_map   abc;
    abc.param = (char *)malloc(sizeof(char) * 3);
	char	s3[] = "hh.ox";
    
	//printf("%d", ft_check_symbols(s1, s2)); проверка актуальных символов
	//printf("\n");
    
	printf("%d", ft_is_argum(s3, &abc));
	return (0);
}
