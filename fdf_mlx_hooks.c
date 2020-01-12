/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 19:44:00 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/10 00:07:13 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_move(int x, int y, void *param)
{
	t_view	*view;

	view = (t_view *)param;
	get_cursor_position(view, x, y);
	control_mouse_shift(view, x, y);
	redraw(view);
	return (0);
}

int		mouse_key_press(int key, int x, int y, void *param)
{
	t_view	*view;

	view = (t_view *)param;
	if (key == MIDDLE_MOUSE_BUTTON)
		view->middle_mouse_button = 1;
	if (key == MOUSE_SCROLL_UP || key == MOUSE_SCROLL_DOWN)
		control_scales(view, key);
	redraw(view);
	return (0);
}

int		mouse_key_release(int key, int x, int y, void *param)
{
	t_view	*view;

	view = (t_view *)param;
	if (key == MIDDLE_MOUSE_BUTTON)
		view->middle_mouse_button = 0;
	return (0);
}

int		keyboard_key_press(int key, void *param)
{
	t_view	*view;

	view = (t_view *)param;
	control_shift(view, key);
	control_rotation(view, key);
	control_scales(view, key);
	control_projections(view, key);
	control_perspective(view, key);
	if (key == C)
		control_colors(view, key);
	if (key == R)
		full_reset(view);
	redraw(view);
	if (key == ESC)
		exit(0);
	return (0);
}

int		close_window(void *param)
{
	(void)param;
	exit(0);
}
