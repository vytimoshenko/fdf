/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_other.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 03:32:09 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/15 03:42:04 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	deg_to_rad(int degrees)
{
	return ((double)degrees * PI / 180.0);
}

int		rad_to_deg(double radians)
{
	return ((int)(round(radians * 180.0 / PI)));
}
