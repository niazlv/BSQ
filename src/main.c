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
	char	s3[] = "5.ox";
	t_map   abc;

	abc.param = (char *)malloc(sizeof(char) * 3);
	printf("ft_is_argum: %d\n", ft_is_argum(s3, &abc));			//загрузка и проверка агрументов в стукрутру
	printf("ft_check_symbols: %d\n", ft_check_symbols(&abc, s2));	// Проверка актуальных символов
	printf("checkLines: %d\n", checkLines(s2, &abc));
	// Освобождаем память после использвания
	free(abc.param);
	return (0);
}
