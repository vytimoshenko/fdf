/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_put_info_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:27:57 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/25 04:43:57 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_info_to_window(t_global *global)
{
	put_map_summary_1(global->map, global->mlx);
	put_map_summary_2(global->map, global->mlx);
	put_map_summary_3(global->map, global->mlx);
	put_loaded_file_names(global->map, global->mlx);
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
	"Size:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 30, TEXT_COLOR,
	str = ft_itoa(map->points));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 100, pos_y + 60, TEXT_COLOR,
	"x:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 60, TEXT_COLOR,
	str = ft_itoa(map->x_size));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 100, pos_y + 80, TEXT_COLOR,
	"y:");
}

void	put_map_summary_2(t_map *map, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 340;
	pos_y = 50;
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 80, TEXT_COLOR,
	str = ft_itoa(map->y_size));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 100, pos_y + 100, TEXT_COLOR,
	"z:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 100, TEXT_COLOR,
	str = ft_itoa(map->z_size));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 60, pos_y + 130, TEXT_COLOR,
	"min z:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 130, TEXT_COLOR,
	str = ft_itoa(map->z_min));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 60, pos_y + 150, TEXT_COLOR,
	"max z:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 150, TEXT_COLOR,
	str = ft_itoa(map->z_max));
	free(str);
}

void	put_map_summary_3(t_map *map, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;

	pos_x = WIN_SIZE_W - 340;
	pos_y = 50;
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 180,
	TEXT_COLOR, "Color:");
	if (map->has_color == TRUE)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 180, TEXT_COLOR,
		"yes");
	else
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 180, TEXT_COLOR,
		"no");
}

void	put_loaded_file_names(t_map *map, t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->win, 200, WIN_SIZE_H - 30, TEXT_COLOR,
	"map file opened:");
	mlx_string_put(mlx->mlx, mlx->win, 370, WIN_SIZE_H - 30, TEXT_COLOR,
	map->map_name_with_path);
	if (map->save_name)
	{
		mlx_string_put(mlx->mlx, mlx->win, 1000, WIN_SIZE_H - 30, TEXT_COLOR,
		"save file loaded:");
		mlx_string_put(mlx->mlx, mlx->win, 1180, WIN_SIZE_H - 30, TEXT_COLOR,
		map->save_name);
	}
}
