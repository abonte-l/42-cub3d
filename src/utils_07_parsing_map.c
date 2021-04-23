#include "../inc/cub3d.h"

int		ft_put_spaces(int i, int j, t_info *info)
{
	while (j <= info->len_line)
	{
		info->map[i][j] = ' ';
		j++;
	}
	return (j);
}

int		ft_fill_in_map(char *str, t_info *info)
{
	static int	i = 0;
	int			j;
	
	j = 0;
	info->map[i] = NULL;
	if (!(info->map[i] = malloc(sizeof(char) * info->len_line + 1)))
	{
		info->map_ex = 1;
		ft_error(MEMORY_ERROR, info);
	}
		
	while (str[j] != '\0')
	{
		if (ft_start(str[j], info, i, j) == 1)
			info->map[i][j] = '0';
		else
			info->map[i][j] = str[j];
		j++;
	}
	j = ft_put_spaces(i, j, info);
	info->map[i][j] = '\0';
	i++;
	return (0);
}

int		ft_check_empty_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\t' && str[i] != ' ' && str[i] != '\0' &&
				str[i] != '\n' && str[i] != '\r' && str[i] != '\v'
				&& str[i] != '\f')
			return (1);
		i++;
	}
	return (0);
}

int		ft_start(char c, t_info *info, int i, int j)
{
	if (c == 'N' || c == 'W' || c == 'S' || c == 'E')
	{
		info->start = c;
		info->start_x = i;
		info->start_y = j;
		info->count_player += 1;
		return (1);
	}
	return (0);
}

int		ft_is_map(char *str, t_info *info)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	if ((ft_str_s_char(str, '1') == 1) || (ft_str_s_char(str, '0') == 1))
	{
		while (str[i])
		{
			if (str[i] != ' ' && str[i] != '0' && str[i] != '1'	&& str[i] != '2' && str[i] != 'N' && str[i] != 'S' && str[i] != 'E' && str[i] != 'W' && str[i] != '\n' && str[i] != '\t')
			{
				if (info->inside_map == 1)
					info->wrg_char_map = 1;
				return (0);
			}
			i++;
		}
		return (1);
	}
	return(0);
}

void	ft_get_map_data(char *str, t_info *info)
{
	int		len_tmp;

	len_tmp = 0;
	if (ft_is_map(str, info) == 1)
	{
		if (info->color_f == -1 || info->color_c == -1 || info->no == NULL || 		info->so == NULL || info->we == NULL || info->ea == NULL || 			info->sp == NULL)
			{
				info->map_ex = 1;
				ft_error(DATA_ERROR, info);
			}
		if ((len_tmp = (ft_strlen(str))) > info->len_line)
		info->len_line = len_tmp;
	info->nb_line += 1;
	}
	
}
