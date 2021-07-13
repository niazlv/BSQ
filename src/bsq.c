/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:24:14 by ahector           #+#    #+#             */
/*   Updated: 2021/07/13 20:20:32 by ahector          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_start_point(char *str)
{
	t_map	abc;

	abc.param = (char *)malloc(sizeof(char) * 3);
	if (ft_mapParser_v2(str, &abc))
		return (1);
	if (ft_check_symbols(&abc))
		return (2);
	ft_print_struct_map(&abc);
	printf("%d\n",ft_find_square(&abc));
	free(abc.param);
	free(abc.map);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_start_point(argv[i]))
			write(2, "map error\n", 1);
		else
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
