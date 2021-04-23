// #include "../inc/cub3d.h"
#include "cub3d.h"
/*
** here we check if the file in the argument is a .cub
** if not there is an error and the program exit
*/


int		ft_check_dot_cub(char *str, t_info *info)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (str[i] != '.')
	{
		i--;
		if (i == 0)
			ft_error(ARG_ERROR, info);
	}
	if (str[i + 1] == 'c' && str[i + 2] == 'u' && str[i + 3] == 'b')
		ft_parsing(str, info);
	else
		ft_error(ARG_ERROR, info);
	return (0);
}

/*
** here we check if the third argument is --save
** if yes, a variable in the main function is initialise to 1
** if not there is an error in the main function and the program exit
*/

int		ft_check_save_enabled(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] == 'e' && str[i - 2] == 'v' && str[i - 3] == 'a' && str[i - 4] == 's' && str[i - 5] == '-' && str[i - 6] == '-' && ft_strlen(str) < 7)
		return (1);
	else
		return (0);
}


