/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 01:34:38 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/26 20:04:19 by mperseus         ###   ########.fr       */
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

t_view		*init_view(void)
{
	t_view *view;

	if (!(view = (t_view *)ft_memalloc(sizeof(t_view))))
		ft_put_errno(PROGRAM_NAME);
	if (!(view->mlx_ptr = mlx_init()))
		ft_put_error("fdf: mlx_init error");
	if (!(view->win_ptr = (void *)mlx_new_window(view->mlx_ptr, WIN_SIZE_X,
	WIN_SIZE_Y, PROGRAM_NAME)))
		ft_put_error("fdf: mlx_new_window error");
	if (!(view->img_ptr = (void *)mlx_new_image(view->mlx_ptr, IMG_SIZE_X,
	IMG_SIZE_Y)))
		ft_put_error("fdf: mlx_new_image error");
	view->data = (int *)mlx_get_data_addr(view->img_ptr,
	&(view->bits_per_pixel), &(view->size_line), &(view->endian));
	clear_background(view);
	init_z_buffer(view);
	return (view);
}

t_global	*init_global(int argc, char **argv)
{
	t_global *global;

	if (!(global = (t_global *)ft_memalloc(sizeof(t_global))))
		ft_put_errno(PROGRAM_NAME);
	global->map = init_map(argc, argv);
	global->status = init_status(global->map);
	global->view = init_view();
	return (global);
}
	
