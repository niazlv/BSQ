#include "bsq.h"
#include <stdio.h>

int	main(void)
{
	char	*s2[] = {
		"..o..",
		".....",
		".....",
		".o.o.",
		".o..."
	};
	char	**str;

	str = malloc(5);
	for (int i=0; i<5;i++)
		str[i] = malloc(9);
	str[0] = "...o....";
	str[1] = "...o....";
	str[2] = "...o....";
	str[3] = "...o....";
	str[4] = "...o....";

	char	s3[] = "5.ox";
	t_map   abc;

	abc.param = (char *)malloc(sizeof(char) * 3);
	printf("ft_is_argum: %d\n", ft_is_argum(s3, &abc));			//загрузка и проверка агрументов в стукрутру
	printf("ft_check_symbols: %d\n", ft_check_symbols(&abc, s2));	// Проверка актуальных символов
	printf("checkLines: %d\n", checkLines(str, &abc));
	// Освобождаем память после использвания
	free(str);
	free(abc.param);
	return (0);
}
