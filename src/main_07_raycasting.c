/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_07_raycasting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:48:28 by abonte-l          #+#    #+#             */
/*   Updated: 2021/04/24 21:48:29 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_raycasting(t_info *info)
{
	info->ray.x = 0;
	while (info->ray.x < info->r_x)
	{
		ft_init_in_rcstng(info);
		ft_dispatch_calc(info);
		ft_colcol(info);
		info->s.zbuffer[info->ray.x] = info->ray.perpwalldist;
		info->ray.x++;
	}
	ft_sprite(info);
	if (info->save_enbld == 1)
		ft_save_to_bmp(info);
	mlx_put_image_to_window(info->data.mlx_ptr, info->data.mlx_win,
			info->data.img, 0, 0);
	ft_forward_backward(info);
	ft_left_right(info);
	ft_turn_right_left(info);
	ft_swap(info);
	return (0);
}

int		ft_mlx(t_info *info)
{
	ft_init_in_ftmlx(info);
	if (!(info->data.mlx_ptr = mlx_init()))
		ft_error(MLX_ERROR, info);
	mlx_get_screen_size(info->data.mlx_ptr, &info->screenx, &info->screeny);
	info->r_x = (info->r_x > info->screenx) ? info->screenx : info->r_x;
	info->r_y = (info->r_y > info->screeny) ? info->screeny : info->r_y;
	ft_get_texture(info);
	info->data.img = mlx_new_image(info->data.mlx_ptr, info->r_x, info->r_y);
	info->data.addr = (int *)mlx_get_data_addr(info->data.img, &info->data.
			bits_per_pixel, &info->data.line_length, &info->data.endian);
	if (info->save_enbld == 1)
		ft_raycasting(info);
	info->data.mlx_win = mlx_new_window(info->data.mlx_ptr, info->r_x,
			info->r_y, "CUB3D");
	info->data.img2 = mlx_new_image(info->data.mlx_ptr, info->r_x, info->r_y);
	info->data.addr2 = (int *)mlx_get_data_addr(info->data.img2, &info->
			data.bits_per_pixel, &info->data.line_length, &info->data.endian);
	if (mlx_hook(info->data.mlx_win, 33, 1L << 17, ft_exit, info))
		info->cross_cl = 1;
	mlx_hook(info->data.mlx_win, 2, 1L << 0, ft_handle_keypress, info);
	mlx_loop_hook(info->data.mlx_ptr, ft_raycasting, info);
	mlx_hook(info->data.mlx_win, 3, 1L << 1, ft_handle_keyrelease, info);
	mlx_loop(info->data.mlx_ptr);
	return (0);
}
