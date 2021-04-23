#include "../inc/cub3d.h"


int		ft_check_wrg_char_r(char *str)
{
	int				i;
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
	return (0);
}
