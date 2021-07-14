/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_std_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 19:42:56 by ahector           #+#    #+#             */
/*   Updated: 2021/07/14 22:19:57 by ahector          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_rewrite_maps(char *mass, char *r)
{
	int	j;

	j = 0;
	while (j < ft_strlen(mass))
	{
		r[j] = mass[j];
		j++;
	}
}

int	ft_std_input(t_map *abc)
{
	unsigned int	i;
	unsigned int	k;
	char			c;
	char			*r;

	i = 0;
	k = 0;
	abc->rawParam = (char *)malloc(sizeof(char) * 1000);
	abc->map = (char *)malloc(sizeof(char) * 0x2711);
	while (read(0, &c, 1) == 1)
	{
		if (c == '\n')
		{
			if (k == 0)
			{
				if (abc->param == (void *)0)
					return (1);
				abc->rawParam[i] = '\n';
				r = (char *)malloc(sizeof(char) * i);
				ft_rewrite_maps(abc->rawParam, r);
				free(abc->rawParam);
				abc->rawParam = r;
				if (ft_is_argum(abc->rawParam, abc) == -1)
					return (2);
			}
			if (k == 1)
			{
				abc->size = i;
				r = (char *)malloc(sizeof(char) * abc->n * abc->size);
				ft_rewrite_maps(abc->map, r);
				free(abc->map);
				abc->map = r;
			}
			i = 0;
			k++;
		}
		else
		{
			if (k == 0)
				abc->rawParam[i] = c;
			if (k == 1)
				abc->map[i] = c;
			if (k > 1)
				if (i > abc->size)
					return (3);
				abc->map[(abc->size * (k - 1)) + i] = c;
			i++;
		}
	}
	return ((k - 1) - abc->n);
}
