/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 17:53:21 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/10 03:32:36 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_view	*init_view(void)
{
	t_view *view;

	if (!(view = (t_view *)ft_memalloc(sizeof(t_view))))
		ft_put_errno(PROGRAM_NAME);
	return (view);
}

int		main(int argc, char **argv)
{
	t_view *view;

	if (argc != 2)
		ft_put_error("usage: fdf map_name.fdf");
	view = init_view();
	check_map(view, argv[1]);
	read_map(view, argv[1]);
	run_mlx(view);
	exit(0);
}
