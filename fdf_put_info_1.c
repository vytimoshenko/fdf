/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_put_info_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:27:57 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/13 17:49:03 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_info_to_window(t_map *map, t_status *status, t_view *view)
{
	put_map_summary_1(map, view);
	put_map_summary_2(map, view);
	put_map_summary_3(map, view);
	put_status_1(status, view);
	put_status_2(status, view);
	put_status_3(status, view);
	put_status_4(status, view);
	put_status_5(status, view);
	put_mouse_position(status, view);
	put_control_keys_1(view);
	put_control_keys_2(view);
}

void	put_map_summary_1(t_map *map, t_view *view)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_X - 340;
	pos_y = 50;
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 50, pos_y,
	TEXT_COLOR, "MAP SUMMARY");
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x, pos_y + 30,
	TEXT_COLOR, "Name:");
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 130, pos_y + 30,
	TEXT_COLOR, map->map_name);
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x, pos_y + 60,
	TEXT_COLOR, "Size:");
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 130, pos_y + 60,
	TEXT_COLOR, str = ft_itoa(map->points));
	free(str);
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 100, pos_y + 90,
	TEXT_COLOR, "X:");
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 130, pos_y + 90,
	TEXT_COLOR, str = ft_itoa(map->x_size));
	free(str);
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 100, pos_y + 110,
	TEXT_COLOR, "Y:");
}

void	put_map_summary_2(t_map *map, t_view *view)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_X - 340;
	pos_y = 50;
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 130, pos_y + 110,
	TEXT_COLOR, str = ft_itoa(map->y_size));
	free(str);
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 100, pos_y + 130,
	TEXT_COLOR, "Z:");
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 130, pos_y + 130,
	TEXT_COLOR, str = ft_itoa(map->z_size));
	free(str);
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 60, pos_y + 160,
	TEXT_COLOR, "min Z:");
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 130, pos_y + 160,
	TEXT_COLOR, str = ft_itoa(map->z_min));
	free(str);
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 60, pos_y + 180,
	TEXT_COLOR, "max Z:");
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 130, pos_y + 180,
	TEXT_COLOR, str = ft_itoa(map->z_max));
	free(str);
}

void	put_map_summary_3(t_map *map, t_view *view)
{
	int		pos_x;
	int		pos_y;

	pos_x = WIN_SIZE_X - 340;
	pos_y = 50;
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x, pos_y + 210,
	TEXT_COLOR, "Color:");
	if (map->has_color == 1)
		mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 130, pos_y + 210,
		TEXT_COLOR, "yes");
	else
		mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 130, pos_y + 210,
		TEXT_COLOR, "no");
}
