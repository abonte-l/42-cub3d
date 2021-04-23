// #include "../inc/cub3d.h"
#include "cub3d.h"
/*
** here we check if the file is not a directory and if we can open it
** then we read it with GNL and start collecting datas in the file
** we also check if there is a map in the .cub
** you'll find ft_collect_data and ft_check_data in "utils_03"
** you'll find ft_get_map_data in "utils_05"
** you'll find ft_check_error in "utils_08"
** others are in the main path or from libs included
*/

void	ft_parsing(char *fichier, t_info *info)
{
	int		fd;
	int		ret;
	char	*str;
	ret = 1;
	str = NULL;
	if ((fd =open(fichier, __O_DIRECTORY)) != -1)
		ft_error(FILE_ERROR, info);
	if ((fd =open(fichier, O_RDONLY)) == -1)
		ft_error(FILE_ERROR, info);
	while (ret != 0 )
	{
		ret = get_next_line(fd, &str);
		ft_collect_data(str, info);
		ft_res_color_parsing(&str, info);
		ft_texture_alloc(str, info);
		ft_get_map_data(str, info);
		free(str);
	}
	close(fd);
	ft_check_data(info);
	if (info->len_line == 0 || info->nb_line == 0)
		ft_error(NO_MAP_ERROR, info);
	ft_parsing_map(fichier, info);
}
