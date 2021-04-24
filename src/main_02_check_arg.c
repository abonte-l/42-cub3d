/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_02_check_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:22:26 by abonte-l          #+#    #+#             */
/*   Updated: 2021/04/24 21:25:54 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
	if (str[i - 1] == 'b' && str[i - 2] == 'u'
		&& str[i - 3] == 'c' && str[i - 4] == '.')
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
	if (str[i - 1] == 'e' && str[i - 2] == 'v' &&
		str[i - 3] == 'a' && str[i - 4] == 's' &&
		str[i - 5] == '-' && str[i - 6] == '-' && ft_strlen(str) < 7)
		return (1);
	else
		return (0);
}
