/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_control_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:34:41 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/10 03:25:03 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_cursor_position(t_view *view, int x, int y)
{
	view->x_mouse = x - IMG_INDT_X;
	if (x < IMG_INDT_X || x > IMG_INDT_X + IMG_SIZE_X)
		view->x_mouse = 0;
	view->y_mouse = y - IMG_INDT_Y;
	if (y < IMG_INDT_Y || y > IMG_INDT_Y + IMG_SIZE_Y)
		view->y_mouse = 0;
}

void	control_shift(t_view *view, int key)
{
	if (key == A && view->x_shift >= -IMG_SIZE_X / 2)
		view->x_shift -= 0.1 * IMG_SIZE_X;
	if (key == D && view->x_shift <= IMG_SIZE_X / 2)
		view->x_shift += 0.1 * IMG_SIZE_X;
	if (key == W && view->y_shift >= -IMG_SIZE_Y / 2)
		view->y_shift -= 0.1 * IMG_SIZE_X;
	if (key == S && view->y_shift <= IMG_SIZE_Y / 2)
		view->y_shift += 0.1 * IMG_SIZE_X;
}

void	control_mouse_shift(t_view *view, int x, int y)
{
	if (view->middle_mouse_button == 1)
	{
		view->x_move = view->x_shift - x;
		view->y_move = view->y_shift - y;
		view->middle_mouse_button = 2;
	}
	if (view->middle_mouse_button == 2)
	{
		view->x_shift = view->x_move + x;
		view->y_shift = view->y_move + y;
	}
}

void	control_rotation(t_view *view, int key)
{
	if (key == ARROW_DOWN && rad_to_deg(view->x_angle) < 180)
		view->x_angle += deg_to_rad(5);
	if (key == ARROW_UP && rad_to_deg(view->x_angle) > -180)
		view->x_angle -= deg_to_rad(5);
	if (key == ARROW_RIGHT && rad_to_deg(view->y_angle) < 180)
		view->y_angle += deg_to_rad(5);
	if (key == ARROW_LEFT && rad_to_deg(view->y_angle) > -180)
		view->y_angle -= deg_to_rad(5);
	if (key == CHEVRON_RIGHT && rad_to_deg(view->z_angle) < 180)
		view->z_angle += deg_to_rad(5);
	if (key == CHEVRON_LEFT && rad_to_deg(view->z_angle) > -180)
		view->z_angle -= deg_to_rad(5);
}

void	control_scales(t_view *view, int key)
{
	if (key == Z && view->sf_z < 5)
		view->sf_z++;
	if (key == X && view->sf_z > 0)
		view->sf_z--;
	if ((key == MOUSE_SCROLL_UP || key == PLUS) && view->sf < view->sf_init * 5)
	{
		view->sf += 0.05 * view->sf_init;
		if (view->sf > view->sf_init * 5)
			view->sf = view->sf_init * 5;
	}
	if ((key == MOUSE_SCROLL_DOWN || key == MINUS)
	&& view->sf > view->sf_init * 1.05)
	{
		view->sf -= 0.05 * view->sf_init;
		if (view->sf < view->sf_init * 1.06)
			view->sf = view->sf_init;
	}
}
