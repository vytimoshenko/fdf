# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/16 19:45:56 by hlorrine          #+#    #+#              #
#    Updated: 2020/01/10 20:18:38 by mperseus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		fdf

HDR = 		fdf.h

SRC = 		fdf_main.c				\
			fdf_check_map.c			\
			fdf_read_map.c			\
			fdf_separate_data.c		\
			fdf_create_line_1.c		\
			fdf_create_line_2.c		\
			fdf_transform_line.c	\
			fdf_get_color.c 		\
			fdf_draw_line.c			\
			fdf_output.c			\
			fdf_run_mlx.c			\
			fdf_mlx_hooks.c 		\
			fdf_control_1.c 		\
			fdf_control_2.c 		\
			fdf_control_3.c 		\
			fdf_put_info_1.c		\
			fdf_put_info_2.c		\
			fdf_put_info_3.c		\
			fdf_other.c

OBJ = 		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C libft
			gcc -Ofast -o $(NAME) $(SRC) -L./libft -lft -L/usr/local/lib/ \
			-lmlx -framework OpenGL -framework AppKit -lpthread

%.o: %.c
			gcc -Ofast -I $(HDR) $< -c -o $@ 

clean:
			@/bin/rm -f $(OBJ)

fclean: 	clean
			@/bin/rm -f $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re