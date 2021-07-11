#include "bsq.h"

int	main(void)
{
	t_map   abc;

	abc.param = (char *)malloc(sizeof(char) * 3);
	printf("ft_mapParser_v2: %d\n",ft_mapParser_v2("test", &abc));
	printf("args = %d %c %c %c\n", abc.n, abc.param[0], abc.param[1], abc.param[2]);
	//printf("ft_is_argum: %d\n", ft_is_argum(abc.param, &abc));			//загрузка и проверка агрументов в стукрутру
	printf("ft_check_symbols: %d\n", ft_check_symbols(&abc, abc.map));	// Проверка актуальных символов
	printf("checkLines: %d\n", checkLines(abc.map, &abc));
	// Освобождаем память после использвания
	free(abc.param);
	return (0);
}
