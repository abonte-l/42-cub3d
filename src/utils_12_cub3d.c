#include "../inc/cub3d.h"

int		ft_strlen(const char *str)
{
	int		len;

	len = 0;
	if (str == NULL)
		return (0);
	while (str[len])
		len++;
	return (len);
}