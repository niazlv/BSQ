/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapParser_v2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:16:06 by ahector           #+#    #+#             */
/*   Updated: 2021/07/11 19:06:43 by ahector          ###   ########.fr       */
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
	while (k < abc->n && read(fd, &d, 1) == 1)
	{
		if (d == '\n')
		{
			k++;
			i = 0;
		}
		printf("i wanna help! %d times!\n", i);
		if (i > abc->size)
		{
			printf("%d, %d\n", i, abc->size);
			return (1);
		}
		if (k >= 1)
			abc->map[k-1][i] = d;
		i++;
	}
	close(fd);
	return (k);
}

void	ft_print_struct_map(t_map *abc)
{
	unsigned int	i;
//	unsigned int	j;

	i = 0;
	while (i < abc->size)
	{
//		j = 0;
//		while(j < abc->n)
//		{
			printf("%s\n", abc->map[i]);
//			j++;
//		}
//		write(1, "\n", 1);
		i++;
	}
}

int	ft_mapParser_v2(char *filename, t_map *abc)
{
	if (ft_mapParser(filename, abc))
		return (1);

	//ft_print_struct_map(abc);
	printf("sdafahu\n");
	if (ft_while(abc, filename, ' ', 0) != abc->n)
	{
		//ft_print_struct_map(abc);
		//printf("dadad");
		return (1);
	}
	printf("sdafahu\n");
	return (0);
}
