/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_symbols.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 18:46:22 by ahector           #+#    #+#             */
/*   Updated: 2021/07/12 13:58:34 by ahector          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_check_symbols(t_map *abc)
{
	unsigned int	k;
	unsigned int	l;

	k = 0;
	l = 0;
	while (k < abc->n)
	{
		l = 0;
		while (abc->map[(abc->size * k) + l] != '\0')
		{
			if (abc->map[(abc->size * k) + l] != abc->param[0] && \
					abc->map[(abc->size * k) + l] != abc->param[1] && \
					abc->map[(abc->size * k) + l] != abc->param[2])
			{
				printf("err: %c\n", abc->map[(abc->size * k) + l]);
				return (1);
			}
			l++;
		}
		k++;
	}
	return (0);
}
