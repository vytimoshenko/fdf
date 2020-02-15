/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get_init_mlx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 00:26:57 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/16 00:27:00 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_background(t_mlx *mlx)
{
	int i;

	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		mlx->data[i] = BACK_COLOR;
}

void	init_z_buffer(t_mlx *mlx)
{
	if (!(mlx->z_buffer = (int *)malloc(sizeof(int)
	* IMG_SIZE_W * IMG_SIZE_H)))
		ft_put_errno(PROGRAM_NAME);
	clean_z_buffer(mlx);
}

void	clean_z_buffer(t_mlx *mlx)
{
	int i;

	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		mlx->z_buffer[i] = -2147483648;
}

void	clean_mlx(t_mlx *mlx)
{
	// int i;

	if (mlx)
	{
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx_destroy_window(mlx->mlx, mlx->win);
		// i = -1;
		// while (++i < IMG_SIZE_W * IMG_SIZE_H)
		// 	pthread_mutex_destroy(&mlx->mutex[i]);
		ft_memdel((void *)mlx->mutex);
		ft_memdel((void *)mlx->data);
	}
}
