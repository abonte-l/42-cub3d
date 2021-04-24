/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_10_movements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:51:30 by abonte-l          #+#    #+#             */
/*   Updated: 2021/04/24 21:51:36 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_forward_backward(t_info *info)
{
	if (info->data.forward == 1)
	{
		if (info->map[(int)(info->ray.posx + (info->ray.dirx * info->
						ray.movespeed * 2))][(int)info->ray.posy] == '0')
			info->ray.posx += info->ray.dirx * info->ray.movespeed;
		if (info->map[(int)(info->ray.posx)][(int)(info->ray.posy +
					(info->ray.diry * info->ray.movespeed * 2))] == '0')
			info->ray.posy += info->ray.diry * info->ray.movespeed;
	}
	if (info->data.back == 1)
	{
		if (info->map[(int)(info->ray.posx - (info->ray.dirx * info->
						ray.movespeed * 2))][(int)(info->ray.posy)] == '0')
			info->ray.posx -= info->ray.dirx * info->ray.movespeed;
		if (info->map[(int)(info->ray.posx)][(int)(info->ray.posy -
					(info->ray.diry * info->ray.movespeed * 2))] == '0')
			info->ray.posy -= info->ray.diry * info->ray.movespeed;
	}
}

void	ft_left_right(t_info *info)
{
	if (info->data.right == 1)
	{
		if (info->map[(int)(info->ray.posx + info->ray.diry *
					(info->ray.movespeed * 2))][(int)info->ray.posy] == '0')
			info->ray.posx += info->ray.diry * info->ray.movespeed;
		if (info->map[(int)info->ray.posx][(int)(info->ray.posy -
					info->ray.dirx *
					(info->ray.movespeed * 2))] == '0')
			info->ray.posy -= info->ray.dirx * info->ray.movespeed;
	}
	if (info->data.left == 1)
	{
		if (info->map[(int)(info->ray.posx - info->ray.diry *
					(info->ray.movespeed * 2))][(int)info->ray.posy] == '0')
			info->ray.posx -= info->ray.diry * info->ray.movespeed;
		if (info->map[(int)info->ray.posx][(int)(info->ray.posy +
					info->ray.dirx *
					(info->ray.movespeed * 2))] == '0')
			info->ray.posy += info->ray.dirx * info->ray.movespeed;
	}
}

void	ft_turn_right_left(t_info *info)
{
	double oldplanx;
	double olddirx;

	oldplanx = info->ray.planx;
	olddirx = info->ray.dirx;
	if (info->data.rotate_right == 1)
	{
		info->ray.dirx = info->ray.dirx * cos(-info->ray.rotspeed / 2) -
			info->ray.diry * sin(-info->ray.rotspeed / 2);
		info->ray.diry = olddirx * sin(-info->ray.rotspeed / 2) +
			info->ray.diry * cos(-info->ray.rotspeed / 2);
		info->ray.planx = info->ray.planx * cos(-info->ray.rotspeed / 2)
			- info->ray.plany * sin(-info->ray.rotspeed / 2);
		info->ray.plany = oldplanx * sin(-info->ray.rotspeed / 2) +
			info->ray.plany * cos(-info->ray.rotspeed / 2);
	}
	ft_turn_left(info, olddirx);
}

void	ft_turn_left(t_info *info, double olddirx)
{
	double oldplanex;

	if (info->data.rotate_left == 1)
	{
		olddirx = info->ray.dirx;
		oldplanex = info->ray.planx;
		info->ray.dirx = info->ray.dirx * cos(info->ray.rotspeed / 2) -
			info->ray.diry * sin(info->ray.rotspeed / 2);
		info->ray.diry = olddirx * sin(info->ray.rotspeed / 2) + info->
			ray.diry * cos(info->ray.rotspeed / 2);
		info->ray.planx = info->ray.planx * cos(info->ray.rotspeed / 2) -
			info->ray.plany * sin(info->ray.rotspeed / 2);
		info->ray.plany = oldplanex * sin(info->ray.rotspeed / 2) +
			info->ray.plany * cos(info->ray.rotspeed / 2);
	}
}
