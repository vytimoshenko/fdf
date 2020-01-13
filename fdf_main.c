/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 17:53:21 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/13 02:00:28 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_map		*map;
	t_status	*status;
	t_view		*view;
	t_global	*global;

	if (argc != 2)
		ft_put_error("usage: fdf map_name.fdf");
	map = init_struct_map();
	check_map(map, argv[1]);
	read_map(map, argv[1]);
	status = init_struct_status(map);
	view = init_struct_view();
	global = init_struct_global(map, status, view);
	run_mlx(global);
	exit(0);
}
