#include "../inc/cub3d.h"

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
	int i;

	i = -1;
	// write(1,"prout33\n",8);
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
	if (str == ARG_ERROR || str == DATA_ERROR || str == FILE_ERROR || str == MAP_ERROR || str == NO_MAP_ERROR || str == SAVE_OK || str == BMP_ERROR)
		{
			// write(1,"prout44\n",8);
			ft_exit_sucess(info, str);
			exit(0);
		}
	else
		ft_free_var_2(info);
}

void 	ft_error(char *str, t_info *info)
{
	// write(1,"prout22\n",8);
	// printf("%s\n\n",str);
	write(1, "Error\n", 6);
	write(1, str, ft_strlen(str));
	write(1, "\n\n", 2);
	ft_free_var_1(info, str);
}

