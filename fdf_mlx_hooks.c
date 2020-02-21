/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 19:44:00 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/21 04:16:31 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_move(int x, int y, t_global *global)
{
	get_mouse_position(global->status, x, y);
	control_mouse_shift(global->status, x, y);
	if (global->status->middle_mouse_button)
		draw(global);
	else
		update_info_only(global);
	return (0);
}

int		mouse_key_press(int key, int x, int y, t_global *global)
{
	(void)x;
	(void)y;
	if (key == MIDDLE_MOUSE_BUTTON)
		global->status->middle_mouse_button = 1;
	else if (key == MOUSE_SCROLL_UP || key == MOUSE_SCROLL_DOWN)
		control_scale(global->status, key);
	else
		return (0);
	draw(global);
	return (0);
}

int		mouse_key_release(int key, int x, int y, t_global *global)
{
	(void)x;
	(void)y;
	if (key == MIDDLE_MOUSE_BUTTON)
		global->status->middle_mouse_button = 0;
	return (0);
}

int		keyboard_key_press(int key, t_global *global)
{
	if (key == A || key == D || key == W || key == S)
		control_shift(global->status, key);
	else if (key == ARROW_UP || key == ARROW_DOWN || key == ARROW_RIGHT ||
	key == ARROW_LEFT || key == MORE || key == LESS)
		control_rotation(global->status, key);
	else if (key == PLUS || key == MINUS)
		control_scale(global->status, key);
	else if (key == Z || key == X)
		control_z_scale(global->status, key);
	else if (key == RETURN || key == SPACE)
		control_projections(global->status, key);
	else if (key == P || key == PAGE_UP || key == PAGE_DOWN)
		control_perspective(global->status, key);
	else if (key == C)
		control_colors(global->map, global->status);
	else if (key == R)
		full_reset(global->map, global->status);
	else if (key == M)
	{
		save_status(global->map, global->status, global->mlx);
		return (0);
	}
	else if (key == ESC)
		close_window(global);
	else
		return (0);
	draw(global);
	return (0);
}

int		close_window(t_global *global)
{
	clean_mlx(global->mlx);
	exit(0);
}
