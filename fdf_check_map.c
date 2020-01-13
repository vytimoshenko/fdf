/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_check_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:00:47 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/13 03:31:07 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_line(t_map *map, char *line)
{
	if (map->y_size == 0)
		map->x_size = ft_wrdcnt(line, ' ');
	if (map->x_size == 1)
		ft_put_error("fdf: map x size must be > 1");
	if (map->x_size != ft_wrdcnt(line, ' '))
		ft_put_error("fdf: map must be recatngular");
}

void	check_map(t_map *map, char *file_name)
{
	int		fd;
	int		ret;
	char	*line;

	ret = 1;
	fd = open(file_name, O_RDONLY);
	if (fd < 0 || read(fd, NULL, 0) == -1)
		ft_put_errno(PROGRAM_NAME);
	while ((ret = get_next_line(fd, &line)) >= 0)
	{
		if (ret == -1)
			ft_put_errno(PROGRAM_NAME);
		if (ret == 0 && map->y_size == 0)
			ft_put_error("fdf: map file is empty");
		if (ret == 0)
			break ;
		check_line(map, line);
		ft_memdel((void *)&line);
		map->y_size++;
	}
	ft_memdel((void *)&line);
	if (map->y_size == 1)
		ft_put_error("fdf: map y size must be > 1");
	close(fd);
}
