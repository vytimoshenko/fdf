/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:25:01 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/15 20:06:24 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	loop(t_global *global)
{
	mlx_hook(global->mlx->win, 2, 0, keyboard_key_press, global);
	mlx_hook(global->mlx->win, 4, 0, mouse_key_press, global);
	mlx_hook(global->mlx->win, 5, 0, mouse_key_release, global);
	mlx_hook(global->mlx->win, 6, 0, mouse_move, global);
	mlx_hook(global->mlx->win, 17, 0, close_window, global);
	mlx_loop(global->mlx->mlx);
}

void	draw(t_global *global)
{
	struct timeval	start;
	struct timeval	end;

	gettimeofday(&start, NULL);
	mlx_clear_window(global->mlx->mlx, global->mlx->win);
	clear_background(global->mlx);
	draw_image(global);
	put_info_to_window(global);
	mlx_put_image_to_window(global->mlx->mlx, global->mlx->win,
	global->mlx->img, IMG_INDT_W, IMG_INDT_H);
	gettimeofday(&end, NULL);
	count_frames(global->mlx, start, end);
}

void	update_info_only(t_global *global)
{
	mlx_clear_window(global->mlx->mlx, global->mlx->win);
	mlx_put_image_to_window(global->mlx->mlx, global->mlx->win,
	global->mlx->img, IMG_INDT_W, IMG_INDT_H);
	put_info_to_window(global);
}

void	count_frames(t_mlx *mlx, struct timeval start, struct timeval end)
{
	++mlx->frames;
	mlx->frame_time = (double)(end.tv_usec - start.tv_usec) / 1000 +
	(double)(end.tv_sec - start.tv_sec) * 1000;
	mlx->fps = 1000 / mlx->frame_time;
}
