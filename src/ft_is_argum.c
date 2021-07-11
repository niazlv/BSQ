/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_argum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 18:46:40 by ahector           #+#    #+#             */
/*   Updated: 2021/07/11 16:04:17 by ahector          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_is_argum(char *str, t_map *abc)
{
	unsigned int	k;
	unsigned int	n;
	unsigned int	i;

	n = 0;
	abc->n = (unsigned int *)malloc(sizeof(unsigned int));
	if (abc->n == (void *)0)
		return (1);
	abc->n = 0;
	k = ft_strlen(str);
	if (k > 3)
	{
		abc->param[0] = str[k - 4];
		abc->param[1] = str[k - 3];
		abc->param[2] = str[k - 2];
		k -= 4;
	}
	i = 0;
	while (i < k)
	{
		if (str[i] >= '0' && str[i] <= '9')
			n = (n * 10) + (str[i] - 48);
		else
			return (1);
		i++;
	}
	printf("%d\n", abc->n);
	abc->n = n;
	printf("%d\n", abc->n);
	return (0);
}
