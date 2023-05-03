# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaillea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/06 11:46:17 by acaillea          #+#    #+#              #
#    Updated: 2022/01/06 11:46:21 by acaillea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include ./Includes/colors.mk

NAME	= fractol

SRC_DIR = ./Sources/
SRC		=	colors.c \
			fractals.c \
			get_next_line.c \
			hook.c \
			init.c \
			main.c \
			utils.c \

INC		= ./Includes/fractol.h

OBJ_DIR	= ./Objects/
OBJ		= $(addprefix ${OBJ_DIR}, ${SRC:%.c=%.o})
OBJ_FIL	= object_file

CC		= gcc
MK		= mkdir -p
MMLX	= make -s -C 
CFLAGS	= -Wall -Werror -Wextra
MLX		= -L ./mlx/ -lmlx -framework OpenGL -framework AppKit -lz

RM		= /bin/rm -f
VEL		= sleep
PRI		= printf

${OBJ_DIR}%.o:${SRC_DIR}%.c
	@${CC} ${CFLAGS} -I ${INC} -Imlx -c $< -o $@
	@${PRI} "${C_MAG}	Compiling fracto'l :	\
	${C_CYAN}[${C_ORANGE}$<${C_CYAN}] $(C_RESET) $(L_CLEAR)\r"
	@${VEL} 0.5
	@printf "$(L_CLEAR)\r"

all : ${OBJ_FIL} ${NAME}

${OBJ_FIL} :
	@${MK} ${OBJ_DIR}

${NAME}: ${OBJ}
	@${MMLX} ./mlx
	@${CC} ${CFLAGS} ${MLX} ${OBJ} -o ${NAME}
	@${PRI} "\n${C_CYAN}[${C_GREEN}✔︎${C_CYAN}]	\
	${C_DEFAUT}$@ . . . ${C_GREEN}Successfully build\n\n"

clean :
	@${RM} -r ${OBJ_DIR}
	@${PRI} "\n${C_CYAN}[${C_GREEN}✔︎${C_CYAN}]	${C_RED}Files Deleted\n\n"

fclean : clean
	@${RM} ${NAME}
	@${PRI} "${C_CYAN}[${C_GREEN}✔︎${C_CYAN}]	${C_RED}Exe Deleted\n\n"

re : fclean all

.PHONY : all clean fclean re
