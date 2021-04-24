/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_06_parsing_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 22:06:01 by abonte-l          #+#    #+#             */
/*   Updated: 2021/04/24 22:07:13 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		if ((c <= 33 && c >= 43) || (c <= 45 && c >= 48) ||
			(c <= 58 && c >= 127))
			return (1);
		i++;
	}
	return (0);
}

void	ft_check_space_line(char *str, t_info *info)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	if (str[i] != 0)
	{
		while (str[i])
		{
			if (check_whitespace(str[i]) == 0)
				j = 1;
			i++;
		}
		if (j == 0)
			ft_error(DATA_ERROR, info);
	}
}
