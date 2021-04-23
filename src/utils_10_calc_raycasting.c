// #include "../inc/cub3d.h"
#include "cub3d.h"

void	ft_dispatch_calc(t_info *info)
{
	ft_step_side_dist(info);
	ft_increment_ray(info);
	ft_draw_start_end(info);
}

void	ft_step_side_dist(t_info *info)
{
	if (info->ray.raydirx < 0)
	{
		info->ray.stepx = -1;
		info->ray.sidedistx = (info->ray.posx - info->ray.mapx) \
							* info->ray.deltadistx;
	}
	else
	{
		info->ray.stepx = 1;
		info->ray.sidedistx = (info->ray.mapx + 1.0 - info->ray.posx) \
							* info->ray.deltadistx;
	}
	if (info->ray.raydiry < 0)
	{
		info->ray.stepy = -1;
		info->ray.sidedisty = (info->ray.posy - info->ray.mapy) \
							* info->ray.deltadisty;
	}
	else
	{
		info->ray.stepy = 1;
		info->ray.sidedisty = (info->ray.mapy + 1.0 - info->ray.posy) \
							* info->ray.deltadisty;
	}
}

void	ft_increment_ray(t_info *info)
{
	while (info->ray.hit == 0)
	{
		if (info->ray.sidedistx < info->ray.sidedisty)
		{
			info->ray.sidedistx += info->ray.deltadistx;
			info->ray.mapx += info->ray.stepx;
			info->ray.side = 0;
		}
		else
		{
			info->ray.sidedisty += info->ray.deltadisty;
			info->ray.mapy += info->ray.stepy;
			info->ray.side = 1;
		}
		if (info->map[info->ray.mapx][info->ray.mapy] == '1')
			info->ray.hit = 1;
	}
}

void	ft_draw_start_end(t_info *info)
{
	if (info->ray.side == 0)
		info->ray.perpwalldist = ((double)info->ray.mapx - \
				info->ray.posx + (1 - (double)info->ray.
				stepx) / 2) / info->ray.raydirx;
	else
		info->ray.perpwalldist = ((double)info->ray.mapy - \
				info->ray.posy + (1 - (double)info->ray.
				stepy) / 2) / info->ray.raydiry;
	info->ray.lineheight = (int)(info->r_y / info->ray.perpwalldist);
	info->ray.drawstart = -info->ray.lineheight / 2 + info->r_y / 2;
	if (info->ray.drawstart < 0)
		info->ray.drawstart = 0;
	info->ray.drawend = info->ray.lineheight / 2 + info->r_y / 2;
	if (info->ray.drawend >= info->r_y || info->ray.drawend < 0)
		info->ray.drawend = info->r_y - 1;
}

void	ft_swap(t_info *info)
{
	void *tmp;

	tmp = info->data.img;
	info->data.img = info->data.img2;
	info->data.img2 = tmp;
	tmp = info->data.addr;
	info->data.addr = info->data.addr2;
	info->data.addr2 = tmp;
}
