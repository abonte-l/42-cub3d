/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_08_parsing_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 22:13:41 by abonte-l          #+#    #+#             */
/*   Updated: 2021/04/24 22:18:36 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_check_edges(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->len_line)
	{
		if (info->map[0][i] != '1' && info->map[0][i] != ' ')
			ft_error(MAP_ERROR, info);
		if (info->map[info->nb_line - 1][i] != '1'
			&& info->map[info->nb_line - 1][i] != ' ')
			ft_error(MAP_ERROR, info);
		i++;
	}
	i = 1;
	while (i < info->nb_line)
	{
		if (info->map[i][0] != '1' && info->map[i][0] != ' ')
			ft_error(MAP_ERROR, info);
		if (info->map[i][info->len_line - 1] != '1'
		&& info->map[i][info->len_line - 1] != ' ')
			ft_error(MAP_ERROR, info);
		i++;
	}
}

void	ft_check_inside(t_info *info)
{
	int	i;
	int	j;

	i = 1;
	while (i < info->nb_line - 1)
	{
		j = 1;
		while (j < info->len_line)
		{
			if (info->map[i][j] != '1' && info->map[i][j] != ' ' &&
			(info->map[i - 1][j] == ' ' || info->map[i + 1][j] == ' ' ||
			info->map[i][j - 1] == ' ' || info->map[i][j + 1] == ' '))
			{
				info->map_ex = 1;
				ft_error(MAP_ERROR, info);
			}
			j++;
		}
		i++;
	}
}

void	ft_put_zero(t_info *info)
{
	int i;
	int	j;

	i = 0;
	while (i < info->nb_line)
	{
		j = 0;
		while (j < info->len_line)
		{
			if (info->map[i][j] == ' ')
				info->map[i][j] = '0';
			j++;
		}
		i++;
	}
}

void	ft_get_map_data(char *str, t_info *info)
{
	int		len_tmp;

	len_tmp = 0;
	if (ft_is_map(str, info) == 1)
	{
		if (info->color_f == -1 || info->color_c == -1 || info->no == NULL ||
			info->so == NULL || info->we == NULL || info->ea == NULL ||
			info->sp == NULL)
			ft_error(DATA_ERROR, info);
		if ((len_tmp = (ft_strlen(str))) > info->len_line)
			info->len_line = len_tmp;
		info->nb_line += 1;
	}
}
