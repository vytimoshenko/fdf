/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 19:00:23 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/10 03:33:19 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	get_grade(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		get_light(int start, int end, double grade)
{
	return ((int)((1 - grade) * start + grade * end));
}

int		get_gradient(t_line *line)
{
	int		red;
	int		green;
	int		blue;
	double	grade;

	if (line->end->x - line->start->x > line->end->y - line->start->y)
		grade = get_grade(line->start->x, line->end->x, line->current->x);
	else
		grade = get_grade(line->start->y, line->end->y, line->current->y);
	red = get_light((line->start->color >> 16) & 0xFF,
	(line->end->color >> 16) & 0xFF, grade);
	green = get_light((line->start->color >> 8) & 0xFF,
	(line->end->color >> 8) & 0xFF, grade);
	blue = get_light(line->start->color & 0xFF, line->end->color & 0xFF, grade);
	return ((red << 16) | (green << 8) | blue);
}

void	get_z_color(t_view *view, t_point *point)
{
	if (point->z <= 0)
	{
		if (view->color_scheme == 1)
			point->color = BOTTOM_COLOR_1;
		else
			point->color = BOTTOM_COLOR_2;
	}
	else if ((point->z >= (float)view->z_min * 2 / 3) &&
	(point->z <= (float)view->z_max * 2 / 3))
	{
		if (view->color_scheme == 1)
			point->color = MIDDLE_COLOR_1;
		else
			point->color = MIDDLE_COLOR_2;
	}
	else
	{
		if (view->color_scheme == 1)
			point->color = TOP_COLOR_1;
		else
			point->color = TOP_COLOR_2;
	}
}

void	get_point_color(t_view *view, t_point *point, int x, int y)
{
	if (view->color_scheme == 0)
	{
		if (view->clr[y][x] != 0)
			point->color = view->clr[y][x];
		else
			point->color = NO_COLOR;
	}
	else if (view->color_scheme == 1 || view->color_scheme == 2)
		get_z_color(view, point);
	else if (view->color_scheme == 3)
		point->color = SINGLE_COLOR_1;
	else
		point->color = SINGLE_COLOR_2;
}
