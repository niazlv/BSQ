/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapParser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 20:19:34 by ahector           #+#    #+#             */
/*   Updated: 2021/07/13 20:09:01 by ahector          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

unsigned int	find_len(char *str, unsigned int t, unsigned int k)
{
	int				fd;
	unsigned int	count;
	char			d;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (0);
	count = 0;
	k = 0;
	while (read(fd, &d, 1) == 1)
	{
		if (d == '\n')
		{
			if (k == t)
			{
				close(fd);
				return (count);
			}
			k++;
			count = 0;
		}
		else
			count++;
	}
	return (count);
}

int	find_param(char *str, t_map *abc)
{
	int				fd;
	int				count;
	char			d;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (-1);
	count = 0;
	while (read(fd, &d, 1) == 1)
	{
		if (d == '\n')
			close(fd);
		abc->rawParam[count] = d;
		count++;
	}
	return (count);
}

int	ft_malloc_map(t_map *abc, unsigned int size)
{
	abc->map = (char *)malloc(sizeof(char) * size * abc->n);
	if (abc->map == (void *)0)
		return (1);
	return (0);
}

int	ft_mapParser(char *filename, t_map *abc)
{
	unsigned int	fd;

	fd = find_len(filename, 1, 0);
	if (fd == 0)
		return (1);
	abc->rawParam = (char *)malloc(sizeof(char) * fd);
	if (abc->rawParam == (void *)0)
		return (2);
	if (find_param(filename, abc) == -1)
		return (3);
	if (ft_is_argum(abc->rawParam, abc))
		return (4);
	fd = find_len(filename, 2, 0);
	if (fd == 0)
		return (5);
	abc->size = fd;
	if (ft_malloc_map(abc, abc->size))
		return (6);
	free(abc->rawParam);
	return (0);
}
