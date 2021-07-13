/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 20:23:04 by ahector           #+#    #+#             */
/*   Updated: 2021/07/13 21:17:17 by ahector          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_replace(t_map *abc, unsigned int x, unsigned int y, \
		unsigned int side_len)
{
	unsigned int	x0;
	unsigned int	y0;

	y0 = y;
	while (y0 <= y + side_len)
	{
		x0 = x;
		while (x0 <= x + side_len)
		{
			abc->map[(abc->size * y0) + x0] = abc->param[2];
			x0++;
		}
		y0++;
	}	
}

int	ft_find_square(t_map *abc)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	max;
	int				flag;
	unsigned int	sqlen;
	unsigned int	k;
	unsigned int	xmax;
	unsigned int	ymax;
	unsigned int	xm;
	unsigned int	ym;


	max = 0;
	i = 0;
	while (i < abc->n)			//от i до вертикального конца карты
	{
		j = 0;
		while (j < abc->size)	//от j до горизонтального конца карты
		{
			if (abc->map[(abc->size * i) + j] == abc->param[0])	//если нашли пустоту, то
			{
				flag = 1;
				sqlen = 1;
				while (sqlen + i < abc->n && sqlen + j < abc->size && flag)
				{
					k = j;
					while (k <= sqlen + j)
					{
						if (abc->map[(abc->size * (i + sqlen)) + k] == abc->param[1])
						{
							xmax = k + 1;
							flag = 0;
							break;
						}
						k++;
					}
					k = i;
					while (k<= sqlen + i)
					{
						if (abc->map[(abc->size * k) + (j + sqlen)] == abc->param[1])
						{
							ymax = k + 1;
							flag = 0;
							break;
						}
						k++;
					}
					if (flag)
						sqlen++;
				}
				if (max < sqlen)
				{
					xm = j;
					ym = i;
					max = sqlen;
				}
			}
			j++;
		}
		i++;
	}
	printf("x0=%d, xmax=%d, y0=%d, ymax=%d\n", xm, xm + max - 1, ym, ym + max - 1);
	ft_replace(abc, xm, ym, max - 1);
	return (max * max);
}
