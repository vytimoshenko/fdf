/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 17:53:21 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/21 00:44:33 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_global	global;

	global.map = init_map(argc, argv);
	global.status = init_status(global.map);
	global.mlx = init_mlx();
	draw(&global);
	loop(&global);
	exit(0);
}
