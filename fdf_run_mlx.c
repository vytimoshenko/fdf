/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_run_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:25:01 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/10 03:42:11 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_background(t_view *view)
{
	int i;

	i = -1;
	while (++i < IMG_SIZE_X * IMG_SIZE_Y)
		view->data[i] = BACK_COLOR;
}

void	put_info_to_window(t_view *view)
{
	put_map_summary_1(view);
	put_map_summary_2(view);
	put_map_summary_3(view);
	put_status_1(view);
	put_status_2(view);
	put_status_3(view);
	put_status_4(view);
	put_status_5(view);
	put_control_keys_1(view);
	put_control_keys_2(view);
	put_mouse_position(view);
}

void	redraw(t_view *view)
{
	mlx_clear_window(view->mlx_ptr, view->win_ptr);
	clear_background(view);
	create_wireframe(view);
	put_info_to_window(view);
	mlx_put_image_to_window(view->mlx_ptr, view->win_ptr, view->img_ptr,
	IMG_INDT_X, IMG_INDT_Y);
}

void	run_mlx(t_view *view)
{
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
	mlx_hook(view->win_ptr, 2, 0, keyboard_key_press, (void*)view);
	mlx_hook(view->win_ptr, 4, 0, mouse_key_press, (void*)view);
	mlx_hook(view->win_ptr, 5, 0, mouse_key_release, (void*)view);
	mlx_hook(view->win_ptr, 6, 0, mouse_move, (void*)view);
	mlx_hook(view->win_ptr, 17, 0, close_window, (void*)view);
	full_reset(view);
	redraw(view);
	mlx_loop(view->mlx_ptr);
}
