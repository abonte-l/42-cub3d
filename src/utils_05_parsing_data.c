#include "../inc/cub3d.h"

int		ft_strlen2(char *str)
{
	int j;
	int i;

	j = 0;
	i = 0;
	while (str[i] != '.')
		i++;
	while (str[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

char	*ft_strcpy_texture(char *dest, const char *src, t_info *info, int j)
{
	while (src[j] != 0)
	{
		dest[info->count_tex] = src[j];
		j++;
		info->count_tex++;
	}
	dest[info->count_tex] = '\0';
	return (dest);
}

void	ft_collect_data(char *str, t_info *info)
{
	if (str[0] == 'R')
		info->check_data.resolution += 1;
	else if (str[0] == 'N' && str[1] == 'O')
		info->check_data.text_north += 1;
	else if (str[0] == 'S' && str[1] == 'O')
		info->check_data.text_south = 1;
	else if (str[0] == 'E' && str[1] == 'A')
		info->check_data.text_east += 1;
	else if (str[0] == 'W' && str[1] == 'E')
		info->check_data.text_west += 1;
	else if (str[0] == 'S' && str[1] != 'O')
		info->check_data.text_sprite = 1;
	else if (str[0] == 'C')
		info->check_data.color_ceiling += 1;
	else if (str[0] == 'F')
		info->check_data.color_floor += 1;
	
}

void	ft_check_data(t_info *info)
{
	if (info->check_data.resolution != 1 || info->check_data.text_north != 1 || info->check_data.text_south != 1 || info->check_data.text_east != 1 || info->check_data.text_west != 1 || info->check_data.text_sprite != 1 || info->check_data.color_floor != 1 || info->check_data.color_ceiling != 1)
		ft_error(DATA_ERROR, info);
}

int		ft_check_wrg_char_c(char *str)
{
	int 			i;
	int 			j;
	unsigned char	c;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		c = str[i];
		if ((c <= 33 && c >= 43 )||(c <= 45 && c >= 48) ||(c <= 58 && c >= 177))
		return (1);
		i++;
	}
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ',')
			j += 1;
		i++;
	}
	if (j != 2)
		return (1);
	
	return (0);
}

