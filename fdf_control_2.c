/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_control_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 22:52:00 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/13 17:52:19 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	control_projections(t_status *status, int key)
{
	if (key == RETURN)
	{
		isometric_projections(status);
		if (status->isometric_projection != 3)
			status->isometric_projection++;
		else
			status->isometric_projection = 0;
	}
	if (key == SPACE)
	{
		straight_projections(status);
		if (status->straight_projection != 2)
			status->straight_projection++;
		else
			status->straight_projection = 0;
	}
}

void	straight_projections(t_status *status)
{
	if (status->straight_projection == 0)
	{
		status->x_angle = deg_to_rad(0);
		status->y_angle = deg_to_rad(0);
		status->z_angle = deg_to_rad(0);
	}
	if (status->straight_projection == 1)
	{
		status->x_angle = deg_to_rad(-90);
		status->y_angle = deg_to_rad(0);
		status->z_angle = deg_to_rad(0);
	}
	if (status->straight_projection == 2)
	{
		status->x_angle = deg_to_rad(-90);
		status->y_angle = deg_to_rad(90);
		status->z_angle = deg_to_rad(0);
	}
	reset_shift_and_scale(status);
}

void	isometric_projections(t_status *status)
{
	if (status->isometric_projection == 0)
	{
		status->x_angle = deg_to_rad(-30);
		status->y_angle = deg_to_rad(-30);
		status->z_angle = deg_to_rad(30);
	}
	if (status->isometric_projection == 1)
	{
		status->x_angle = deg_to_rad(-150);
		status->y_angle = deg_to_rad(30);
		status->z_angle = deg_to_rad(30);
	}
	if (status->isometric_projection == 2)
	{
		status->x_angle = deg_to_rad(30);
		status->y_angle = deg_to_rad(-150);
		status->z_angle = deg_to_rad(150);
	}
	if (status->isometric_projection == 3)
	{
		status->x_angle = deg_to_rad(-30);
		status->y_angle = deg_to_rad(30);
		status->z_angle = deg_to_rad(-30);
	}
	reset_shift_and_scale(status);
}

void	control_perspective(t_status *status, int key)
{
	if (key == P)
	{
		if (status->perspective_projection == 0)
			status->perspective_projection = 1;
		else
		{
			status->perspective_projection = 0;
			status->persp_rate = INIT_PERSPECTIVE_RATE;
		}
	}
	if (key == PAGE_UP && status->perspective_projection == 1 &&
	status->persp_rate > INIT_PERSPECTIVE_RATE / 4)
		status->persp_rate /= 2;
	if (key == PAGE_DOWN && status->perspective_projection == 1 &&
	status->persp_rate < INIT_PERSPECTIVE_RATE)
		status->persp_rate *= 2;
}

void	control_colors(t_map *map, t_status *status)
{
	if (status->color_scheme != 4)
		status->color_scheme++;
	else
		status->color_scheme = 0;
	if (status->color_scheme == 0 && map->has_color == 0)
		status->color_scheme++;
}
