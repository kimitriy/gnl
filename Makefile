# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rburton <rburton@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/28 11:32:38 by rburton           #+#    #+#              #
#    Updated: 2021/01/03 15:01:45 by rburton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

SRC = gnl_main.c get_next_line_exam.c get_next_line_utils.c
#SRC = gnl_main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c

GCC = gcc -g -Wall -Werror -Wextra

RM = rm -f

#BUFFER_SIZE = BUFFER_SIZE=10

all: ${NAME}

#${GCC} -o ${NAME} ${SRC}
#${GCC} -o ${NAME} ${SRC} -D ${BUFFER_SIZE}
$(NAME):
	${GCC} -o ${NAME} ${SRC}
	#${GCC} -o ${NAME} ${SRC} -D ${BUFFER_SIZE}

clean:
	${RM} *.o

fclean: clean
	${RM} ${NAME}

re: fclean all
