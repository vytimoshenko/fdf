/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_control_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 03:23:22 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/10 03:26:49 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	control_colors(t_view *view, int key)
{
	if (view->color_scheme != 4)
		view->color_scheme++;
	else
		view->color_scheme = 0;
	if (view->color_scheme == 0 && view->has_color == 0)
		view->color_scheme++;
}

void	reset_shift_and_scale(t_view *view)
{
	view->x_shift = 0;
	view->y_shift = 0;
	view->sf = view->sf_init;
}

void	full_reset(t_view *view)
{
	reset_shift_and_scale(view);
	view->sf_z = INIT_SCALE_FACTOR_Z;
	view->persp_rate = INIT_PERSPECTIVE_RATE;
	if (view->has_color == 1)
		view->color_scheme = 0;
	else
		view->color_scheme = 1;
	control_projections(view, RETURN);
	view->perspective_projection = 0;
}
