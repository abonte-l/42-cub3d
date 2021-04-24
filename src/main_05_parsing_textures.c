/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_05_parsing_textures.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:32:43 by abonte-l          #+#    #+#             */
/*   Updated: 2021/04/24 21:38:15 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** here we get path of textures and sprite
** we also check if the path is correct
** you'll find ft_str_s_char in "utils_02"
** you'll find ft_strlen2 and ft_strcpy_texture in "utils_3"
** you'll find ft_check_error in "utils_08"
*/

int		ft_get_texture_path(char *str, char **path, t_info *info, int j)
{
	info->count_tex = 0;
	if (*path != NULL)
		ft_error(DATA_ERROR, info);
	if (ft_str_s_char(str, '.') == 0 ||
		ft_str_s_char(str, '/') == 0 || ft_strlen2(str) <= 2)
		ft_error(DATA_ERROR, info);
	while (str[j] != '.')
	{
		if (str[j] == ' ' && str[j] == '.')
			ft_error(DATA_ERROR, info);
		j++;
	}
	if (!(*path = (char *)malloc(sizeof(char) * (ft_strlen2(str) + 1))))
		ft_error(MEMORY_ERROR, info);
	ft_strcpy_texture(*path, str, info, j);
	return (0);
}

void	ft_texture_alloc(char *str, t_info *info)
{
	int	i;

	i = 0;
	if (str[i] == 'S' && str[i + 1] == 'O')
		ft_get_texture_path(str, &info->so, info, 2);
	else if (str[i] == 'N' && str[i + 1] == 'O')
		ft_get_texture_path(str, &info->no, info, 2);
	else if (str[i] == 'E' && str[i + 1] == 'A')
		ft_get_texture_path(str, &info->ea, info, 2);
	else if (str[i] == 'W' && str[i + 1] == 'E')
		ft_get_texture_path(str, &info->we, info, 2);
	else if (str[i] == 'S' && str[i + 1] == ' ')
		ft_get_texture_path(str, &info->sp, info, 1);
	else if (str[0] != 'N' && str[0] != 'S' && str[0] != 'W' && str[0] != 'E'
			&& str[0] != 'R' && str[0] != 'F' && str[0] != 'C'
			&& str[0] > 65 && str[0] < 122)
		ft_error(DATA_ERROR, info);
}
