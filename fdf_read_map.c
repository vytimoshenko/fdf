/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:13:41 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/08 19:37:22 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_max_min_z(t_view *view, int x, int y)
{
	if (view->z_max < view->xyz[y][x])
		view->z_max = view->xyz[y][x];
	if (view->z_min > view->xyz[y][x])
		view->z_min = view->xyz[y][x];
	view->z_size = view->z_max - view->z_min;
}

void	calc_scale(t_view *view)
{
	float sf;

	sf = (IMG_SIZE_X - 10) / (1.2 * (view->x_size - 1));
	if (sf > (IMG_SIZE_Y - 10) / (1.2 * (view->y_size - 1)))
		sf = (IMG_SIZE_Y - 10) / (1.2 * (view->y_size - 1));
	view->sf = sf;
	view->sf_init = sf;
}

void	trim_file_name(t_view *view, char *file_name)
{
	char *trimmed_file_name;
	char *file_name_end;

	if (ft_strlen(file_name) > 16)
	{
		trimmed_file_name = ft_strnew(16);
		ft_strncpy(trimmed_file_name, file_name, 16);
		file_name_end = ft_strnew(3);
		file_name_end[0] = '.';
		file_name_end[1] = '.';
		file_name_end[2] = '.';
		file_name = ft_strjoin(trimmed_file_name, file_name_end);
		ft_strdel(&trimmed_file_name);
		ft_strdel(&file_name_end);
	}
	view->map_name = file_name;
}

void	split_line(t_view *view, char *line, int y)
{
	char	**split_line;

	if (!(view->xyz[y] = malloc(sizeof(int) * view->x_size)))
		ft_put_errno(PROGRAM_NAME);
	if (!(view->clr[y] = malloc(sizeof(int) * view->x_size)))
		ft_put_errno(PROGRAM_NAME);
	split_line = ft_strsplit(line, ' ');
	free(line);
	save_map_line(view, split_line, y);
	ft_arrdel(split_line);
	free(split_line);
}

void	read_map(t_view *view, char *file_name)
{
	int		fd;
	char	*line;
	int		y;

	fd = open(file_name, O_RDONLY);
	if (fd < 0 || read(fd, NULL, 0) == -1)
		ft_put_errno(PROGRAM_NAME);
	if (!(view->xyz = malloc(sizeof(int *) * view->y_size)))
		ft_put_errno(PROGRAM_NAME);
	if (!(view->clr = malloc(sizeof(int *) * view->y_size)))
		ft_put_errno(PROGRAM_NAME);
	y = -1;
	while (++y < view->y_size)
	{
		if (!(get_next_line(fd, &line)))
			break ;
		split_line(view, line, y);
	}
	view->points = view->y_size * view->x_size;
	trim_file_name(view, file_name);
	calc_scale(view);
	init_z_buffer(view);
}
