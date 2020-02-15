/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transform_line_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:43:17 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/15 02:22:11 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	x_rotate_line(t_status *status, t_line *line)
{
	float y_temp;
	float z_temp;

	y_temp = line->start->y * status->cos_x + line->start->z * status->sin_x;
	z_temp = -line->start->y * status->sin_x + line->start->z * status->cos_x;
	line->start->y = y_temp;
	line->start->z = z_temp;
	y_temp = line->end->y * status->cos_x + line->end->z * status->sin_x;
	z_temp = -line->end->y * status->sin_x + line->end->z * status->cos_x;
	line->end->y = y_temp;
	line->end->z = z_temp;
}

void	y_rotate_line(t_status *status, t_line *line)
{
	float x_temp;
	float z_temp;

	x_temp = line->start->x * status->cos_y + line->start->z * status->sin_y;
	z_temp = -line->start->x * status->sin_y + line->start->z * status->cos_y;
	line->start->x = x_temp;
	line->start->z = z_temp;
	x_temp = line->end->x * status->cos_y + line->end->z * status->sin_y;
	z_temp = -line->end->x * status->sin_y + line->end->z * status->cos_y;
	line->end->x = x_temp;
	line->end->z = z_temp;
}

void	z_rotate_line(t_status *status, t_line *line)
{
	float angle;
	float x_temp;
	float y_temp;

	angle = status->z_angle;
	x_temp = line->start->x * status->cos_z - line->start->y * status->sin_z;
	y_temp = line->start->x * status->sin_z + line->start->y * status->cos_z;
	line->start->x = x_temp;
	line->start->y = y_temp;
	x_temp = line->end->x * status->cos_z - line->end->y * status->sin_z;
	y_temp = line->end->x * status->sin_z + line->end->y * status->cos_z;
	line->end->x = x_temp;
	line->end->y = y_temp;
}

void	scale_line(t_status *status, t_line *line)
{
	line->start->x *= status->sf;
	line->start->y *= status->sf;
	line->start->z *= status->sf_z * status->sf / status->sf_init;
	line->end->x *= status->sf;
	line->end->y *= status->sf;
	line->end->z *= status->sf_z * status->sf / status->sf_init;
}

void	shift_line(t_status *status, t_line *line)
{
	int x_align;
	int y_align;

	x_align = IMG_SIZE_W / 2;
	y_align = IMG_SIZE_H / 2;
	line->start->x = line->start->x + x_align + status->x_shift;
	line->start->y = line->start->y + y_align + status->y_shift;
	line->end->x = line->end->x + x_align + status->x_shift;
	line->end->y = line->end->y + y_align + status->y_shift;
}
