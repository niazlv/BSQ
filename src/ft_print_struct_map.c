/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_struct_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 21:19:19 by ahector           #+#    #+#             */
/*   Updated: 2021/07/13 21:19:43 by ahector          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_print_struct_map(t_map *abc)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < abc->n)
	{
		j = 0;
		while (j < abc->size)
		{
			write(1, &(abc->map[(abc->size * i) + j]), 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
