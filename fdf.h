/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 15:47:44 by mperseus          #+#    #+#             */
/*   Updated: 2020/01/13 03:45:44 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# define PROGRAM_NAME "fdf"

# define WIN_SIZE_X 2560
# define WIN_SIZE_Y 1400
# define IMG_SIZE_X 2190
# define IMG_SIZE_Y 1340
# define IMG_INDT_X 10
# define IMG_INDT_Y 10

# define INIT_SCALE_FACTOR		1
# define INIT_SCALE_FACTOR_Z	1
# define INIT_PERSPECTIVE_RATE	2000

# define TEXT_COLOR  	0xFFFFFF
# define BACK_COLOR  	0x000000

# define NO_COLOR		0x555555

# define SINGLE_COLOR_1 0x0D6CA0
# define SINGLE_COLOR_2 0x556B2F

# define BOTTOM_COLOR_1 0x0000FF
# define MIDDLE_COLOR_1 0x555555
# define TOP_COLOR_1	0xFF0000

# define BOTTOM_COLOR_2 0x556B2F
# define MIDDLE_COLOR_2 0x404040
# define TOP_COLOR_2	0xFFFFFF

# define MIDDLE_MOUSE_BUTTON	3
# define MOUSE_SCROLL_UP		4
# define MOUSE_SCROLL_DOWN		5

# define A						0
# define S						1
# define D						2
# define Z						6
# define X						7
# define C						8
# define W						13
# define R						15
# define P						35
# define RETURN					36
# define CHEVRON_LEFT			43
# define CHEVRON_RIGHT			47
# define SPACE					49
# define ESC					53
# define PLUS					69
# define MINUS					78
# define PAGE_UP				116
# define PAGE_DOWN				121
# define ARROW_LEFT				123
# define ARROW_RIGHT			124
# define ARROW_DOWN				125
# define ARROW_UP				126

# define PI 3.14159265

# include "./libft/libft.h"
# include "mlx.h"
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>

typedef	struct	s_point
{
	float	x;
	float	y;
	float	z;

	int		color;
}				t_point;

typedef struct	s_line
{
	t_point *start;
	t_point *end;
	t_point *current;

	int		x;
	int		y;
	int		dx;
	int		dy;
}				t_line;

typedef struct	s_map
{
	int		**xyz;
	int		**clr;

	char	*map_name;
	int		has_color;

	int		points;
	int		x_size;
	int		y_size;
	int		z_size;
	int		z_min;
	int		z_max;
}				t_map;

typedef struct	s_status
{
	float	sf;
	float	sf_init;
	float	sf_z;
	int		persp_rate;
	int		color_scheme;

	int		straight_projection;
	int		isometric_projection;
	int		perspective_projection;

	float	x_angle;
	float	y_angle;
	float	z_angle;

	int		x_shift;
	int		y_shift;

	float	sin_x;
	float	sin_y;
	float	sin_z;
	float	cos_x;
	float	cos_y;
	float	cos_z;

	int		x_mouse;
	int		y_mouse;
	int		x_move;
	int		y_move;
	int		middle_mouse_button;
}				t_status;

typedef struct	s_view
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*data;

	int		bits_per_pixel;
	int		size_line;
	int		endian;

	int		*z_buffer;
}				t_view;

typedef struct	s_global
{
	t_map		*map;
	t_status	*status;
	t_view		*view;
}				t_global;

int				main(int argc, char **argv);

t_map			*init_struct_map(void);
t_status		*init_struct_status(t_map *map);
t_view			*init_struct_view(void);
t_global		*init_struct_global(t_map *map, t_status *status, t_view *view);

void			check_map(t_map *map, char *file_name);
void			check_line(t_map *map, char *line);

void			read_map(t_map *map, char *file_name);
void			split_line(t_map *map, char *line, int y);
void			trim_file_name(t_map *map, char *file_name);
void			get_max_min_z(t_map *map, int x, int y);

void			save_map_line(t_map *map, char **split_line, int y);
void			separate_color(t_map *map, char **split_line, int x, int y);
int				atoi_color(char *str);
int				atoi_mod(const char *str);
void			check_color(char *color);

void			calc_scale(t_map *map, t_status *status);
void			reset_shift_and_scale(t_status *status);
void			full_reset(t_map *map, t_status *status);

void			clear_background(t_view *view);
void			init_z_buffer(t_view *view);
void			clean_z_buffer(t_view *view);

void			draw_image(t_global *global);
void			*create_verticals(void *global);
void			*create_horizontals(void *global);
void			create_ver_line(t_global *global, t_line *line, int x, int y);
void			create_hor_line(t_global *global, t_line *line, int x, int y);

t_line			*init_line(void);
t_point			*init_point(void);
void			get_sin_cos(t_status *status);
void			transform_line(t_status *status, t_line *line);
void			destroy_line(t_line *line);

void			x_rotate_line(t_status *status, t_line *line);
void			y_rotate_line(t_status *status, t_line *line);
void			z_rotate_line(t_status *status, t_line *line);
void			scale_line(t_status *status, t_line *line);
void			shift_line(t_status *status, t_line *line);

void			draw_line(t_global *global, t_line *line);
void			swap_line_ends(t_line *line);
void			draw_line_low(t_global *global, t_line *line);
void			draw_line_high(t_global *global, t_line *line);
void			draw_current_point(t_global *global, t_line *line,
				int x, int y);

double			get_grade(int start, int end, int current);
int				get_light(int start, int end, double grade);
int				get_gradient(t_line *line);
void			get_z_color(t_map *map, t_status *status, t_point *point);
void			get_point_color(t_global *global, t_point *point, int x, int y);

void			get_perspective(t_status *status, t_line *line);
int				need_trim_line(t_line *line);
void			put_pixel(t_view *view, t_line *line);

void			redraw(t_global *global);
void			run_mlx(t_global *global);

int				keyboard_key_press(int key, void *param);
int				mouse_key_press(int key, int x, int y, void *param);
int				mouse_key_release(int key, int x, int y, void *param);
int				mouse_move(int x, int y, void *param);
int				close_window(void *param);

void			get_cursor_position(t_status *status, int x, int y);
void			control_shift(t_status *status, int key);
void			control_mouse_shift(t_status *status, int x, int y);
void			control_rotation(t_status *status, int key);
void			control_scales(t_status *status, int key);

void			control_projections(t_status *status, int key);
void			straight_projections(t_status *status);
void			isometric_projections(t_status *status);
void			control_perspective(t_status *status, int key);

void			control_colors(t_map *map, t_status *status, int key);

void			put_info_to_window(t_map *map, t_status *status, t_view *view);
void			put_map_summary_1(t_map *map, t_view *view);
void			put_map_summary_2(t_map *map, t_view *view);
void			put_map_summary_3(t_map *map, t_view *view);

void			put_status_1(t_status *status, t_view *view);
void			put_status_2(t_status *status, t_view *view);
void			put_status_3(t_status *status, t_view *view);
void			put_status_4(t_status *status, t_view *view);
void			put_status_5(t_status *status, t_view *view);

void			put_mouse_position(t_status *status, t_view *view);
void			put_control_keys_1(t_view *view);
void			put_control_keys_2(t_view *view);

float			deg_to_rad(int degrees);
int				rad_to_deg(float radians);
#endif
