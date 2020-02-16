/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_control_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:34:41 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/16 20:51:11 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_mouse_position(t_status *status, int x, int y)
{
	status->x_mouse = x - IMG_INDT_W;
	status->y_mouse = y - IMG_INDT_H;
	if (x < IMG_INDT_W || x > IMG_INDT_W + IMG_SIZE_W ||
	y < IMG_INDT_H || y > IMG_INDT_H + IMG_SIZE_H)
	{
		status->x_mouse = 0;
		status->y_mouse = 0;
	}
}

void	control_shift(t_status *status, int key)
{
	if (key == A && status->x_shift >= -IMG_SIZE_W / 2)
		status->x_shift -= 0.1 * IMG_SIZE_W;
	else if (key == D && status->x_shift <= IMG_SIZE_W / 2)
		status->x_shift += 0.1 * IMG_SIZE_W;
	else if (key == W && status->y_shift >= -IMG_SIZE_H / 2)
		status->y_shift -= 0.1 * IMG_SIZE_W;
	else if (key == S && status->y_shift <= IMG_SIZE_H / 2)
		status->y_shift += 0.1 * IMG_SIZE_W;
}

void	control_mouse_shift(t_status *status, int x, int y)
{
	if (status->middle_mouse_button == 1)
	{
		status->x_move = status->x_shift - x;
		status->y_move = status->y_shift - y;
		status->middle_mouse_button = 2;
	}
	else if (status->middle_mouse_button == 2)
	{
		status->x_shift = status->x_move + x;
		status->y_shift = status->y_move + y;
	}
}

void	control_rotation(t_status *status, int key)
{
	if (key == ARROW_DOWN && rad_to_deg(status->x_angle) < 180)
		status->x_angle += deg_to_rad(5);
	else if (key == ARROW_UP && rad_to_deg(status->x_angle) > -180)
		status->x_angle -= deg_to_rad(5);
	else if (key == ARROW_RIGHT && rad_to_deg(status->y_angle) < 180)
		status->y_angle += deg_to_rad(5);
	else if (key == ARROW_LEFT && rad_to_deg(status->y_angle) > -180)
		status->y_angle -= deg_to_rad(5);
	else if (key == MORE && rad_to_deg(status->z_angle) < 180)
		status->z_angle += deg_to_rad(5);
	else if (key == LESS && rad_to_deg(status->z_angle) > -180)
		status->z_angle -= deg_to_rad(5);
}

void	save_status(t_status *status)
{
	int 	fd;
	char	*file_name;
	char	*tmp1;
	char	*tmp2;

	++status->save_num;
	tmp1 = ft_itoa(status->save_num);
	tmp2 = ft_strjoin("_", tmp1);
	free(tmp1);
	tmp1 = ft_strjoin(tmp2, ".fdf-save");
	free(tmp2);
	tmp2 = ft_strjoin(PROGRAM_NAME, tmp1);
	free(tmp1);
	file_name = ft_strjoin(SAVE_PATH, tmp2);
	free(tmp2);
	if (!(fd = open(file_name, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP
	| S_IWGRP | S_IROTH | S_IWOTH)))
		ft_put_errno(PROGRAM_NAME);
	free(file_name);
	write(fd, (void *)status, sizeof(*status));
    close(fd);
}
