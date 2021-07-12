/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapParser_v2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:16:06 by ahector           #+#    #+#             */
/*   Updated: 2021/07/12 14:32:39 by ahector          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

unsigned int	ft_while(t_map *abc, char *filename, char d, unsigned int k)
{
	unsigned int	i;
	int				fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	i = 0;
	while (read(fd, &d, 1) == 1)
	{
		if (d == '\n')
		{
			if (k != 0 && i < abc->size)
				return (1);
			k++;
			i = 0;
		}
		else
		{
			if (i > abc->size)
				return (1);
			if (k >= 1)
			{
				abc->map[(abc->size * (k - 1)) + i] = d;
				//printf("i wanna help! %d times!\n", i);
			}
			i++;
		}
	}
	close(fd);
	return (k - 1);
}

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

int	ft_mapParser_v2(char *filename, t_map *abc)
{
	if (ft_mapParser(filename, abc))
		return (1);
	if (ft_while(abc, filename, ' ', 0) != abc->n)
		return (2);
	return (0);
}
