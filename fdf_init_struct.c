/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 01:34:38 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/15 02:19:30 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map		*init_map(int argc, char **argv)
{
	t_map *map;

	if (argc != 2)
		ft_put_error("usage: fdf map_name.fdf");
	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		ft_put_errno(PROGRAM_NAME);
	check_map(map, argv[1]);
	read_map(map, argv[1]);
	return (map);
}

t_status	*init_status(t_map *map)
{
	t_status *status;

	if (!(status = (t_status *)ft_memalloc(sizeof(t_status))))
		ft_put_errno(PROGRAM_NAME);
	calc_scale(map, status);
	full_reset(map, status);
	return (status);
}

t_mlx		*init_mlx(void)
{
	t_mlx *mlx;

	if (!(mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx))))
		ft_put_errno(PROGRAM_NAME);
	if (!(mlx->mlx = mlx_init()))
		ft_put_error("fdf: mlx_init error");
	if (!(mlx->win = (void *)mlx_new_window(mlx->mlx, WIN_SIZE_W, WIN_SIZE_H,
	PROGRAM_NAME)))
		ft_put_error("fdf: mlx_new_window error");
	if (!(mlx->img = (void *)mlx_new_image(mlx->mlx, IMG_SIZE_W, IMG_SIZE_H)))
		ft_put_error("fdf: mlx_new_image error");
	mlx->data = (int *)mlx_get_data_addr(mlx->img, &(mlx->bits_per_pixel),
	&(mlx->size_line), &(mlx->endian));
	clear_background(mlx);
	init_z_buffer(mlx);
	return (mlx);
}

t_global	*init_global(int argc, char **argv)
{
	t_global *global;

	if (!(global = (t_global *)ft_memalloc(sizeof(t_global))))
		ft_put_errno(PROGRAM_NAME);
	global->map = init_map(argc, argv);
	global->status = init_status(global->map);
	global->mlx = init_mlx();
	return (global);
}
	
