/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:24:14 by ahector           #+#    #+#             */
/*   Updated: 2021/07/12 14:32:04 by ahector          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_start_point(char *str)
{
	t_map   abc;

	abc.param = (char *)malloc(sizeof(char) * 3);
	if (ft_mapParser_v2(str, &abc))
		return (1);
	//printf("args = %d %c %c %c\n", abc.n, abc.param[0], abc.param[1], abc.param[2]);
	//ft_print_struct_map(&abc);			//Выводит всю карту, которая записана в структуре
	if (ft_check_symbols(&abc))
		return (2);
	// Освобождаем память после использвания
	free(abc.param);

}

int	main(int argc, char *argv[])
{
	unsigned int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_start_point(argv[i]))
			write(1, "map error\n", 1);
		write(1, "\n", 1);
	}
	return (0);
}
