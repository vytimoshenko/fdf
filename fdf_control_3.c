/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_control_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 22:52:00 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/15 03:58:59 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	control_scale(t_status *status, int key)
{
	if ((key == MOUSE_SCROLL_UP || key == PLUS) &&
	status->sf < status->sf_init * 5)
	{
		status->sf += 0.05 * status->sf_init;
		if (status->sf > status->sf_init * 5)
			status->sf = status->sf_init * 5;
	}
	else if ((key == MOUSE_SCROLL_DOWN || key == MINUS)
	&& status->sf > status->sf_init * 1.05)
	{
		status->sf -= 0.05 * status->sf_init;
		if (status->sf < status->sf_init * 1.06)
			status->sf = status->sf_init;
	}
}

void	control_z_scale(t_status *status, int key)
{
	if (key == Z)
		control_z_scale_plus(status);
	else if (key == X)
		control_z_scale_minus(status);
}

void	control_z_scale_plus(t_status *status)
{
	if (status->sf_z == 0.0)
		status->sf_z = 0.01;
	else if (status->sf_z == 0.01)
		status->sf_z = 0.03;
	else if (status->sf_z == 0.03)
		status->sf_z = 0.05;
	else if (status->sf_z == 0.05)
		status->sf_z = 0.1;
	else if (status->sf_z == 0.1)
		status->sf_z = 0.25;
	else if (status->sf_z == 0.25)
		status->sf_z = 0.5;
	else if (status->sf_z == 0.5)
		status->sf_z = 1.0;
	else if (status->sf_z == 1.0)
		status->sf_z = 2.0;
	else if (status->sf_z == 2.0)
		status->sf_z = 4.0;
}

void	control_z_scale_minus(t_status *status)
{
	if (status->sf_z == 4.0)
		status->sf_z = 2.0;
	else if (status->sf_z == 2.0)
		status->sf_z = 1.0;
	else if (status->sf_z == 1.0)
		status->sf_z = 0.5;
	else if (status->sf_z == 0.5)
		status->sf_z = 0.25;
	else if (status->sf_z == 0.25)
		status->sf_z = 0.1;
	else if (status->sf_z == 0.1)
		status->sf_z = 0.05;
	else if (status->sf_z == 0.05)
		status->sf_z = 0.03;
	else if (status->sf_z == 0.03)
		status->sf_z = 0.01;
	else if (status->sf_z == 0.01)
		status->sf_z = 0.0;
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
