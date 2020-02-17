/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transform_line_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 17:19:51 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/17 18:06:03 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_perspective(t_status *status, t_line *line)
{
	if (line->start->z < status->persp_rate &&
	line->end->z < status->persp_rate)
	{
		line->start->x *= status->persp_rate /
		(status->persp_rate - line->start->z);
		line->start->y *= status->persp_rate /
		(status->persp_rate - line->start->z);
		line->end->x *= status->persp_rate /
		(status->persp_rate - line->end->z);
		line->end->y *= status->persp_rate /
		(status->persp_rate - line->end->z);
	}
	else
	{
		line->start->x = IMG_SIZE_W + IMG_INDT_W;
		line->start->y = IMG_SIZE_H + IMG_INDT_H;
		line->end->x = IMG_SIZE_W + IMG_INDT_W;
		line->end->y = IMG_SIZE_H + IMG_INDT_H;
	}
}

int		need_trim_line(t_line *line)
{
	if ((line->start->x < IMG_INDT_W && line->end->x < IMG_INDT_W) ||
	(line->start->x > IMG_SIZE_W + IMG_INDT_W &&
	line->end->x > IMG_SIZE_W + IMG_INDT_W) ||
	(line->start->y < IMG_INDT_H && line->end->x < IMG_INDT_H) ||
	(line->start->y > IMG_SIZE_H + IMG_INDT_H &&
	line->end->y > IMG_SIZE_H + IMG_INDT_H))
		return (1);
	else
		return (0);
}

// pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void	put_pixel(t_mlx *mlx, t_line *line)
{
	if (line->current->x > IMG_INDT_W && line->current->x < IMG_SIZE_W
	&& line->current->y > IMG_INDT_W && line->current->y < IMG_SIZE_H)
	{
		// if (pthread_mutex_lock(&mlx->mutex[(int)(IMG_SIZE_W *
		// (line->current->y - 1) + line->current->x)]))
		// 	ft_put_error("fdf: pthread_mutex_lock error");
		// pthread_mutex_lock(&mutex);
		if (mlx->z_buffer[(int)(IMG_SIZE_W * (line->current->y - 1) +
		line->current->x)] < line->current->z)
		{
			mlx->data[(int)(IMG_SIZE_W * (line->current->y - 1) +
		line->current->x)] = line->current->color;
			mlx->z_buffer[((int)(IMG_SIZE_W * (line->current->y - 1) +
		line->current->x))] = line->current->z;
		}
		// pthread_mutex_unlock(&mutex);
		// if (pthread_mutex_unlock(&mlx->mutex[(int)(IMG_SIZE_W *
		// (line->current->y - 1) + line->current->x)]))
		// 	ft_put_error("fdf: pthread_mutex_lock error");
	}
}
