/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 18:00:06 by ahector           #+#    #+#             */
/*   Updated: 2021/07/14 23:10:20 by ahector          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_map
{
	char			*param;
	unsigned int	size;
	char			*rawParam;
	unsigned int	n;
	char			*map;
}	t_map;

int		ft_strlen(char *str);
int		ft_is_argum(char *str, t_map *abc);
int		ft_check_symbols(t_map *abc);
int		ft_mapParser(char *filename, t_map *abc);
int		ft_mapParser_v2(char *filename, t_map *abc);
void	ft_print_struct_map(t_map *abc);
int		ft_find_square(t_map *abc);
int		ft_std_input(t_map *abc);

#endif
