# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/16 19:45:56 by hlorrine          #+#    #+#              #
#    Updated: 2020/02/17 20:16:25 by mperseus         ###   ########.fr        #
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
			fdf_get_init_mlx.c		\
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

MK_FT	=	make -C libft
CL_FT	=	make clean -C libft
FCL_FT	=	make fclean -C libft

MK_MLX	=	make -C mlx
CL_MLX	=	make clean -C mlx

ADD_ERR =	-Wall -Wextra -Werror

MK_DIR	=	@/bin/mkdir saves

ADD_OPT =	-Ofast

ADD_LIB =	-L ./libft	-l ft\
			-L ./mlx	-l mlx
			
ADD_FMW =	-lmlx -framework OpenGL -framework AppKit\
			-lpthread
			# -fopenmp

all:		$(NAME)

$(NAME):	$(OBJ)
			$(MK_FT)
			$(MK_MLX)
			gcc -o $(NAME) $(OBJ) $(ADD_ERR) $(ADD_OPT) $(ADD_LIB) $(ADD_FMW)
			$(MK_DIR)

%.o: %.c
			gcc -I $(HDR) $< -c -o $@ $(ADD_ERR) $(ADD_OPT)

clean:
			@/bin/rm -f $(OBJ)
			$(CL_FT)
			$(CL_MLX)
			@/bin/rm -rf saves

fclean: 	clean
			@/bin/rm -f $(NAME)
			$(FCL_FT)

re: 		fclean all

.PHONY: 	all clean fclean re