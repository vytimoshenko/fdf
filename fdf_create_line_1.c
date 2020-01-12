/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_create_line_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:56:28 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/12 03:27:38 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_wireframe(t_view *view)
{
	pthread_t	thr_0;
	pthread_t	thr_1;

	clean_z_buffer(view);
	get_sin_cos(view);
	pthread_create(&thr_0, NULL, create_verticals, view);
	pthread_create(&thr_1, NULL, create_horizontals, view);
	pthread_join(thr_0, NULL);
	pthread_join(thr_1, NULL);
}

void	*create_verticals(void *thr_data)
{
	int		x;
	int		y;
	t_line	*line;
	t_view	*view;

	view = (t_view *)thr_data;
	line = init_line();
	y = -1;
	while (++y <= view->y_size - 1)
	{
		x = -1;
		while (++x < view->x_size - 1)
			create_ver_line(view, line, x, y);
	}
	destroy_line(line);
	pthread_exit(0);
}

void	*create_horizontals(void *thr_data)
{
	int		x;
	int		y;
	t_line	*line;
	t_view	*view;

	view = (t_view *)thr_data;
	line = init_line();
	x = -1;
	while (++x <= view->x_size - 1)
	{
		y = -1;
		while (++y < view->y_size - 1)
			create_hor_line(view, line, x, y);
	}
	destroy_line(line);
	pthread_exit(0);
}

void	create_ver_line(t_view *view, t_line *line, int x, int y)
{
	line->start->x = x - view->x_size / 2;
	line->start->y = y - view->y_size / 2;
	line->start->z = view->xyz[y][x];
	line->end->x = x + 1 - view->x_size / 2;
	line->end->y = y - view->y_size / 2;
	line->end->z = view->xyz[y][x + 1];
	get_point_color(view, line->start, x, y);
	get_point_color(view, line->end, x + 1, y);
	transform_line(view, line);
	if (!(need_trim_line(view, line)))
		draw_line(view, line);
}

void	create_hor_line(t_view *view, t_line *line, int x, int y)
{
	line->start->x = x - view->x_size / 2;
	line->start->y = y - view->y_size / 2;
	line->start->z = view->xyz[y][x];
	line->end->x = x - view->x_size / 2;
	line->end->y = y + 1 - view->y_size / 2;
	line->end->z = view->xyz[y + 1][x];
	get_point_color(view, line->start, x, y);
	get_point_color(view, line->end, x + 1, y);
	transform_line(view, line);
	if (!(need_trim_line(view, line)))
		draw_line(view, line);
}
