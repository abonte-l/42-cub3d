/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:52:03 by abonte-l          #+#    #+#             */
/*   Updated: 2021/04/24 21:52:32 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int ac, char **av)
{
	t_info	info;

	ft_init_info_1(&info);
	if (ac == 2 || (ac == 3 && ft_check_save_enabled(av[2]) == 1))
	{
		if (ac == 3)
			info.save_enbld = 1;
		ft_check_dot_cub(av[1], &info);
	}
	else
		ft_error(ARG_ERROR, &info);
	return (0);
}
