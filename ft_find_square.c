/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 20:23:04 by ahector           #+#    #+#             */
/*   Updated: 2021/07/13 20:35:37 by ahector          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

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
							xmax = k;
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
							ymax = k;
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
					xm = xmax;
					ym = ymax;
					max = sqlen;
				}
			}
			j++;
		}
		i++;
	}
	return (xm * ym);
}
