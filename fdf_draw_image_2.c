/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_create_line_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 00:44:12 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/12 22:03:38 by mperseus         ###   ########.fr       */
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

void	get_sin_cos(t_status *status)
{
	status->sin_x = sin(status->x_angle);
	status->sin_y = sin(status->y_angle);
	status->sin_z = sin(status->z_angle);
	status->cos_x = cos(status->x_angle);
	status->cos_y = cos(status->y_angle);
	status->cos_z = cos(status->z_angle);
}

void	transform_line(t_status *status, t_line *line)
{
	scale_line(status, line);
	x_rotate_line(status, line);
	y_rotate_line(status, line);
	z_rotate_line(status, line);
	if (status->perspective_projection == 1)
		get_perspective(status, line);
	shift_line(status, line);
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
