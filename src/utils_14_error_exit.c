/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_14_error_exit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 22:25:05 by abonte-l          #+#    #+#             */
/*   Updated: 2021/04/24 22:30:09 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit_sucess(t_info *info, char *str)
{
	if (info->cross_cl == 1 || info->escp_cl == 1)
	{
		str = EXIT_GAME;
		write(1, "\n\n", 2);
		write(1, str, ft_strlen(str));
		write(1, "\n\n", 2);
	}
	if (info->save_enbld == 1)
	{
		str = SAVE_OK;
		write(1, "\n\n", 2);
		write(1, str, ft_strlen(str));
		write(1, "\n\n", 2);
	}
}

int		ft_exit(t_info *info)
{
	char	*str;

	str = NULL;
	if (info->data.img)
		mlx_destroy_image(info->data.mlx_ptr, info->data.img);
	if (info->texture[0].img)
		mlx_destroy_image(info->data.mlx_ptr, info->texture[0].img);
	if (info->texture[1].img)
		mlx_destroy_image(info->data.mlx_ptr, info->texture[1].img);
	if (info->texture[2].img)
		mlx_destroy_image(info->data.mlx_ptr, info->texture[2].img);
	if (info->texture[3].img)
		mlx_destroy_image(info->data.mlx_ptr, info->texture[3].img);
	if (info->texture[4].img)
		mlx_destroy_image(info->data.mlx_ptr, info->texture[4].img);
	if (info->data.mlx_win)
		mlx_destroy_window(info->data.mlx_ptr, info->data.mlx_win);
	ft_exit_sucess(info, str);
	exit(0);
	return (0);
}
