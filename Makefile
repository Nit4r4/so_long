# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 22:30:27 by mreymond          #+#    #+#              #
#    Updated: 2022/02/22 15:30:56 by vferraro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/so_long.c \
	##src/so_long_utils.c \
	src/so_long_render.c \
	src/so_long_errors.c \
	src/so_long_directions.c \
	src/get_next_line.c \
	src/get_next_line_utils.c
CFLAGS = -Wall -Werror -Wextra -Imlx
MLXFLAGS = -L ${LBFT_PATH} -lft -L ${MLX_PATH} -lmlx -framework OpenGL -framework AppKit
CC = gcc
NAME = so_long
OBJS = ${SRCS:.c=.o}
MLX_PATH = ./mlx/
LBFT_PATH = ./libft/
AR = ar rc
RM = rm -f

all: ${NAME}

$(NAME):	$(OBJS)
		@$(MAKE) -C $(LBFT_PATH)
		@$(MAKE) -C $(MLX_PATH)
		$(CC) $(OBJS) $(CFLAGS) -I ${MLX_PATH} -I ${LBFT_PATH} -o $(NAME) $(MLXFLAGS)

%o:	%.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean: 
	${RM} ${OBJS}
	@$(MAKE) -C $(LBFT_PATH) clean
	@$(MAKE) -C $(MLX_PATH) clean

fclean: clean
	${RM} ${NAME}
	@$(MAKE) -C $(LBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re