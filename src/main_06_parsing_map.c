// #include "../inc/cub3d.h"
#include "cub3d.h"
/*
** here we get the raw map as it is in the file and check it 
**then we put it in a matrice and transform it as we can use it
** you'll find ft_check_empty_line, ft_is_map and ft_copy_map in "utils_05"
** you'll find ft_check_edges, ft_check_inside and ft_put_zero in "utils_06"
** you'll find ft_check_error in "utils_08"
*/

int		ft_parsing_map_2(int ret, int fd, t_info *info)
{
	char	*str;

	str = NULL;
	while (ret != 0)
	{
		ret = get_next_line(fd, &str);
		if (info->inside_map == 1 && ft_check_empty_line(str) == 0 &&
				info->count_lines < info->nb_line)
			info->empty_line = 1;
		if ((info->inside_map = ft_is_map(str, info)) == 1)
		{
			ft_fill_in_map(str, info);
			info->count_lines++;
		}
		free(str);
	}
	return (0);
}

int		ft_parsing_map(char *fichier, t_info *info)
{
	int		fd;
	int		ret;
	
	ret = 1;
	if (!(info->map = (char**)malloc(sizeof(char*) * info->nb_line)))
		ft_error(MEMORY_ERROR, info);
	fd = open(fichier, O_RDONLY);
	ft_parsing_map_2(ret, fd, info);
	close(fd);
	if ( info->empty_line == 1 || info->wrg_char_map == 1 || info->start == 'x'|| info->count_player > 1)
	{
		info->map_ex = 1;
		ft_error(DATA_ERROR, info);
	}
	ft_check_edges(info);
	ft_check_inside(info);
	ft_put_zero(info);
	ft_init_sprite(info);
	// ft_mlx(info);
	return (0);
}
