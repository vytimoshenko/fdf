/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_put_info_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:27:57 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/10 03:07:50 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_map_summary_1(t_view *view)
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
	TEXT_COLOR, view->map_name);
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x, pos_y + 60,
	TEXT_COLOR, "Size:");
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 130, pos_y + 60,
	TEXT_COLOR, str = ft_itoa(view->points));
	free(str);
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 100, pos_y + 90,
	TEXT_COLOR, "X:");
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 130, pos_y + 90,
	TEXT_COLOR, str = ft_itoa(view->x_size));
	free(str);
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 100, pos_y + 110,
	TEXT_COLOR, "Y:");
}

void	put_map_summary_2(t_view *view)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_X - 340;
	pos_y = 50;
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 130, pos_y + 110,
	TEXT_COLOR, str = ft_itoa(view->y_size));
	free(str);
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 100, pos_y + 130,
	TEXT_COLOR, "Z:");
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 130, pos_y + 130,
	TEXT_COLOR, str = ft_itoa(view->z_size));
	free(str);
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 60, pos_y + 160,
	TEXT_COLOR, "min Z:");
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 130, pos_y + 160,
	TEXT_COLOR, str = ft_itoa(view->z_min));
	free(str);
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 60, pos_y + 180,
	TEXT_COLOR, "max Z:");
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 130, pos_y + 180,
	TEXT_COLOR, str = ft_itoa(view->z_max));
	free(str);
}

void	put_map_summary_3(t_view *view)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_X - 340;
	pos_y = 50;
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x, pos_y + 210,
	TEXT_COLOR, "Color:");
	if (view->has_color == 1)
		mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 130, pos_y + 210,
		TEXT_COLOR, "yes");
	else
		mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 130, pos_y + 210,
		TEXT_COLOR, "no");
}
