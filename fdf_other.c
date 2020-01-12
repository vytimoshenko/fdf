/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_other.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 03:32:09 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/10 03:32:30 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	deg_to_rad(int degrees)
{
	return ((float)degrees * PI / 180.0);
}

int		rad_to_deg(float radians)
{
	return ((int)(round(radians * 180.0 / PI)));
}
