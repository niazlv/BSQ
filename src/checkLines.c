/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkLines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:57:38 by ahector           #+#    #+#             */
/*   Updated: 2021/07/11 16:04:12 by ahector          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/*
 * Функция проверяет количество символов в двумерном массиве(карте)
 *	Если ошибок нет, то возвращаем 0, если вдруг есть какое-то несовпадение,
 *	то возвращаем 1
 */
int	checkLines(char *str[], t_map *abc)
{
	unsigned int	i;
	int				cmp;

	i = 0;
	cmp = ft_strlen(str[0]);
	while (i < abc->n)
	{
		if (cmp != ft_strlen(str[i]))
			return (1);
		cmp = ft_strlen(str[i]);
		i++;
	}
	return (0);
}