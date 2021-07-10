/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 18:00:06 by ahector           #+#    #+#             */
/*   Updated: 2021/07/10 18:04:54 by ahector          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

typedef struct s_map
{
	char	*param;
	int		n;
	char	**map;
}	t_map;

int	ft_strlen(char *str);
int	checkLines(char *str);

#endif
