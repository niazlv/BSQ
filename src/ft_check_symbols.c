/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_symbols.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 18:46:22 by ahector           #+#    #+#             */
/*   Updated: 2021/07/11 16:04:13 by ahector          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_check_symbols(t_map *abc, char **s2)
{
	int		k;
	int		l;
	int		m;

	m = abc->n;
	k = 0;
	l = 0;
	while (k < m)
	{
		l = 0;
		while (s2[k][l] != '\0')
		{
			if (s2[k][l] != abc->param[0] && s2[k][l] != abc->param[1] && \
					s2[k][l] != abc->param[2])
				return (1);
			l++;
		}
		k++;
	}
	return (0);
}
