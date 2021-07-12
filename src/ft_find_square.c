/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:24:03 by ahector           #+#    #+#             */
/*   Updated: 2021/07/12 14:58:58 by ahector          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_while_v2(t_map *abc, unsigned int x0, unsigned int y0)
{
	unsigned int	y;
	unsigned int	x;
	unsigned int	ymax;
	unsigned int	xmax;

	ymax = 0;
	xmax = 0;
	y = y0;
	while (y < abc->n)
	{
		x = x0;
		if (abc->map[(abc->size * y) + x] == abc->param[1])
		{
			ymax = y;
			break;
		}
		while (x < abc->size)
		{
			if (abc->map[(abc->size * y) + x] == abc->param[1])
			{
				xmax = x;
				break;
			}
			x++;
		}
		y++;
	}
	if (ymax > xmax)
		return (xmax * xmax);
	else
		return (ymax * ymax);
}

int	ft_find_square(t_map *abc)
{
	unsigned int	y;
	unsigned int	x;
	unsigned int	max;
	unsigned int	tmp;

	y = 0;
	while (y < abc->n)
	{
		x = 0;
		while (x < abc->size)
		{
			if (abc->map[(abc->size * y) + x] == abc->param[0])
			{
				ft_while_v2(abc, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}
