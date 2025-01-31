# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kralison <kralison@student.42antananarivo  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 09:04:34 by kralison          #+#    #+#              #
#    Updated: 2025/01/31 08:38:52 by kralison         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =				cub3D

CC =				gcc

CFLAGS =			-Wall -Werror -Wextra -Iincludes

SRCS_DIR =			srcs

MLX =				minilibx-linux/libmlx.a

MLX_DIR =			minilibx-linux

LIB =				-L${MLX_DIR} -lmlx -L${LIB_DIR} -lft -lXext -lX11 -lm

OBJS_DIR =			objs

LIB_DIR =			libft

LIBFT =				libft/libft.a

SRCS =				\
					${SRCS_DIR}/colors.c \
					${SRCS_DIR}/color_utils.c \
					${SRCS_DIR}/cub3d.c \
					${SRCS_DIR}/gameloop.c \
					${SRCS_DIR}/program_functions.c \

OBJS = 				${SRCS:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o}

all:				${NAME}

${NAME}:			${LIBFT} ${MLX} ${OBJS}
					${CC} ${CFLAGS} ${OBJS} ${LIB} -o $@

${LIBFT}:
					make -C ${LIB_DIR}

${MLX}:
					@make -C ${MLX_DIR}

${OBJS_DIR}/%.o:	${SRCS_DIR}/%.c
					@mkdir -p ${OBJS_DIR}
					${CC} ${CFLAGS} -c $< -o $@

clean:
					make -C ${LIB_DIR} clean
					rm -rf ${OBJS_DIR}

fclean:				clean
					make -C ${LIB_DIR} fclean
					rm -f ${NAME}

re:					fclean all

.PHONY:				all clean fclean re
