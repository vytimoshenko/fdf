/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_put_info_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 03:05:11 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/10 03:06:32 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_control_keys_1(t_view *view)
{
	int pos_x;
	int pos_y;

	pos_x = WIN_SIZE_X - 340;
	pos_y = 780;
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 70, pos_y,
	TEXT_COLOR, "CONTROL");
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x, pos_y + 30,
	TEXT_COLOR, "Move:        W/A/S/D");
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x, pos_y + 50,
	TEXT_COLOR, "             middle mouse button");
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x, pos_y + 80,
	TEXT_COLOR, "Rotate X/Y:  arrows");
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x, pos_y + 100,
	TEXT_COLOR, "Rotate Z:    </>");
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x, pos_y + 130,
	TEXT_COLOR, "Zoom:        +/-");
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x, pos_y + 150,
	TEXT_COLOR, "             mouse wheel scroll");
}

void	put_control_keys_2(t_view *view)
{
	int pos_x;
	int pos_y;

	pos_x = WIN_SIZE_X - 340;
	pos_y = 780;
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x, pos_y + 180,
	TEXT_COLOR, "Z scale:     Z/X");
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x, pos_y + 210,
	TEXT_COLOR, "View:        Enter/Space");
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x, pos_y + 240,
	TEXT_COLOR, "Perspective: P");
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 70, pos_y + 260,
	TEXT_COLOR, "rate: Page up/Page down");
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x, pos_y + 290,
	TEXT_COLOR, "Color:       C");
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x, pos_y + 320,
	TEXT_COLOR, "Reset:       R");
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x, pos_y + 350,
	TEXT_COLOR, "Exit:        ESC");
}

void	put_mouse_position(t_view *view)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = IMG_INDT_X + 20;
	pos_y = WIN_SIZE_Y - 40;
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x, pos_y,
	TEXT_COLOR, "X:");
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 20, pos_y,
	TEXT_COLOR, str = ft_itoa(view->x_mouse));
	free(str);
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 80, pos_y,
	TEXT_COLOR, "Y:");
	mlx_string_put(view->mlx_ptr, view->win_ptr, pos_x + 100, pos_y,
	TEXT_COLOR, str = ft_itoa(view->y_mouse));
	free(str);
}
