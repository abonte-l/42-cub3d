
#include "cub3d.h" 



void	ft_dist_n_order2(t_info *info)
{
	int i;

	i = -1;
	while (++i < info->s.nbspr)
	{
		info->s.order[i] = i;
		info->s.dist[i] = ((info->ray.posx - info->sxy[i].x) *
				(info->ray.posx - info->sxy[i].x) + (info->ray.posy -
					info->sxy[i].y) * (info->ray.posy - info->sxy[i].y));
	}
}

void	ft_dist_n_order(t_info *info)
{
	int		i;
	int		j;
	double	tmp;

	ft_dist_n_order2(info);
	i = -1;
	while (++i < info->s.nbspr)
	{
		j = -1;
		while (++j < info->s.nbspr - 1)
		{
			if (info->s.dist[j] < info->s.dist[j + 1])
			{
				tmp = info->s.dist[j];
				info->s.dist[j] = info->s.dist[j + 1];
				info->s.dist[j + 1] = tmp;
				tmp = info->s.order[j];
				info->s.order[j] = info->s.order[j + 1];
				info->s.order[j + 1] = (int)tmp;
			}
		}
	}
}

void	ft_calc(t_info *info, int i)
{
	info->s.spritex = info->sxy[info->s.order[i]].x - info->ray.posx;
	info->s.spritey = info->sxy[info->s.order[i]].y - info->ray.posy;
	info->s.invdet = 1.0 / (info->ray.planx * info->ray.diry -
			info->ray.dirx * info->ray.plany);
	info->s.transformx = info->s.invdet * (info->ray.diry *
			info->s.spritex - info->ray.dirx * info->s.spritey);
	info->s.transformy = info->s.invdet * (-info->ray.plany *
			info->s.spritex + info->ray.planx * info->s.spritey);
	info->s.spritescreenx = (int)((info->r_x / 2) * (1 + info->s.transformx
				/ info->s.transformy));
	info->s.spriteheight = abs((int)(info->r_y / (info->s.transformy)));
	info->s.drawstarty = -info->s.spriteheight / 2 + info->r_y / 2;
	if (info->s.drawstarty < 0)
		info->s.drawstarty = 0;
	info->s.drawendy = info->s.spriteheight / 2 + info->r_y / 2;
	if (info->s.drawendy >= info->r_y)
		info->s.drawendy = info->r_y;
	info->s.spritewidth = abs((int)(info->r_y / (info->s.transformy)));
	info->s.drawstartx = -info->s.spritewidth / 2 + info->s.spritescreenx;
	if (info->s.drawstartx < 0)
		info->s.drawstartx = 0;
	info->s.drawendx = info->s.spritewidth / 2 + info->s.spritescreenx;
	if (info->s.drawendx >= info->r_x)
		info->s.drawendx = info->r_x;
}

void	ft_draw_sprites(t_info *info, int y, int texx, int stripe)
{
	int		d;
	int		texy;

	while (y < info->s.drawendy)
	{
		d = (y) * 256 - info->r_y * 128 + info->s.spriteheight * 128;
		texy = ((d * info->texture[4].height) / info->s.spriteheight) / 256;
		if (info->texture[4].addr[texy * info->texture[4].line_length / 4 +
				texx] != -16777216)
		{
			info->data.addr[y * info->data.line_length / 4 + stripe] =
				info->texture[4].addr[texy * info->texture[4].line_length /
				4 + texx];
		}
		y++;
	}
}

void	ft_sprite(t_info *info)
{
	int i;
	int y;
	int stripe;
	int texx;

	i = -1;
	ft_dist_n_order(info);
	while (++i < info->s.nbspr)
	{
		ft_calc(info, i);
		stripe = info->s.drawstartx;
		while (stripe < info->s.drawendx)
		{
			texx = (int)(256 * (stripe - (-info->s.spritewidth / 2 +
							info->s.spritescreenx)) * info->texture[4].width
					/ info->s.spritewidth) / 256;
			if (info->s.transformy > 0 && stripe >= 0 && stripe < info->r_x
					&& info->s.transformy < info->s.zbuffer[stripe])
			{
				y = info->s.drawstarty;
				ft_draw_sprites(info, y, texx, stripe);
			}
			stripe++;
		}
	}
}
