/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get_init_status.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 01:44:45 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/15 04:15:45 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calc_scale(t_map *map, t_status *status)
{
	float sf;

	sf = (IMG_SIZE_W - 10) / (1.2 * (map->x_size - 1));
	if (sf > (IMG_SIZE_H - 10) / (1.2 * (map->y_size - 1)))
		sf = (IMG_SIZE_H - 10) / (1.2 * (map->y_size - 1));
	status->sf = sf;
	status->sf_init = sf;
	status->sf_z_init = 1;
	if (map->z_size > 300)
		status->sf_z_init = 0.1;
	if (map->z_size > 1000)
		status->sf_z_init = 0.01;

}

void	reset_shift_and_scale(t_status *status)
{
	status->x_shift = 0;
	status->y_shift = 0;
	status->sf = status->sf_init;
}

void	full_reset(t_map *map, t_status *status)
{
	reset_shift_and_scale(status);
	status->sf_z = status->sf_z_init;
	status->persp_rate = INIT_PERSPECTIVE_RATE;
	if (map->has_color == 1)
		status->color_scheme = 0;
	else
		status->color_scheme = 1;
	status->isometric_projection = 0;
	status->perspective_projection = 0;
	isometric_projections(status);
}
