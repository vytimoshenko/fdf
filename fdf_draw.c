/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:25:01 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/26 20:07:15 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	redraw(t_global *global)
{
	mlx_clear_window(global->view->mlx_ptr, global->view->win_ptr);
	clear_background(global->view);
	draw_image(global);
	put_info_to_window(global->map, global->status, global->view);
	mlx_put_image_to_window(global->view->mlx_ptr, global->view->win_ptr,
	global->view->img_ptr, IMG_INDT_X, IMG_INDT_Y);
}

void	draw(t_global *global)
{
	mlx_hook(global->view->win_ptr, 2, 0, keyboard_key_press, (void *)global);
	mlx_hook(global->view->win_ptr, 4, 0, mouse_key_press, (void *)global);
	mlx_hook(global->view->win_ptr, 5, 0, mouse_key_release, (void *)global);
	mlx_hook(global->view->win_ptr, 6, 0, mouse_move, (void *)global);
	mlx_hook(global->view->win_ptr, 17, 0, close_window, (void *)global);
	redraw(global);
	mlx_loop(global->view->mlx_ptr);
}
