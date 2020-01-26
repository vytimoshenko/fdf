# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/16 19:45:56 by hlorrine          #+#    #+#              #
#    Updated: 2020/01/26 20:19:50 by mperseus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	fdf

HDR		= 	fdf.h

SRC		= 	fdf_main.c				\
			fdf_check_map.c			\
			fdf_read_map_1.c		\
			fdf_read_map_2.c		\
			fdf_init_struct.c		\
			fdf_get_init_status.c	\
			fdf_get_init_view.c		\
			fdf_draw_image_1.c		\
			fdf_draw_image_2.c		\
			fdf_transform_line_1.c	\
			fdf_transform_line_2.c	\
			fdf_draw_line.c			\
			fdf_get_color.c 		\
			fdf_draw.c				\
			fdf_mlx_hooks.c 		\
			fdf_control_1.c 		\
			fdf_control_2.c 		\
			fdf_control_3.c 		\
			fdf_put_info_1.c		\
			fdf_put_info_2.c		\
			fdf_put_info_3.c		\
			fdf_other.c

OBJ		= 	$(SRC:.c=.o)

LIB		=	make -C libft

ADD_ERR =	-Wall -Wextra -Werror

ADD_OPT =	-Ofast

ADD_LIB =	-L./libft -lft\
			-L/usr/local/lib/
			
ADD_FMW =	-lmlx -framework OpenGL -framework AppKit\
			-lpthread

$(NAME):	$(OBJ)
			$(LIB)
			gcc -o $(NAME) $(OBJ) $(ADD_ERR) $(ADD_OPT) $(ADD_LIB) $(ADD_FMW)

%.o: %.c
			gcc -I $(HDR) $< -c -o $@ $(ADD_ERR) $(ADD_OPT)

clean:
			@/bin/rm -f $(OBJ)

fclean: 	clean
			@/bin/rm -f $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re