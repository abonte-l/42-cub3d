/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_04_parsing_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:57:44 by abonte-l          #+#    #+#             */
/*   Updated: 2021/04/24 22:01:50 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_str_s_char(const char *str, char c)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

double	power(double base, double exponent)
{
	double result;

	result = 1;
	while (exponent > 0)
	{
		result = result * base;
		exponent--;
	}
	return (result);
}

int		check_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\r' || c == '\f')
		return (1);
	else
		return (0);
}

int		ft_atoi_r(char *str, t_info *info)
{
	int result;

	if (str[1] != ' ' || ft_check_wrg_char_r(str) == 1)
		ft_error(DATA_ERROR, info);
	while (check_whitespace(str[info->i]) == 1)
		info->i++;
	if (str[info->i] == '\0')
		return (-1);
	if (str[info->i] == '-' || str[info->i] == '+')
		ft_error(DATA_ERROR, info);
	result = 0;
	while (str[info->i] >= '0' && str[info->i] <= '9')
	{
		if (result > 21474636)
			ft_error(DATA_ERROR, info);
		result = (result * 10 + str[info->i] - 48);
		info->i++;
	}
	return (result);
}

int		ft_atoi_c(char *str, t_info *info)
{
	info->color_result = 0;
	info->count_color = 2;
	while (str[info->i] && info->count_color >= 0)
	{
		while (check_whitespace(str[info->i]) == 1)
			info->i++;
		if (str[1] != ' ' || ft_check_wrg_char_c(str, info) == 1)
			ft_error(DATA_ERROR, info);
		if (str[info->i] == ',')
			info->i++;
		if (str[info->i] == '-' || str[info->i] == '+')
			ft_error(DATA_ERROR, info);
		info->color_tmp = 0;
		while (str[info->i] >= '0' && str[info->i] <= '9')
		{
			info->color_tmp = (info->color_tmp * 10 + str[info->i] - 48);
			info->i++;
		}
		if (info->color_tmp < 0 || info->color_tmp > 255)
			ft_error(DATA_ERROR, info);
		info->color_tmp = info->color_tmp * power(256, info->count_color);
		info->color_result += info->color_tmp;
		info->count_color--;
	}
	return (info->color_result);
}
