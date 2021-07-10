/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapParser_v2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:16:06 by ahector           #+#    #+#             */
/*   Updated: 2021/07/10 22:08:45 by ahector          ###   ########.fr       */
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
	while (i < abc->n && read(fd, &d, 1) == 1)
	{
		if (d == '\n')
		{
			k++;
			i = 0;
		}
		if (i > abc->size)
			return (1);
		if (k >= 2)
			abc->map[k][i] = d;
	}
	close(fd);
	return (k);
}

int	ft_mapParser_v2(char *filename, t_map *abc)
{
	if (ft_mapParser(filename, abc))
		return (1);
	if (ft_while(abc, filename, ' ', 0) != abc->n)
		return (1);
	return (0);
}
