/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapParser_v2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:16:06 by ahector           #+#    #+#             */
/*   Updated: 2021/07/11 16:04:10 by ahector          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

unsigned int	ft_while(t_map *abc, char *filename, char d, unsigned int k)
{
	unsigned int	i;
	int				fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	i = 0;
	while (k < abc->n && read(fd, &d, 1) == 1)
	{
		if (d == '\n')
		{
			k++;
			i = 0;
		}
		if (i > abc->size)
			return (1);
		if (k >= 1)
			abc->map[k-1][i] = d;
		i++;
	}
	close(fd);
	return (k);
}

void	ft_print_sturct_map(t_map *abc)
{
	int	i;
	int	j;

	i = 0;
	while (i < abc->size)
	{
		j = 0;
		while(j < abc->n)
		{
			write(1, &abc->map[i][j], 1);
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
	{
		ft_print_struct_map(abc);
		printf("dadad");
		return (1);
	}
	return (0);
}
