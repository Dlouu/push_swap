# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbaumgar <mbaumgar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/06 13:28:40 by mbaumgar          #+#    #+#              #
#    Updated: 2024/05/10 14:35:05 by mbaumgar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

LFT			= ./libft/libft.a
LIBFT		= ./libft
MAKE_LIBFT	= ${MAKE} --no-print-directory -C ${LIBFT}

# ╔═╗╦  ╔═╗╔═╗╔═╗
# ╠╣ ║  ╠═╣║ ╦╚═╗
# ╚  ╩═╝╩ ╩╚═╝╚═╝

CC					= cc
ARFLAGS 			= -crs
RM					= rm -rf
CFLAGS				= -Wall -Werror -Wextra
DEBUG				= -fsanitize=address -fsanitize=leak -g3

# ╔═╗╔═╗╦  ╔═╗╦═╗╔═╗
# ║  ║ ║║  ║ ║╠╦╝╚═╗
# ╚═╝╚═╝╩═╝╚═╝╩╚═╚═╝

YELLOW		= \033[1;33m# bold / yellow
RED			= \033[1;31m# bold / red
BACKGROUND	= \033[7;33m# background / yellow
BLINK		= \033[5;2;39m# blink / gray
END			= \033[m# remove style

# ╔═╗╔═╗╦ ╦╦═╗╔═╗╔═╗╔═╗
# ╚═╗║ ║║ ║╠╦╝║  ║╣ ╚═╗
# ╚═╝╚═╝╚═╝╩╚═╚═╝╚═╝╚═╝

SRC_DIR			= ./src/
OUT_DIR			= ./bin/
UTILS_DIR		= utils/
OP_DIR			= operations/

SRC				= main.c \
				parsing.c \
				sort.c	\
				${OP_DIR}push.c \
				${OP_DIR}swap.c \
				${OP_DIR}rotate.c \
				${OP_DIR}rrotate.c \
				${OP_DIR}loop_rotate.c \
				${UTILS_DIR}stack.c \
				${UTILS_DIR}target.c \
				${UTILS_DIR}lst.c

OBJ				= ${SRC:%.c=${OUT_DIR}%.o}

# ╦═╗╦ ╦╦  ╔═╗╔═╗
# ╠╦╝║ ║║  ║╣ ╚═╗
# ╩╚═╚═╝╩═╝╚═╝╚═╝

all: ${NAME}

${LFT}: 
	@${MAKE_LIBFT}
	@echo "📗 ${GREEN}libft.a${END} has been created\n"

${NAME}: ${LFT} ${OBJ}
	@${CC} ${CFLAGS} -o ${NAME} ${OBJ} ${LFT}
	@echo " ${YELLOW}push_swap${END} is ready !\n\n \
	${CYAN} Have fun ! ${END}    ${BLINK}Yeah!${END} ᕙ ( •̀ ᴗ •́ )ᕗ\n" 

${OUT_DIR}%.o: ${SRC_DIR}%.c
	@mkdir -p ${OUT_DIR}
	@mkdir -p ${OUT_DIR}${OP_DIR} ${OUT_DIR}${UTILS_DIR}
	@${CC} ${CFLAGS} -g3 -c $< -o $@

clean:
	@${MAKE_LIBFT} clean
	@${RM} ${OUT_DIR}
	@echo "🧹 ${RED}removed:${END} objects"

fclean: clean
	@${MAKE_LIBFT} fclean
	@echo "🧹 ${RED}removed:${END} libft archive"
	@${RM} ${NAME}
	@echo "🧹 ${RED}removed:${END} push_swap\n\
	 ${BACKGROUND} Everything has been DESTROYED!! ${END} ( •̀ ᴖ •́ )\n"

re: fclean all

uwu: re
	@${MAKE} --no-print-directory clean

norminette:
	norminette libft/src/*
	@echo "\n"
	norminette libft/inc/*
	@echo "\n"
	norminette inc/*
	@echo "\n"
	norminette src/*

sanitize: re
	${CC} ${CFLAGS} ${DEBUG} -o ${NAME} ${OBJ} ${LFT}

git: fclean
	cd ..
	git add .
	git commit -m "update from push_swap : ${m}"
	git push

.PHONY: all clean fclean re uwu norminette sanitize git
