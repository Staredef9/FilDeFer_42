# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/21 12:24:30 by fsalvett          #+#    #+#              #
#    Updated: 2023/04/18 11:06:07 by fsalvett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = fdf.c draw.c read_file.c

OBJS = ${SRCS:.c=.o}

CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -lX11 -lXext 

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

all: ${NAME} 

${NAME}: ${OBJS}
	make all -C minilibx
	mv ./minilibx/libmlx.a ./
	mv ./minilibx/libmlx_Linux.a ./
	make all -C Libft
	mv ./Libft/libft.a ./
	${CC} ${CFLAGS} ${OBJS} libft.a libmlx_Linux.a -o ${NAME}
	
clean: minilibx 
	${RM} ${OBJS} libmlx.a libmlx_Linux.a
fclean: clean
	${RM} ${NAME}
re: fclean all

minilibxclean: 
	cd minilibx && ${MAKE} clean

.PHONY: all clean fclean re .c.o. minilibx libmlx
.SUFFIXES: .c .o
