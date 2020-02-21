/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_map_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:13:41 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/21 22:19:54 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	load_saved_status(t_map *map, char *file_name)
{
	int		fd;
	int		ret;

	ret = 1;
	fd = open(file_name, O_RDONLY);
	if (fd < 0 || read(fd, NULL, 0) == -1)
		ft_put_errno(PROGRAM_NAME);
	close(fd);
	fd = open(file_name, O_RDWR);
	if (fd < 0)
		ft_put_errno(PROGRAM_NAME);
	map->save_name = ft_strdup(file_name);
	if (!(map->loaded_save = (t_status *)malloc(sizeof(t_status))))
		ft_put_errno(PROGRAM_NAME);
	if (!(ret = read(fd, map->loaded_save, sizeof(t_status))))
		ft_put_errno(PROGRAM_NAME);
	close(fd);
	map->opened_save = 1;
}

void	get_max_min_z(t_map *map, int x, int y)
{
	if (map->z_max < map->xyz[y][x])
		map->z_max = map->xyz[y][x];
	if (map->z_min > map->xyz[y][x])
		map->z_min = map->xyz[y][x];
	map->z_size = map->z_max - map->z_min;
}

void	trim_file_name(t_map *map, char *file_name_with_path)
{
	char	*tmp;

	map->map_name_with_path = ft_strdup(file_name_with_path);
	if ((ft_strrchr(file_name_with_path, '/')))
	{
		tmp = ft_strrchr(file_name_with_path, '/');
		tmp++;
		map->map_name = ft_strdup(tmp);
	}
	else
		map->map_name = ft_strdup(file_name_with_path);
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
	close(fd);
}
