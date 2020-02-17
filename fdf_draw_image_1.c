/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_image_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:56:28 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/17 20:15:34 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_image(t_global *global)
{
	pthread_t	thr_0;
	pthread_t	thr_1;

	clean_z_buffer(global->mlx);
	get_sin_cos(global->status);
	// ft_putnbr((int)sysconf(_SC_NPROCESSORS_ONLN));
	pthread_create(&thr_0, NULL, create_verticals, global);
	pthread_create(&thr_1, NULL, create_horizontals, global);
	pthread_join(thr_0, NULL);
	pthread_join(thr_1, NULL);
	// #pragma omp parallel sections
	// {
	// 	#pragma omp section
	// 		create_verticals(global);
	// 	#pragma omp section
	// 		create_horizontals(global);
	// }
}

void	*create_verticals(void *param)
{
	int			x;
	int			y;
	t_line		*line;
	t_global	*global;

	global = (t_global *)param;
	line = init_line();
	y = -1;
	#pragma omp parallel num_threads(4)
	while (++y <= global->map->y_size - 1)
	{
		x = -1;
		while (++x < global->map->x_size - 1)
			create_ver_line(global, line, x, y);
	}
	destroy_line(line);
	// return (0);
	pthread_exit(0);
}

void	*create_horizontals(void *param)
{
	int			x;
	int			y;
	t_line		*line;
	t_global	*global;

	global = (t_global *)param;
	line = init_line();
	x = -1;
	#pragma omp parallel num_threads(4)
	while (++x <= global->map->x_size - 1)
	{
		y = -1;
		while (++y < global->map->y_size - 1)
			create_hor_line(global, line, x, y);
	}
	destroy_line(line);
	return (0);
	// pthread_exit(0);
}

void	create_ver_line(t_global *global, t_line *line, int x, int y)
{
	line->start->x = x - global->map->x_size / 2;
	line->start->y = y - global->map->y_size / 2;
	line->start->z = global->map->xyz[y][x];
	line->end->x = x + 1 - global->map->x_size / 2;
	line->end->y = y - global->map->y_size / 2;
	line->end->z = global->map->xyz[y][x + 1];
	get_point_color(global, line->start, x, y);
	get_point_color(global, line->end, x + 1, y);
	transform_line(global->status, line);
	if (!(need_trim_line(line)))
		draw_line(global, line);
}

void	create_hor_line(t_global *global, t_line *line, int x, int y)
{
	line->start->x = x - global->map->x_size / 2;
	line->start->y = y - global->map->y_size / 2;
	line->start->z = global->map->xyz[y][x];
	line->end->x = x - global->map->x_size / 2;
	line->end->y = y + 1 - global->map->y_size / 2;
	line->end->z = global->map->xyz[y + 1][x];
	get_point_color(global, line->start, x, y);
	get_point_color(global, line->end, x + 1, y);
	transform_line(global->status, line);
	if (!(need_trim_line(line)))
		draw_line(global, line);
}
