/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transform_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:43:17 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/10 03:36:29 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	x_rotate_line(t_view *view, t_line *line)
{
	float y_temp;
	float z_temp;

	y_temp = line->start->y * view->cos_x + line->start->z * view->sin_x;
	z_temp = -line->start->y * view->sin_x + line->start->z * view->cos_x;
	line->start->y = y_temp;
	line->start->z = z_temp;
	y_temp = line->end->y * view->cos_x + line->end->z * view->sin_x;
	z_temp = -line->end->y * view->sin_x + line->end->z * view->cos_x;
	line->end->y = y_temp;
	line->end->z = z_temp;
}

void	y_rotate_line(t_view *view, t_line *line)
{
	float x_temp;
	float z_temp;

	x_temp = line->start->x * view->cos_y + line->start->z * view->sin_y;
	z_temp = -line->start->x * view->sin_y + line->start->z * view->cos_y;
	line->start->x = x_temp;
	line->start->z = z_temp;
	x_temp = line->end->x * view->cos_y + line->end->z * view->sin_y;
	z_temp = -line->end->x * view->sin_y + line->end->z * view->cos_y;
	line->end->x = x_temp;
	line->end->z = z_temp;
}

void	z_rotate_line(t_view *view, t_line *line)
{
	float angle;
	float x_temp;
	float y_temp;

	angle = view->z_angle;
	x_temp = line->start->x * view->cos_z - line->start->y * view->sin_z;
	y_temp = line->start->x * view->sin_z + line->start->y * view->cos_z;
	line->start->x = x_temp;
	line->start->y = y_temp;
	x_temp = line->end->x * view->cos_z - line->end->y * view->sin_z;
	y_temp = line->end->x * view->sin_z + line->end->y * view->cos_z;
	line->end->x = x_temp;
	line->end->y = y_temp;
}

void	scale_line(t_view *view, t_line *line)
{
	line->start->x *= view->sf;
	line->start->y *= view->sf;
	line->start->z *= view->sf_z * view->sf / view->sf_init;
	line->end->x *= view->sf;
	line->end->y *= view->sf;
	line->end->z *= view->sf_z * view->sf / view->sf_init;
}

void	shift_line(t_view *view, t_line *line)
{
	int x_align;
	int y_align;

	x_align = IMG_SIZE_X / 2;
	y_align = IMG_SIZE_Y / 2;
	line->start->x = line->start->x + x_align + view->x_shift;
	line->start->y = line->start->y + y_align + view->y_shift;
	line->end->x = line->end->x + x_align + view->x_shift;
	line->end->y = line->end->y + y_align + view->y_shift;
}
