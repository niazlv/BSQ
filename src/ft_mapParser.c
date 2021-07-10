/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapParser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 20:19:34 by ahector           #+#    #+#             */
/*   Updated: 2021/07/10 22:09:46 by ahector          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int	find_len(char *str, int t)
{
	int				fd;
	int				count;
	char			d;
	int				k;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (-1);
	count = 0;
	k = 0;
	while (read(fd, &d, 1) == 1)
	{
		if (d == '\n')
		{
			k++;
			count = 0;
		}
		if (k == t)
			close(fd);
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

/*
 *	Проверить насколько хорошо выделена память
 */
int	ft_malloc_map(t_map *abc, int size)
{
	unsigned int	i;

	i = 0;
	while (i < abc->n)
	{
		abc->map[i] = (char *)malloc(sizeof(char) * size);
		if (abc->map[i] == (void *)0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_mapParser(char *filename, t_map *abc)
{
	int				fd;

	fd = find_len(filename, 1);
	if (fd == -1)
		return (1);
	abc->rawParam = (char *)malloc(sizeof(char) * fd);
	if (abc->rawParam == (void *)0)
		return (1);
	find_param(filename, abc);
	if (ft_is_argum(abc->rawParam, abc))
		return (1);
	fd = find_len(filename, 2);
	if (fd == -1)
		return (1);
	abc->size = fd;
	abc->map = (char **)malloc(sizeof(char) * abc->n);
	if (abc->map == (void *)0)
		return (1);
	if (ft_malloc_map(abc, fd))
		return (1);
	free(abc->rawParam);
	return (0);
}
