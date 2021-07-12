/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:24:03 by ahector           #+#    #+#             */
/*   Updated: 2021/07/12 16:55:16 by ahector          ###   ########.fr       */
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
		if (abc->map[(abc->size * y) + x] == abc->param[1] && ymax < ((y - 1) - y0))
		{
			//ymax = (y - 1) - y0;
			//printf("y=%d, ymax=%d;", y, ymax);
			1+1;
			//break;
		}
		while (x < abc->size)
		{
			if (abc->map[(abc->size * y) + x] == abc->param[1] && xmax < ((x - 1) - x0))
			{
				xmax = x - x0;
				ymax = y - y0;
				//printf("x=%d, xmax=%d; ", x, xmax);
				break;
			}
			x++;
		}
		y++;
	}
	printf("%d %d\n", ymax, xmax);
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

	max = 0;
	y = 0;
	while (y < abc->n)
	{
		x = 0;
		while (x < abc->size)
		{
			if (abc->map[(abc->size * y) + x] == abc->param[0])
			{
				printf("%d %d:\n", y, x);
				tmp = ft_while_v2(abc, x, y);
				if (tmp > max)
					max = tmp;
			}
			x++;
		}
		y++;
	}
	return (max);
}
