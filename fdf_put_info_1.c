/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_put_info_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:27:57 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/21 03:06:21 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_info_to_window(t_global *global)
{
	put_map_summary_1(global->map, global->mlx);
	put_map_summary_2(global->map, global->mlx);
	put_map_summary_3(global->map, global->mlx);
	put_status_1(global->status, global->mlx);
	put_status_2(global->status, global->mlx);
	put_status_3(global->status, global->mlx);
	put_status_4(global->status, global->mlx);
	put_status_5(global->status, global->mlx);
	put_control_keys_1(global->mlx);
	put_control_keys_2(global->mlx);
	put_render_info_1(global->mlx);
	put_render_info_2(global->mlx);
	put_mouse_position(global->status, global->mlx);
}

void	put_map_summary_1(t_map *map, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 340;
	pos_y = 50;
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 50, pos_y, TEXT_COLOR,
	"MAP SUMMARY");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 30, TEXT_COLOR,
	"Name:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 30, TEXT_COLOR,
	map->trimmed_map_name);
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 60, TEXT_COLOR,
	"Size:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 60, TEXT_COLOR,
	str = ft_itoa(map->points));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 100, pos_y + 90, TEXT_COLOR,
	"X:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 90, TEXT_COLOR,
	str = ft_itoa(map->x_size));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 100, pos_y + 110, TEXT_COLOR,
	"Y:");
}

void	put_map_summary_2(t_map *map, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 340;
	pos_y = 50;
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 110, TEXT_COLOR,
	str = ft_itoa(map->y_size));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 100, pos_y + 130, TEXT_COLOR,
	"Z:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 130, TEXT_COLOR,
	str = ft_itoa(map->z_size));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 60, pos_y + 160, TEXT_COLOR,
	"min Z:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 160, TEXT_COLOR,
	str = ft_itoa(map->z_min));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 60, pos_y + 180, TEXT_COLOR,
	"max Z:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 180, TEXT_COLOR,
	str = ft_itoa(map->z_max));
	free(str);
}

void	put_map_summary_3(t_map *map, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;

	pos_x = WIN_SIZE_W - 340;
	pos_y = 50;
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 210,
	TEXT_COLOR, "Color:");
	if (map->has_color == 1)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 210, TEXT_COLOR,
		"yes");
	else
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 210, TEXT_COLOR,
		"no");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 240,
	TEXT_COLOR, "Opened save:");
	if (map->opened_save == 1)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 240, TEXT_COLOR,
		"yes");
	else
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 240, TEXT_COLOR,
		"no");
}
