/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_control_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 03:23:22 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/13 02:09:52 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	control_colors(t_map *map, t_status *status, int key)
{
	if (status->color_scheme != 4)
		status->color_scheme++;
	else
		status->color_scheme = 0;
	if (status->color_scheme == 0 && map->has_color == 0)
		status->color_scheme++;
}
