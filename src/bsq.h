/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 18:00:06 by ahector           #+#    #+#             */
/*   Updated: 2021/07/10 20:08:26 by ahector          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <stdlib.h>

typedef struct s_map
{
	char	*param;
	int		n;
	char	**map;
}	t_map;

int	ft_strlen(char *str);
int	checkLines(char *str[], t_map *abc);
int	ft_is_argum(char *str, t_map *abc);
int	ft_check_symbols(t_map *abc, char **s2);
#endif
