/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_put_info_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:37:57 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/15 20:12:08 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_status_1(t_status *status, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 340;
	pos_y = 380;
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 70, pos_y, TEXT_COLOR,
	"STATUS");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 30, TEXT_COLOR,
	"Shift:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 30, TEXT_COLOR,
	"X:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 150, pos_y + 30, TEXT_COLOR,
	str = ft_itoa(status->x_shift));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 50, TEXT_COLOR,
	"Y:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 150, pos_y + 50, TEXT_COLOR,
	str = ft_itoa(status->y_shift));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 80, TEXT_COLOR,
	"Rotation:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 80, TEXT_COLOR,
	"X:");
}

void	put_status_2(t_status *status, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 340;
	pos_y = 380;
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 150, pos_y + 80, TEXT_COLOR,
	str = ft_itoa(rad_to_deg(status->x_angle)));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 100, TEXT_COLOR,
	"Y:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 150, pos_y + 100, TEXT_COLOR,
	str = ft_itoa(rad_to_deg(status->y_angle)));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 120, TEXT_COLOR,
	"Z:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 150, pos_y + 120, TEXT_COLOR,
	str = ft_itoa(rad_to_deg(status->z_angle)));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 150, TEXT_COLOR,
	"Zoom:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 160, pos_y + 150, TEXT_COLOR,
	"%");
}

void	put_status_3(t_status *status, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 340;
	pos_y = 380;
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 150, TEXT_COLOR,
	str = ft_itoa(100 * (status->sf / status->sf_init)));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 170, TEXT_COLOR,
	"Z scale:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 160, pos_y + 170, TEXT_COLOR,
	"%");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 170, TEXT_COLOR,
	str = ft_itoa(100 * status->sf_z));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 200, TEXT_COLOR,
	"Perspective:");
	if (status->perspective_projection == 0)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 200, TEXT_COLOR,
		"off");
	else
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 200, TEXT_COLOR,
		"on");
}

void	put_status_4(t_status *status, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 340;
	pos_y = 380;
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 70, pos_y + 220, TEXT_COLOR,
	"rate:");
	if (status->perspective_projection == 1)
	{
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 220, TEXT_COLOR,
		"x");
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 140, pos_y + 220, TEXT_COLOR,
		str = ft_itoa((int)(1.0 /
		((float)(status->persp_rate) / 2000.0))));
		free(str);
	}
	else
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 220, TEXT_COLOR,
		"-");
}

void	put_status_5(t_status *status, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;

	pos_x = WIN_SIZE_W - 340;
	pos_y = 380;
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 240,
	TEXT_COLOR, "Color:");
	if (status->color_scheme == 0)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 240, TEXT_COLOR,
		"Map");
	else if (status->color_scheme == 1)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 240, TEXT_COLOR,
		"Gradient #1");
	else if (status->color_scheme == 2)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 240, TEXT_COLOR,
		"Gradient #2");
	else if (status->color_scheme == 3)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 240, TEXT_COLOR,
		"Mono Cyan");
	else
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 240, TEXT_COLOR,
		"Mono Green");
}
