/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_control_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 22:52:00 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/10 03:26:25 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	control_projections(t_view *view, int key)
{
	if (key == RETURN)
	{
		isometric_projections(view);
		if (view->isometric_projection != 3)
			view->isometric_projection++;
		else
			view->isometric_projection = 0;
	}
	if (key == SPACE)
	{
		straight_projections(view);
		if (view->straight_projection != 2)
			view->straight_projection++;
		else
			view->straight_projection = 0;
	}
}

void	straight_projections(t_view *view)
{
	if (view->straight_projection == 0)
	{
		view->x_angle = deg_to_rad(0);
		view->y_angle = deg_to_rad(0);
		view->z_angle = deg_to_rad(0);
	}
	if (view->straight_projection == 1)
	{
		view->x_angle = deg_to_rad(-90);
		view->y_angle = deg_to_rad(0);
		view->z_angle = deg_to_rad(0);
	}
	if (view->straight_projection == 2)
	{
		view->x_angle = deg_to_rad(-90);
		view->y_angle = deg_to_rad(90);
		view->z_angle = deg_to_rad(0);
	}
	reset_shift_and_scale(view);
}

void	isometric_projections(t_view *view)
{
	if (view->isometric_projection == 0)
	{
		view->x_angle = deg_to_rad(-30);
		view->y_angle = deg_to_rad(-30);
		view->z_angle = deg_to_rad(30);
	}
	if (view->isometric_projection == 1)
	{
		view->x_angle = deg_to_rad(-150);
		view->y_angle = deg_to_rad(30);
		view->z_angle = deg_to_rad(30);
	}
	if (view->isometric_projection == 2)
	{
		view->x_angle = deg_to_rad(30);
		view->y_angle = deg_to_rad(-150);
		view->z_angle = deg_to_rad(150);
	}
	if (view->isometric_projection == 3)
	{
		view->x_angle = deg_to_rad(-30);
		view->y_angle = deg_to_rad(30);
		view->z_angle = deg_to_rad(-30);
	}
	reset_shift_and_scale(view);
}

void	control_perspective(t_view *view, int key)
{
	if (key == P)
	{
		if (view->perspective_projection == 0)
			view->perspective_projection = 1;
		else
		{
			view->perspective_projection = 0;
			view->persp_rate = INIT_PERSPECTIVE_RATE;
		}
	}
	if (key == PAGE_UP && view->perspective_projection == 1 &&
	view->persp_rate > INIT_PERSPECTIVE_RATE / 4)
		view->persp_rate /= 2;
	if (key == PAGE_DOWN && view->perspective_projection == 1 &&
	view->persp_rate < INIT_PERSPECTIVE_RATE)
		view->persp_rate *= 2;
}
