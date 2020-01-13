/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get_init_view.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 01:36:16 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/13 03:42:21 by mperseus         ###   ########.fr       */
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

void	init_z_buffer(t_view *view)
{
	if (!(view->z_buffer = (int *)malloc(sizeof(int)
	* IMG_SIZE_X * IMG_SIZE_Y)))
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
