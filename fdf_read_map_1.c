/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_map_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:13:41 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/13 03:37:19 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_max_min_z(t_map *map, int x, int y)
{
	if (map->z_max < map->xyz[y][x])
		map->z_max = map->xyz[y][x];
	if (map->z_min > map->xyz[y][x])
		map->z_min = map->xyz[y][x];
	map->z_size = map->z_max - map->z_min;
}

void	trim_file_name(t_map *map, char *file_name)
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
		file_name = ft_strjoin(trimmed_file_name, (char *)file_name_end);
		ft_strdel(&trimmed_file_name);
		ft_strdel(&file_name_end);
	}
	map->map_name = file_name;
}

void	split_line(t_map *map, char *line, int y)
{
	char	**split_line;

	if (!(map->xyz[y] = malloc(sizeof(int) * map->x_size)))
		ft_put_errno(PROGRAM_NAME);
	if (!(map->clr[y] = malloc(sizeof(int) * map->x_size)))
		ft_put_errno(PROGRAM_NAME);
	split_line = ft_strsplit(line, ' ');
	free(line);
	save_map_line(map, split_line, y);
	ft_arrdel(split_line);
	free(split_line);
}

void	read_map(t_map *map, char *file_name)
{
	int		fd;
	char	*line;
	int		y;

	fd = open(file_name, O_RDONLY);
	if (fd < 0 || read(fd, NULL, 0) == -1)
		ft_put_errno(PROGRAM_NAME);
	if (!(map->xyz = malloc(sizeof(int *) * map->y_size)))
		ft_put_errno(PROGRAM_NAME);
	if (!(map->clr = malloc(sizeof(int *) * map->y_size)))
		ft_put_errno(PROGRAM_NAME);
	y = -1;
	while (++y < map->y_size)
	{
		if (!(get_next_line(fd, &line)))
			break ;
		split_line(map, line, y);
	}
	map->points = map->y_size * map->x_size;
	trim_file_name(map, file_name);
}
