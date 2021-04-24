// #include "../inc/cub3d.h"
#include "cub3d.h"

void	ft_init_info_3(t_info *info)
{
	info->s.order = NULL;
	info->s.dist = NULL;
	info->s.zbuffer = NULL;
	info->sxy = NULL;
}

void	ft_init_info_2(t_info *info)
{
	info->check_data.resolution = 0;
	info->check_data.color_ceiling = 0;
	info->check_data.color_floor = 0;
	info->check_data.text_north = 0;
	info->check_data.text_south = 0;
	info->check_data.text_east = 0;
	info->check_data.text_west = 0;
	info->check_data.text_sprite = 0;
	info->map = NULL;
	info->wrg_char_map = 0;
	info->count_player = 0;
	info->r_verif = 0;
	info->check_line_map = 0;
	info->check_col_map	= 0;
	info->escp_cl = 0;
	info->cross_cl = 0;
	ft_init_info_3(info);

}

void	ft_init_info_1(t_info *info)
{
	info->r_x = 0;
	info->r_y = 0;
	info->i = 0;
	info->color_f = -1;
	info->color_c = -1;
	info->nb_line = 0;
	info->len_line = 0;
	info->map = NULL;
	info->no = NULL;
	info->so = NULL;
	info->ea = NULL;
	info->we = NULL;
	info->sp = NULL;
	info->start = 'x';
	info->start_x = 0;
	info->start_y = 0;
	info->save_enbld = 0;
	info->error = 0;
	info->count_tex = 0;
	info->count_color = 0;
	info->count_lines = 0;
	info->empty_line = 0;
	info->inside_map = 0;
	info->map_ex = 0;
	ft_init_info_2(info);
}

void	ft_init_dir(t_info *info)
{
	if (info->start == 'N')
		info->ray.dirx = -1;
	if (info->start == 'S')
		info->ray.dirx = 1;
	if (info->start == 'E')
		info->ray.diry = 1;
	if (info->start == 'W')
		info->ray.diry = -1;
	if (info->start == 'N')
		info->ray.plany = 0.66;
	if (info->start == 'S')
		info->ray.plany = -0.66;
	if (info->start == 'E')
		info->ray.planx = 0.66;
	if (info->start == 'W')
		info->ray.planx = -0.66;
}

void	ft_calc_delta_dist(t_info *info)
{
	if (info->ray.raydiry == 0)
		info->ray.deltadistx = 0;
	else if (info->ray.raydirx == 0)
		info->ray.deltadistx = 1;
	else
		info->ray.deltadistx = sqrt(1 + (info->ray.raydiry
			* info->ray.raydiry) / (info->ray.raydirx *
			info->ray.raydirx));
	if (info->ray.raydirx == 0)
		info->ray.deltadisty = 0;
	else if (info->ray.raydiry == 0)
		info->ray.deltadisty = 1;
	else
		info->ray.deltadisty = sqrt(1 + (info->ray.raydirx *
			info->ray.raydirx) / (info->ray.raydiry *
			info->ray.raydiry));
}
