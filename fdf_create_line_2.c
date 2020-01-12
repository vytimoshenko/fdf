/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_create_line_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 00:44:12 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/10 20:07:40 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*init_point(void)
{
	t_point *point;

	if (!(point = (t_point *)ft_memalloc(sizeof(t_point))))
		ft_put_errno(PROGRAM_NAME);
	return (point);
}

t_line	*init_line(void)
{
	t_line	*line;

	if (!(line = (t_line *)ft_memalloc(sizeof(t_line))))
		ft_put_errno(PROGRAM_NAME);
	line->start = init_point();
	line->end = init_point();
	line->current = init_point();
	return (line);
}

void	get_sin_cos(t_view *view)
{
	view->sin_x = sin(view->x_angle);
	view->sin_y = sin(view->y_angle);
	view->sin_z = sin(view->z_angle);
	view->cos_x = cos(view->x_angle);
	view->cos_y = cos(view->y_angle);
	view->cos_z = cos(view->z_angle);
}

void	transform_line(t_view *view, t_line *line)
{
	scale_line(view, line);
	x_rotate_line(view, line);
	y_rotate_line(view, line);
	z_rotate_line(view, line);
	if (view->perspective_projection == 1)
		get_perspective(view, line);
	shift_line(view, line);
}

void	destroy_line(t_line *line)
{
	free(line->start);
	free(line->end);
	free(line->current);
	line->start = NULL;
	line->end = NULL;
	line->current = NULL;
	free(line);
	line = NULL;
}
