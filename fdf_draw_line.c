/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:53:42 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/15 22:32:57 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_current_point(t_global *global, t_line *line, int x, int y)
{
	line->current->x = x;
	line->current->y = y;
	line->current->z = (line->start->z + line->end->z) / 2;
	if (global->status->color_scheme != 2)
		line->current->color = get_gradient(line);
	else
		line->current->color = line->start->color;
	put_pixel(global->mlx, line);
}

void	draw_line_low(t_global *global, t_line *line)
{
	int		x;
	int		y;
	int		yi;
	float	d;

	yi = 1;
	if (line->dy < 0)
	{
		yi = -1;
		line->dy = -line->dy;
	}
	d = 2 * line->dy - line->dx;
	x = line->start->x - 1;
	y = line->start->y;
	while (++x <= line->end->x)
	{
		if (d > 0)
		{
			y = y + yi;
			d = d - 2 * line->dx;
		}
		d = d + 2 * line->dy;
		draw_current_point(global, line, x, y);
	}
}

void	draw_line_high(t_global *global, t_line *line)
{
	int		x;
	int		y;
	int		xi;
	float	d;

	xi = 1;
	if (line->dx < 0)
	{
		xi = -1;
		line->dx = -line->dx;
	}
	d = 2 * line->dx - line->dy;
	x = line->start->x;
	y = line->start->y - 1;
	while (++y <= line->end->y)
	{
		if (d > 0)
		{
			x = x + xi;
			d = d - 2 * line->dy;
		}
		d = d + 2 * line->dx;
		draw_current_point(global, line, x, y);
	}
}

void	swap_line_ends(t_line *line)
{
	float	x_temp;
	float	y_temp;
	float	z_temp;
	int		color_temp;

	x_temp = line->start->x;
	y_temp = line->start->y;
	z_temp = line->start->z;
	color_temp = line->start->color;
	line->start->x = line->end->x;
	line->start->y = line->end->y;
	line->start->z = line->end->z;
	line->start->color = line->end->color;
	line->end->x = x_temp;
	line->end->y = y_temp;
	line->end->z = z_temp;
	line->end->color = color_temp;
	line->dx = line->end->x - line->start->x;
	line->dy = line->end->y - line->start->y;
}

void	draw_line(t_global *global, t_line *line)
{
	if (line)
	{
		line->dx = line->end->x - line->start->x;
		line->dy = line->end->y - line->start->y;
		if (fabs(line->end->y - line->start->y) <
			fabs(line->end->x - line->start->x))
		{
			if (line->start->x > line->end->x)
				swap_line_ends(line);
			draw_line_low(global, line);
		}
		else
		{
			if (line->start->y > line->end->y)
				swap_line_ends(line);
			draw_line_high(global, line);
		}
	}
}
