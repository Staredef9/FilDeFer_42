# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 11:31:08 by fsalvett          #+#    #+#              #
#    Updated: 2023/02/02 10:28:40 by fsalvett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


####### NAME #########

NAME = libft.a
#BNUS = bonus

###### VARIABLE ######

SRCS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
       ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_bzero.c \
       ft_atoi.c ft_calloc.c ft_tolower.c ft_toupper.c ft_strdup.c \
       ft_strrchr.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strnstr.c \
       ft_itoa.c ft_strtrim.c ft_split.c ft_substr.c ft_strmapi.c ft_strncmp.c \
       ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
       ft_strjoin.c get_next_line.c ft_utils.c  ft_printf.c ft_split_count.c\
	   ft_cases_handlers.c ft_cases_handlers_2.c 
OBJS = ${SRCS:.c=.o}

#BNSRCS =# ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
	 ft_lstsize.c ft_lstlast.c ft_lstiter.c ft_lstmap.c
#BNOBJS = ${BNSRCS:.c=.o}

CC = gcc
AR = ar
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

######## EXT #########

# make a .o file using a .c file
# $< for the .c file
# $@ for the .o file

# .inextention.outextention:

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

####### RULES ########

all: ${NAME}

${NAME}: ${OBJS}
	@echo "===++== CREATE/UPDATE ARCHIVE ==++=="
	${AR} -rcs ${NAME} ${OBJS}
	@echo ""

#${BNUS}: ${BNOBJS}
	#@echo "===++== ADD BONUS IN ARCHIVE ==++==="
	#${AR} -rcs ${NAME} ${BNOBJS}
	#@echo ""

clean:
	@echo "====++=== CLEAN ALL OBJECTS ===++==="
	${RM} ${OBJS} 
	@echo ""

fclean: clean
	@echo "====++==== DELETE ARCHIVE ====++===="
	${RM} ${NAME}
	@echo ""
	@echo "====++==== ==++==++==++== ====++===="

re: fclean all

.PHONY: all clean fclean re .c.o
.SUFFIXES: .c .o 
