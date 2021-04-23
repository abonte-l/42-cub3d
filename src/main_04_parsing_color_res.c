// #include "../inc/cub3d.h"
#include "cub3d.h"
/*
** here we get resolution and colors (for 'ceiling' and 'floor')
** we also check if the resolution is only two numbers
** you'll find ft_atoi_r and ft_atoi_c in "utils_02"
** you'll find ft_check_error in "utils_08"
*/

void	ft_res_color_parsing(char **str, t_info *info)
{
	int	i;

	i = 0;
	info->i = 1;
	if (*str[i] == 'R')
	{
		info->r_x = ft_atoi_r(*str, info);
		info->r_y = ft_atoi_r(*str, info);
		info->r_verif = ft_atoi_r(*str, info);
		if (info->r_verif != -1 || info->r_x == -1 || info->r_y == -1)
			ft_error(DATA_ERROR, info);
	}
	else if (*str[i] == 'F')
		info->color_f = ft_atoi_c(*str, info);
	else if (*str[i] == 'C')
		info->color_c = ft_atoi_c(*str, info);
	
}
