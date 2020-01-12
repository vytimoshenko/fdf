/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 17:19:51 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/10 20:14:47 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_perspective(t_view *view, t_line *line)
{
	if (line->start->z < view->persp_rate && line->end->z < view->persp_rate)
	{
		line->start->x *= view->persp_rate /
		(view->persp_rate - line->start->z);
		line->start->y *= view->persp_rate /
		(view->persp_rate - line->start->z);
		line->end->x *= view->persp_rate / (view->persp_rate - line->end->z);
		line->end->y *= view->persp_rate / (view->persp_rate - line->end->z);
	}
	else
	{
		line->start->x = IMG_SIZE_X + IMG_INDT_X;
		line->start->y = IMG_SIZE_Y + IMG_INDT_Y;
		line->end->x = IMG_SIZE_X + IMG_INDT_X;
		line->end->y = IMG_SIZE_Y + IMG_INDT_Y;
	}
}

int		need_trim_line(t_view *view, t_line *line)
{
	if ((line->start->x < IMG_INDT_X && line->end->x < IMG_INDT_X) ||
	(line->start->x > IMG_SIZE_X + IMG_INDT_X &&
	line->end->x > IMG_SIZE_X + IMG_INDT_X) ||
	(line->start->y < IMG_INDT_Y && line->end->x < IMG_INDT_Y) ||
	(line->start->y > IMG_SIZE_Y + IMG_INDT_Y &&
	line->end->y > IMG_SIZE_Y + IMG_INDT_Y))
		return (1);
	else
		return (0);
}

void	init_z_buffer(t_view *view)
{
	if (!(view->z_buffer = (int *)malloc(sizeof(int) *
	IMG_SIZE_X * IMG_SIZE_Y)))
		ft_put_errno(PROGRAM_NAME);
	clean_z_buffer(view);
}

void	clean_z_buffer(t_view *view)
{
	int i;

	i = -1;
	while (++i < IMG_SIZE_X * IMG_SIZE_Y)
		view->z_buffer[i] = -2147483648;
}

void	put_pixel(t_view *view, t_line *line)
{
	if (line->current->x > IMG_INDT_X && line->current->x < IMG_SIZE_X
	&& line->current->y > IMG_INDT_Y && line->current->y < IMG_SIZE_Y)
	{
		if (view->z_buffer[(int)(IMG_SIZE_X * (line->current->y - 1) +
		line->current->x)] < line->current->z)
		{
			view->data[(int)(IMG_SIZE_X * (line->current->y - 1) +
		line->current->x)] = line->current->color;
			view->z_buffer[(int)(IMG_SIZE_X * (line->current->y - 1) +
		line->current->x)] = line->current->z;
		}
	}
}
