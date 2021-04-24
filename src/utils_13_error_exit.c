/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_13_error_exit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 22:21:47 by abonte-l          #+#    #+#             */
/*   Updated: 2021/04/24 22:29:46 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_var_2(t_info *info)
{
	if (info->map)
		free(info->map);
	if (info->s.dist)
		free(info->s.dist);
	if (info->sxy)
		free(info->sxy);
	if (info->s.zbuffer)
		free(info->s.zbuffer);
	if (info->s.order)
		free(info->s.order);
	ft_exit(info);
}

void	ft_free_var_1(t_info *info, char *str)
{
	if (str == ARG_ERROR || str == DATA_ERROR || str == FILE_ERROR ||
	str == MAP_ERROR || str == NO_MAP_ERROR || str == SAVE_OK ||
	str == BMP_ERROR)
	{
		ft_exit_sucess(info, str);
		exit(0);
	}
	else
		ft_free_var_2(info);
}

void	ft_free_var(t_info *info, char *str)
{
	int i;

	i = -1;
	if (info->no)
		free(info->no);
	if (info->so)
		free(info->so);
	if (info->we)
		free(info->we);
	if (info->ea)
		free(info->ea);
	if (info->sp)
		free(info->sp);
	if (info->map)
	{
		while (++i < info->nb_line && info->map[i])
			free(info->map[i]);
	}
	ft_free_var_1(info, str);
}

void	ft_error(char *str, t_info *info)
{
	write(1, "\n\n", 2);
	write(1, "Error\n", 6);
	write(1, str, ft_strlen(str));
	write(1, "\n\n", 2);
	ft_free_var(info, str);
}
