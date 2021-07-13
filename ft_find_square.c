/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:24:03 by ahector           #+#    #+#             */
/*   Updated: 2021/07/13 21:21:13 by ahector          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/*
 * Name of variable |	= vars[N]
 *-------------------------------
 *	i				|	= vars[0]
 *	j				|	= vars[1]
 *	max				|	= vars[2]
 *	flag			|	= vars[3]
 *  sqlen			|	= vars[4]
 *  k				|	= vars[5]
 */

void	ft_what_v2(unsigned int *vars, t_map *abc)
{
	while (vars[5] <= vars[4] + vars[1])
	{
		if (abc->map[(abc->size * (vars[0] + vars[4])) + vars[5]] \
				== abc->param[1])
		{
			vars[3] = 0;
			break ;
		}
		vars[5]++;
	}
	vars[5] = vars[0];
	while (vars[5] <= vars[4] + vars[0])
	{
		if (abc->map[(abc->size * vars[5]) + \
				(vars[1] + vars[4])] == abc->param[1])
		{
			vars[3] = 0;
			break ;
		}
		vars[5]++;
	}
}

void	ft_what(unsigned int *vars, t_map *abc)
{
	if (abc->map[(abc->size * vars[0]) + vars[1]] == abc->param[0])
	{
		vars[3] = 1;
		vars[4] = 1;
		while (vars[4] + vars[0] < abc->n && vars[4] + \
				vars[1] < abc->size && vars[3])
		{
			vars[5] = vars[1];
			ft_what_v2(vars, abc);
			if (vars[3])
				vars[4]++;
		}
		if (vars[2] < vars[4])
			vars[2] = vars[4];
	}
}

int	ft_find_square(t_map *abc)
{
	unsigned int	*vars;
	unsigned int	sum;

	vars = (unsigned int *)malloc(sizeof(unsigned int) * 6);
	if (vars == (void *)0)
		return (-1);
	vars[2] = 0;
	vars[0] = 0;
	while (vars[0] < abc->n)
	{
		vars[1] = 0;
		while (vars[1] < abc->size)
		{
			ft_what(vars, abc);
			vars[1]++;
		}
		vars[0]++;
	}
	sum = vars[2];
	free(vars);
	return (sum * sum);
}
