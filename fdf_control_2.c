/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_control_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 22:52:00 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/25 04:46:13 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	control_projections(t_status *status, int key)
{
	if (key == RETURN)
	{
		if (status->isometric_projection != 3)
			status->isometric_projection++;
		else
			status->isometric_projection = 0;
		isometric_projections(status);
	}
	else if (key == SPACE)
	{
		if (status->straight_projection != 2)
			status->straight_projection++;
		else
			status->straight_projection = 0;
		straight_projections(status);
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
	else if (status->straight_projection == 1)
	{
		status->x_angle = deg_to_rad(-90);
		status->y_angle = deg_to_rad(0);
		status->z_angle = deg_to_rad(0);
	}
	else if (status->straight_projection == 2)
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
	else if (status->isometric_projection == 1)
	{
		status->x_angle = deg_to_rad(30);
		status->y_angle = deg_to_rad(-30);
		status->z_angle = deg_to_rad(150);
	}
	else if (status->isometric_projection == 2)
	{
		status->x_angle = deg_to_rad(30);
		status->y_angle = deg_to_rad(30);
		status->z_angle = deg_to_rad(-150);
	}
	else if (status->isometric_projection == 3)
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
		if (status->perspective_projection == FALSE)
			status->perspective_projection = TRUE;
		else
		{
			status->perspective_projection = FALSE;
			status->persp_rate = INIT_PERSPECTIVE_RATE;
		}
	}
	else if (key == PAGE_UP && status->perspective_projection == 1 &&
	status->persp_rate > INIT_PERSPECTIVE_RATE / 4)
		status->persp_rate /= 2;
	else if (key == PAGE_DOWN && status->perspective_projection == 1 &&
	status->persp_rate < INIT_PERSPECTIVE_RATE)
		status->persp_rate *= 2;
}
