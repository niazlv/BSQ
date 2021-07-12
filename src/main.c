#include "bsq.h"

int	main(void)
{
	t_map   abc;

	abc.param = (char *)malloc(sizeof(char) * 3);
	printf("ft_mapParser_v2: %d\n",ft_mapParser_v2("test", &abc));
	printf("args = %d %c %c %c\n", abc.n, abc.param[0], abc.param[1], abc.param[2]);
	ft_print_struct_map(&abc);			//Выводит всю карту, которая записана в структуре
	printf("ft_check_symbols: %d\n", ft_check_symbols(&abc));	// Проверка актуальных символов
	// Освобождаем память после использвания
	free(abc.param);
	return (0);
}
