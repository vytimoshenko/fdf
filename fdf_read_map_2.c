/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_map_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 03:55:20 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/13 03:36:53 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_color(char *color)
{
	char	*prefix;

	if (color != NULL)
	{
		if (ft_strlen(color) > 10)
			ft_put_error("fdf: color data is wrong");
		prefix = ft_strnew(2);
		prefix[0] = '0';
		prefix[1] = 'x';
		if (!(ft_strstr(color, (char *)prefix)))
			ft_put_error("fdf: color data is wrong");
		ft_strdel(&prefix);
		free(prefix);
		prefix = NULL;
	}
}

int		atoi_mod(const char *str)
{
	long	result;
	int		sign;

	if (ft_strlen(str) > 10)
		ft_put_error("fdf: z coordinate is wrong");
	sign = 0;
	if (*str == '-')
	{
		sign = 1;
		str++;
		if (*str < '0' || *str > '9')
			ft_put_error("fdf: z coordinate is wrong");
	}
	result = 0;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		result = result * 10 + *str - '0';
		str++;
	}
	if (sign == 1)
		result = -result;
	if (result < -2147483648 || result > 2147483647)
		ft_put_error("fdf: z coordinate is wrong");
	return (result);
}

int		atoi_color(char *str)
{
	size_t	result;
	int		digit;
	int		power;

	result = 0;
	digit = 0;
	str += 2;
	power = ft_strlen(str);
	while (power > 0)
	{
		if (ft_isdigit(*str))
			digit = *str - '0';
		else if (*str >= 'a' && *str <= 'f')
			digit = *str - 'a' + 10;
		else if (*str >= 'A' && *str <= 'F')
			digit = *str - 'A' + 10;
		else
			return (-1);
		result += digit * ft_power(16, power - 1);
		str++;
		power--;
	}
	return (result);
}

void	separate_color(t_map *map, char **split_line, int x, int y)
{
	char	**separate_color;

	separate_color = ft_strsplit(split_line[x], ',');
	check_color(separate_color[1]);
	map->xyz[y][x] = atoi_mod(separate_color[0]);
	map->clr[y][x] = atoi_color(separate_color[1]);
	ft_arrdel(separate_color);
	free(separate_color);
}

void	save_map_line(t_map *map, char **split_line, int y)
{
	int		x;
	int		color;

	x = -1;
	while (++x < map->x_size)
	{
		color = ft_wrdcnt(split_line[x], ',') - 1;
		if (color == 0)
		{
			map->xyz[y][x] = atoi_mod(split_line[x]);
			map->clr[y][x] = 0;
		}
		else if (color == 1)
		{
			separate_color(map, split_line, x, y);
			map->has_color = 1;
		}
		else
			ft_put_error("fdf: wrong map file data");
		get_max_min_z(map, x, y);
	}
}
