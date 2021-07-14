/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:24:14 by ahector           #+#    #+#             */
/*   Updated: 2021/07/14 23:03:13 by ahector          ###   ########.fr       */
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
	if (ft_find_square(&abc) < 4)
		return (3);
	ft_print_struct_map(&abc);
	free(abc.param);
	free(abc.map);
	return (0);
}

int	ft_start_input()
{
	t_map	abc;

	abc.param = (char *)malloc(sizeof(char) * 3);
	if (ft_std_input(&abc))
		return (1);
	if (ft_check_symbols(&abc))
		return (2);
	if (ft_find_square(&abc) < 4)
		return (3);
	ft_print_struct_map(&abc);
	free(abc.param);
	free(abc.rawParam);
	free(abc.map);
	return (0);
}

int	main(int argc, char *argv[])
{
	int		i;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			if (ft_start_point(argv[i]))
				write(2, "map error\n", 10);
			else
			{
				if (i < argc - 1)
					write(1, "\n", 1);
			}
			i++;
		}
	}
	else
	{
		if (ft_start_input())
			write(2, "map error\n", 10);
	}
	return (0);
}
