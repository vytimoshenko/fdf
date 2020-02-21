/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get_init_mlx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 00:26:57 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/21 02:51:10 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx		*init_mlx(void)
{
	t_mlx	*mlx;
	// int		i;

	if (!(mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx))))
		ft_put_errno(PROGRAM_NAME);
	if (!(mlx->mlx = mlx_init()))
		ft_put_error("fdf: mlx_init error");
	if (!(mlx->win = (void *)mlx_new_window(mlx->mlx, WIN_SIZE_W, WIN_SIZE_H,
	PROGRAM_NAME)))
		ft_put_error("fdf: mlx_new_window error");
	if (!(mlx->img = (void *)mlx_new_image(mlx->mlx, IMG_SIZE_W, IMG_SIZE_H)))
		ft_put_error("fdf: mlx_new_image error");
	mlx->data = (int *)mlx_get_data_addr(mlx->img, &(mlx->bits_per_pixel),
	&(mlx->size_line), &(mlx->endian));
	// if (!(mlx->mutex = (pthread_mutex_t *)ft_memalloc(sizeof(pthread_mutex_t)
	// * IMG_SIZE_W * IMG_SIZE_H)))
	// 	ft_put_errno(PROGRAM_NAME);
	// i = -1;
	// while (++i < IMG_SIZE_W * IMG_SIZE_H)
	// {
	// 	if (pthread_mutex_init(&mlx->mutex[i], NULL))
	// 		ft_put_error("fdf: pthread_mutex_init error");
	// }
	clear_background(mlx);
	init_z_buffer(mlx);
	return (mlx);
}

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
